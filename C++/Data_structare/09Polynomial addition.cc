#include<bits/stdc++.h>
typedef int ElemType;
using namespace std;
typedef struct LinkNode
{
    ElemType data;//系数
    ElemType power;//次数,指数
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
    	if(p->data!=0)//只输出非零项
    	{
        	cout << p->data 
				 << "X^" 
				 << p->power;
        	if(p->next!=NULL&&p->next->data>0)cout<<"+";//最后一项不加+
    	}
        p = p->next;
    }
    cout << endl;
}

void ReverseDisPlayLinkList(LinkNode *L)//逆序输出
{
    LinkNode *p=L->next;
    ElemType St[LinkListLength(L)][2];//定义栈
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
    
    while(p!=NULL)//合并多项式a中的同类项 
    {
    	pa=p;
    	pre=p->next;
    	while(pre!=NULL)
    	{
    		flag=false;//默认不存在同类项
    		if(pre->power==p->power)
    		{
    			flag=true;
    			p->data=p->data+pre->data;//合并同类项
    			pa->next=pre->next;
    			free(pre);
			}
			if(flag)pre=pa->next;//合并一项时pa不动
			else 
			{
				pa=pa->next;
				pre=pa->next;
			}
		}
    	p=p->next;
	}
	while(q!=NULL)//合并多项式b中的同类项 
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
	
	p=a->next;q=b->next;//复位
	L=(LinkNode *)malloc(sizeof(LinkNode));r=L;
	while(q!=NULL)
	{
		p=a->next;
		while(p!=NULL)
		{
			if(q->power==p->power)//在两个多项式中寻找并且合并同类项
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
		if(flag)//如果该项次数对于另外一个多项式是独一无二的,直接加上
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
	if(p!=NULL)//插入一个节点作为有序表
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
		while(q!=NULL && p->power<q->power){q=q->next;r=r->next;}//找位置
		
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
	#ifdef _WIN32//识别Windows平台
	system("cls");//清屏
	//system("color 0A");//字体颜色
	#endif
	LinkNode *A,*B,*sum;
    int key=4;

	printf("多项式 1 有几项?\n");
	scanf("%d",&key);
	int a[key][2]={{5,3},{2,2},{3,2},{-1,9}};
	printf("依次输入每一项的系数和次数: \n");
	for(int i=0;i<key;i++)
		for(int j=0;j<=1;j++)
			scanf("%d",&a[i][j]);
	CreateLinkListF(A,a,key);
	
	key=6;
	printf("多项式 2 有几项?\n");
	scanf("%d",&key);
	int b[key][2]={{9,2},{-2,1},{4,2},{3,8},{-5,4},{7,10}};
	printf("依次输入每一项的系数和次数: \n");
	for(int i=0;i<key;i++)
		for(int j=0;j<=1;j++)
			scanf("%d",&b[i][j]);
	CreateLinkListF(B,b,key);
	//system("cls");
	
	cout<<"\n多项式1: ";DisPlayLinkList(A);
	cout<<"多项式2: ";DisPlayLinkList(B);
    sum=Sum(A,B);
    
    cout<<"\n化简后的多项式1: ";DisPlayLinkList(A);
	cout<<"        多项式2: ";DisPlayLinkList(B);
	cout<<"\n\n      多项式和: ";DisPlayLinkList(sum);
	
	sum=InsertSort(sum);
	cout<<"降幂排序后的和: ";
	DisPlayLinkList(sum);
	cout<<"升幂排序后的和: ";
	ReverseDisPlayLinkList(sum);
    system("pause");
	return 0;
}
