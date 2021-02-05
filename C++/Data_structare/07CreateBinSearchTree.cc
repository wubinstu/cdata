#include<bits/stdc++.h>
using namespace std;

#define MaxSize 50
typedef int KeyType;
typedef char InfoType;
typedef int ElemType;

typedef struct RecType
{
    KeyType key;
    InfoType data;
}RecType;

typedef struct Tree
{
	ElemType data;
	int floor;
	struct Tree *lchild;
	struct Tree *rchild;
}BTNode;

void CreateBinSearchBTree(RecType R[],int low,int high,int child,BTNode *&b)
{
	BTNode *r=b,*s;
	int mid=(low+high)/2;
	if(low<=mid && mid<=high)
	{
		s=(BTNode *)malloc(sizeof(BTNode));
		s->data=R[mid].key;
		s->lchild=s->rchild=NULL;
		if(child==-1)
			r->lchild=s;
		if(child==1)
			r->rchild=s;
		if(child==0)
			b=s;
		r=s;
		CreateBinSearchBTree(R,low,mid-1,-1,r);
		CreateBinSearchBTree(R,mid+1,high,1,r);
	}
}



int BTreeHeight(BTNode *b)
{
	short int lchild,rchild;
	if(b==NULL)return 0;
	else
	{
		lchild=BTreeHeight(b->lchild);
        rchild=BTreeHeight(b->rchild);
        return ((lchild>rchild)?(lchild+1):(rchild+1));
	}
}

void DisplayBTree(BTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->data;
        if(b->lchild!=NULL || b->rchild!=NULL)
        {
            cout<<"(";
            DisplayBTree(b->lchild);
            if(b->rchild!=NULL)cout<<",";
            DisplayBTree(b->rchild);
            cout<<")";
        }
    }
}

int BinSearch(RecType R[],int n,KeyType k)	
{
	int low=0,high=n-1,mid;
	while (low<=high) 
	{	
		mid=(low+high)/2;
		if (R[mid].key==k)   	
			return mid+1;
		if (R[mid].key>k)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

void CreateRecType(RecType R[],KeyType k[],int n)
{
    for(int i=0;i<n;i++)
        R[i].key=k[i];
    return ;
}

void DisplayRecType(RecType R[],int n)
{
    for(int i=0;i<n;i++)
        cout<<R[i].key<<" ";
    cout<<endl;
}

int main()
{
	system("cls");
    RecType R[10];
    KeyType k[10]={0,1,2,3,4,5,6,7,8,9};
    CreateRecType(R,k,10);
    DisplayRecType(R,10);
    cout<<"元素1的位置在: "<<BinSearch(R,10,1)<<endl;
    BTNode *b;
    CreateBinSearchBTree(R,0,9,0,b);
    DisplayBTree(b);
	cout<<endl;
    //system("pause");
    return 0;
}
