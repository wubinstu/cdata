#include <stdio.h>
#include <malloc.h>
//ͼ�����ִ洢�ṹ
#define INF 32767				//�����
#define	MAXV 100				//��󶥵����
typedef char InfoType;

//���¶����ڽӾ�������
typedef struct
{	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct
{	int edges[MAXV][MAXV];		//�ڽӾ�������
	int n,e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MatGraph;						//������ͼ�ڽӾ�������

//���¶����ڽӱ�����
typedef struct ANode
{	int adjvex;					//�ñߵ��ڽӵ���
	struct ANode *nextarc;		//ָ����һ���ߵ�ָ��
	int weight;					//�ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;						//�߽ڵ�����
typedef struct Vnode
{	InfoType info;				//����������Ϣ
	int count;					//��Ŷ������,����������������
	ArcNode *firstarc;			//ָ���һ����
} VNode;						//�ڽӱ�ͷ�ڵ�����
typedef struct 
{	VNode adjlist[MAXV];		//�ڽӱ�ͷ�ڵ�����
	int n,e;					//ͼ�ж�����n�ͱ���e
} AdjGraph;						//������ͼ�ڽӱ�����

//------------------------------------------------------------
//----�ڽӾ���Ļ��������㷨----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph &g,int A[MAXV][MAXV],int n,int e) //����ͼ���ڽӾ���
{
	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
}
void DispMat(MatGraph g)	//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]!=INF)
				printf("%4d",g.edges[i][j]);
			else
				printf("%4s","��");
		printf("\n");
	}
}
//------------------------------------------------------------

//------------------------------------------------------------
//----�ڽӱ�Ļ��������㷨------------------------------------
//------------------------------------------------------------
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e) //����ͼ���ڽӱ�
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<n;i++)						//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)						//����ڽӾ�����ÿ��Ԫ��
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)	//����һ����
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�p
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;	//����ͷ�巨����ڵ�p
				G->adjlist[i].firstarc=p;
			}
	G->n=n; G->e=e;
}
void DispAdj(AdjGraph *G)	//����ڽӱ�G
{
	ArcNode *p;
	for (int i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d[%d]��",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("��\n");
	}
}
void DestroyAdj(AdjGraph *&G)	//����ͼ���ڽӱ�
{
	ArcNode *pre,*p;
	for (int i=0;i<G->n;i++)		//ɨ�����еĵ�����
	{	pre=G->adjlist[i].firstarc;	//pָ���i����������׽ڵ�
		if (pre!=NULL)
		{	p=pre->nextarc;
			while (p!=NULL)			//�ͷŵ�i������������б߽ڵ�
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//�ͷ�ͷ�ڵ�����
}

int visited[MAXV];						//ȫ������
void DFS(AdjGraph *G,int v)				//�ݹ�������ȱ����㷨
{
	ArcNode *p;
	visited[v]=1;                   	//���ѷ��ʱ��
	printf("%3d",v); 					//��������ʶ���ı��
	p=G->adjlist[v].firstarc;      		//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL) 
	{	
		if (visited[p->adjvex]==0)		//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);    
		p=p->nextarc;              		//pָ�򶥵�v����һ�����Ļ�ͷ���
	}
}

void BFS(AdjGraph *G,int v)					//������ȱ����㷨		
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;			//���廷�ζ��в���ʼ��
	int visited[MAXV];            			//�����Ŷ���ķ��ʱ�־������
	int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;		//���ʱ�־�����ʼ��
	printf("%3d",v); 						//��������ʶ���ı��
	visited[v]=1;              				//���ѷ��ʱ��
	rear=(rear+1)%MAXV;
	queue[rear]=v;             				//v����
	while (front!=rear)       				//�����в���ʱѭ��
	{	
		front=(front+1)%MAXV;
		w=queue[front];       				//���Ӳ�����w
		p=G->adjlist[w].firstarc; 			//�Ҷ���w�ĵ�һ�����ڵ�
		while (p!=NULL) 
		{	
			if (visited[p->adjvex]==0) 		//�����ڵ�δ������
			{	
				printf("%3d",p->adjvex);  	//�������ڵ�
				visited[p->adjvex]=1;		//�øö����ѱ����ʵı�־
				rear=(rear+1)%MAXV;			//�ö������
				queue[rear]=p->adjvex; 		
           	}
           	p=p->nextarc;              		//����һ�����ڵ�
		}
	}
	printf("\n");
}



void TopSort(AdjGraph *G)
{
	int i,j;
	int St[MAXV],top=-1;  			//ջSt��ָ��Ϊtop
	ArcNode *p;
	for (i=0;i<G->n;i++)			//����ó�ֵ0
		G->adjlist[i].count=0;
	for (i=0;i<G->n;i++)			//�����ж�������
	{
		p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{
			G->adjlist[p->adjvex].count++;
			p=p->nextarc;
		}
	}
	for (i=0;i<G->n;i++)
		if (G->adjlist[i].count==0)  //���Ϊ0�Ķ����ջ
		{
			top++; 
			St[top]=i;  
		}
	while (top>-1)             		//ջ��Ϊ��ʱѭ��
	{
		i=St[top];top--;  			//��ջ
		printf("%d ",i);      		//�������
		p=G->adjlist[i].firstarc;	//�ҵ�һ�����ڶ���
		while (p!=NULL) 
		{
			j=p->adjvex;
			G->adjlist[j].count--; 
			if (G->adjlist[j].count==0)//���Ϊ0�����ڶ����ջ
			{
				top++;
				St[top]=j;
			}
			p=p->nextarc;       //����һ�����ڶ���
		}
	}
}



//------------------------------------------------------------
int main()
{
	MatGraph g;
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0}};
	int n=6,e=10;			//ͼ8.1�е�����
	CreateMat(g,A,n,e);
	printf("(1)ͼG���ڽӾ���:\n");	DispMat(g);
	CreateAdj(G,A,n,e);
	printf("(2)ͼG���ڽӱ�:\n"); DispAdj(G);
	printf("(3)����ͼG���ڽӱ�\n");
	printf("(4)�������: ");DFS(G,0);
	printf("\n(5)�������: ");BFS(G,0);
	DestroyAdj(G);
	return 1;
}
