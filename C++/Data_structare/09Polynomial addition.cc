#include<bits/stdc++.h>
typedef int ElemType;
using namespace std;
typedef struct LinkNode
{
    ElemType data;//ϵ��
    ElemType power;//����,ָ��
    struct LinkNode *next;
} LinkNode;

void CreateLinkListF(LinkNode *&L, ElemType a[][2], int n)
{
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i][0];
        s->power = a[i][1];
        s->next = L->next;
        L->next = s;
    }
}

void DestroyLinkList(LinkNode *&L)
{
    LinkNode *pre = L, *p = L->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

int LinkListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

void DisPlayLinkList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
    	if(p->data!=0)//ֻ���������
    	{
        	cout << p->data 
				 << "X^" 
				 << p->power;
        	if(p->next!=NULL&&p->next->data>0)cout<<"+";//���һ���+
    	}
        p = p->next;
    }
    cout << endl;
}

void ReverseDisPlayLinkList(LinkNode *L)//�������
{
    LinkNode *p=L->next;
    ElemType St[LinkListLength(L)][2];//����ջ
	int top=-1;
	bool flag=false;
    while(p!=NULL)
    {
    	top++;
        St[top][0]=p->data;
        St[top][1]=p->power;
        p=p->next;
    }
    while(top!=-1)
    {
		if(St[top][0]!=0)
		{
			if(flag)
				if(St[top][0]>0)cout<<"+";
			flag=false;
    		cout<<St[top][0]
				<<"X^"
				<<St[top][1];
    		if(top!=0 && St[top-1][0]>0)cout<<"+";
			if(St[top-1][0]==0)flag=true;
		}
    	top--;
	}
    cout<<endl;
}

LinkNode *Sum(LinkNode *&a,LinkNode *&b)
{
    LinkNode *p=a->next,*q=b->next,*L,*r,*s;
    LinkNode *pa,*pb,*pre;
    bool flag=false;
    
    while(p!=NULL)//�ϲ�����ʽa�е�ͬ���� 
    {
    	pa=p;
    	pre=p->next;
    	while(pre!=NULL)
    	{
    		flag=false;//Ĭ�ϲ�����ͬ����
    		if(pre->power==p->power)
    		{
    			flag=true;
    			p->data=p->data+pre->data;//�ϲ�ͬ����
    			pa->next=pre->next;
    			free(pre);
			}
			if(flag)pre=pa->next;//�ϲ�һ��ʱpa����
			else 
			{
				pa=pa->next;
				pre=pa->next;
			}
		}
    	p=p->next;
	}
	while(q!=NULL)//�ϲ�����ʽb�е�ͬ���� 
    {
    	pb=q;
    	pre=q->next;
    	while(pre!=NULL)
    	{
    		flag=false;
    		if(pre->power==q->power)
    		{
    			flag=true;
    			q->data=q->data+pre->data;
    			pb->next=pre->next;
    			free(pre);
			}
			if(flag)pre=pb->next;
			else 
			{
				pb=pb->next;
				pre=pb->next;
			}
		}
    	q=q->next;
	}
	
	p=a->next;q=b->next;//��λ
	L=(LinkNode *)malloc(sizeof(LinkNode));r=L;
	while(q!=NULL)
	{
		p=a->next;
		while(p!=NULL)
		{
			if(q->power==p->power)//����������ʽ��Ѱ�Ҳ��Һϲ�ͬ����
			{
				s=(LinkNode *)malloc(sizeof(LinkNode));
				s->power=p->power;
				s->data=p->data+q->data;
				r->next=s;r=s;
			}
			p=p->next;
		}
		
		q=q->next;
	}
	p=a->next;q=b->next;
	while(q!=NULL)
	{
		flag=true;
		p=a->next;
		while(p!=NULL)
		{
			if(q->power==p->power)
				flag=false;
			p=p->next;
		}
		if(flag)//������������������һ������ʽ�Ƕ�һ�޶���,ֱ�Ӽ���
		{
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->power=q->power;
			s->data=q->data;
			r->next=s;r=s;
		}
		q=q->next;
	}
	p=a->next;q=b->next;
	while(p!=NULL)
	{
		flag=true;
		q=b->next;
		while(q!=NULL)
		{
			if(q->power==p->power)
				flag=false;
			q=q->next;
		}
		if(flag)
		{
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->power=p->power;
			s->data=p->data;
			r->next=s;r=s;
		}
		p=p->next;
	}
	r->next=NULL;
    return L;
}

LinkNode *InsertSort(LinkNode *&L) 
{
	LinkNode *c,*p=L->next;
	LinkNode *r,*s,*q;
	c=(LinkNode *)malloc(sizeof(LinkNode));r=c;
	if(p!=NULL)//����һ���ڵ���Ϊ�����
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=p->data;
		s->power=p->power;
		s->next=NULL;
		r->next=s;r=s;
		p=p->next;
	}
	while(p!=NULL)
	{
		q=c->next;
		r=c;
		while(q!=NULL && p->power<q->power){q=q->next;r=r->next;}//��λ��
		
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=p->data;
		s->power=p->power;
		s->next=r->next;
		r->next=s;
		
		p=p->next;
	}
	return c;
}

int main()
{
	#ifdef _WIN32//ʶ��Windowsƽ̨
	system("cls");//����
	//system("color 0A");//������ɫ
	#endif
	LinkNode *A,*B,*sum;
    int key=4;

	printf("����ʽ 1 �м���?\n");
	scanf("%d",&key);
	int a[key][2]={{5,3},{2,2},{3,2},{-1,9}};
	printf("��������ÿһ���ϵ���ʹ���: \n");
	for(int i=0;i<key;i++)
		for(int j=0;j<=1;j++)
			scanf("%d",&a[i][j]);
	CreateLinkListF(A,a,key);
	
	key=6;
	printf("����ʽ 2 �м���?\n");
	scanf("%d",&key);
	int b[key][2]={{9,2},{-2,1},{4,2},{3,8},{-5,4},{7,10}};
	printf("��������ÿһ���ϵ���ʹ���: \n");
	for(int i=0;i<key;i++)
		for(int j=0;j<=1;j++)
			scanf("%d",&b[i][j]);
	CreateLinkListF(B,b,key);
	//system("cls");
	
	cout<<"\n����ʽ1: ";DisPlayLinkList(A);
	cout<<"����ʽ2: ";DisPlayLinkList(B);
    sum=Sum(A,B);
    
    cout<<"\n�����Ķ���ʽ1: ";DisPlayLinkList(A);
	cout<<"        ����ʽ2: ";DisPlayLinkList(B);
	cout<<"\n\n      ����ʽ��: ";DisPlayLinkList(sum);
	
	sum=InsertSort(sum);
	cout<<"���������ĺ�: ";
	DisPlayLinkList(sum);
	cout<<"���������ĺ�: ";
	ReverseDisPlayLinkList(sum);
    system("pause");
	return 0;
}
