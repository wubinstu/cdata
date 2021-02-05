#include "data.h"      //Include Self Head File 

int main()
{
    #ifdef _WIN32
    //progressbar(120,90);
    //win_size(80,30);
    SetColor(3,0);
    system("cls");
    #endif
    //system("clear");
    //char wz[]="LoveWWB";
    //love_graphical(wz);

    cout<<"----------SqList---------\n";
    SqList *L;
        InitSqList(L);
    cout<<"<01> Insert a,b,c,d: ";
        SqListInsert(L,1,'a');
        SqListInsert(L,2,'b');
        SqListInsert(L,3,'c');
        SqListInsert(L,4,'d');
    cout<<"\n<02> DisPlay SqList: ";
        DisplaySqList(L);
    printf("<03> The Length Is: %d",SqListLength(L));
    printf("\n<04> The List Is %s",(SqListEmpty(L)?"Empty":"Not Empty"));
    ElemType aa;
        GetSqListElem(L,3,aa);
    cout<<"\n<05> The Third Elem Is: "<<aa;
    printf("\n<06> The Location Of 'a' Is At: NO.%d",LocateSqListElem(L,'a'));
    cout<<"\n<07> Tnsert 'f' In The Fourth Place";
        SqListInsert(L,4,'f');
    cout<<"\n<08> DisPlayer SqList: ";
        DisplaySqList(L);
    cout<<"<09> Delete The Third Elem";
        SqListDelete(L,3,aa);
    cout<<"\n<10> DisPlay SqList: ";
        DisplaySqList(L);
    cout<<"<11> Destroy The SqList";
        DestroySqList(L);


	#ifdef _WIN32
	SetColor(2,0);
	#endif

    cout<<"\n\n\n----------SingleLinkList---------"<<endl;
    cout<<"<01> Init LinkList"<<endl;
    LinkNode *h;
    //InitLinkList(h);
    cout<<"<02> Insert a,b,c,d,e"<<endl;
    /*LinkListInsert(h,1,'a');
    LinkListInsert(h,2,'b');
    LinkListInsert(h,3,'c');
    LinkListInsert(h,4,'d');
    LinkListInsert(h,5,'e');*/
    char a[]="abcde";
    CreateLinkListR(h,a,5);
    cout<<"<03> DisPlay LinkList: ";
        DisplayLinkList(h);
    cout<<"<04> The List Length Is: NO."<<LinkListLength(h)<<endl;
    printf("<05> The List Is %s",(LinkListEmpty(h))?"Empty":"Not Empty");
    char x;
        GetLinkListElem(h,3,x);
    cout<<"\n<06> The Third Elem Is: "<<x<<endl;
    cout<<"<07> The Location Of 'a' Is At NO."<<LocateLinkListElem(h,'a')<<endl;
    cout<<"<08> Tnsert 'f' In The Fourth Place";
        LinkListInsert(h,4,'f');
    cout<<"\n<09> DisPlay Link LIst: ";
        DisplayLinkList(h);
    cout<<"<10> Delete The Third Elem"<<endl;
        LinkListDelete(h,3,x);
    cout<<"<11> DisPlay Link List: ";
        DisplayLinkList(h);
    cout<<"<12> Destroy LinkList";
        DestroyLinkList(h);


    cout<<"\n\n\n----------DoubleLinkList---------"<<endl;
    cout<<"<01> Init Double LinkList"<<endl;
    DLinkNode *DL;
    //DL->next=DL->prior=NULL;
    cout<<"<02> Insert(F) a,b,c,d,e,f"<<endl;
    char DLS[]="abcdef";
        CreateDLinkListF(DL,DLS,6);
    cout<<"<03> DisplayDLinkList: ";
        DisplayDLinkList(DL);
    cout<<"<04> Delete The Third Elem"<<endl;
        DLinkListDelete(DL,3,aa);
    cout<<"<05> DisplayDLinkList: ";
        DisplayDLinkList(DL);
    cout<<"<06> Destroy DLinkList(F)"<<endl;
        DestroyDLinkList(DL);
    cout<<"<07> Insert(R) a,b,c,d,e,f"<<endl;
        CreateDLinkListR(DL,DLS,6);
    cout<<"<08> DisplayDLinkList: ";
        DisplayDLinkList(DL);
    cout<<"<09> Delete The Fourth Elem"<<endl;
        DLinkListDelete(DL,4,aa);
    cout<<"<10> DisplayDLinkList: ";
        DisplayDLinkList(DL);
    cout<<"<11> Destroy DLinkList(R)";
        DestroyDLinkList(DL);


	#ifdef _WIN32
	SetColor(5,0);
	#endif
	
	
    cout<<endl<<"\n\n-----------SqStack----------\n";
    SqStack *s;
    cout<<"<01> InitStack\n";
        InitSqStack(s);
    printf("<02> The Stack Is %s\n",(SqStackEmpty(s)?"Empty":"Not Empty"));
    cout<<"<03> Push Elem a,b,c,d,e\n";
        SqStackPush(s,'a');
        SqStackPush(s,'b');
        SqStackPush(s,'c');
        SqStackPush(s,'d');
        SqStackPush(s,'e');
    printf("<04> The Stack Is %s\n",(SqStackEmpty(s)?"Empty":"Not Empty"));
    cout<<"<05> DisPlay Stack:";
    char t;
    while(s->top!=-1)
    {
        SqStackPop(s,t);
        cout<<t<<" ";
    }
    printf("\n<06> The Stack Is %s\n",(SqStackEmpty(s)?"Empty":"Not Empty"));
    cout<<"<07> Destroy SqStack";
        DestroySqStack(s);
    

    cout<<endl<<"\n\n-----------LinkStack----------\n";
    cout<<"<01> Init Link Stack"<<endl;
    LinkStNode *LS;
    InitLinkStack(LS);
    cout<<"<02> Push a,b,c,d,e"<<endl;
        LinkStackPush(LS,'a');
        LinkStackPush(LS,'b');
        LinkStackPush(LS,'c');
        LinkStackPush(LS,'d');
        LinkStackPush(LS,'e');
    printf("<03> The Link Stack Is %s\n",(LinkStackEmpty(LS)?"Empty":"Not Empty"));
        LinkStackPop(LS,aa);
    cout<<"<04> Pop A Elem: "<<aa<<endl;
        GetLinkStackTop(LS,aa);
    cout<<"<05> The Top Of The Stack Is: "<<aa<<endl;
    cout<<"<06> Pop All Elem: ";
    while(LS->next!=NULL)
    {
        LinkStackPop(LS,aa);
        cout<<aa<<" ";
    }
    printf("\n<07> The Link Stack Is %s\n",(LinkStackEmpty(LS)?"Empty":"Not Empty"));
    cout<<"<08> Destroy The Link Stack"<<endl;

	#ifdef _WIN32
	SetColor(6,0);
	#endif
    
    cout<<"\n\n-----------SqQueue-----------"<<endl;
	cout<<"<01> InitSqQueue\n";
	SqQueue *q;
	    InitSqQueue(q);
	printf("<02> This Queue Is %s\n",(SqQueueEmpty(q)?"Empty":"Not Empt"));
	cout<<"<03> enQueue Elem:a,b,c\n";
	    enSqQueue(q,'a');
	    enSqQueue(q,'b');
	    enSqQueue(q,'c');
	cout<<"<04> deQueue Elem:";
	    deSqQueue(q,x);
	cout<<x<<endl;
	cout<<"<05> enQueue Elem:d,e,f\n";
	    enSqQueue(q,'d');
	    enSqQueue(q,'e');
	    enSqQueue(q,'f');
	cout<<"<06> DisPlay SqQueue:";
	for(int i=q->front+1;i<q->rear;i++)
		cout<<q->data[i]<<" ";
	cout<<endl<<"<07> Destroy The SqQueue\n";
	    DestroySqQueue(q);



    cout<<"\n\n-----------LinkQueue-----------"<<endl;
    cout<<"<01> Init Link Queue"<<endl;
    LinkQuPointerNode *LQP;
        InitLinkQueue(LQP);
    cout<<"<02> enQueue a,b,c,d,e,f"<<endl;
    /*enLinkQueue(LQP,'a');
    enLinkQueue(LQP,'b');
    enLinkQueue(LQP,'c');
    enLinkQueue(LQP,'d');
    enLinkQueue(LQP,'e');
    enLinkQueue(LQP,'f');*/
    for(int i=97;i<=102;i++)//ASCII Coding
        enLinkQueue(LQP,i);
    printf("<03> The Queue Is %s\n",(LinkQueueEmpty(LQP)?"Empty":"Not Empty"));
        deLinkQueue(LQP,aa);
    cout<<"<04> deQueue: "<<aa<<endl;
    cout<<"<05> deQueue All Elem: ";
    while(LQP->front!=NULL)
    {
        deLinkQueue(LQP,aa);
        cout<<aa<<" ";
    }
    printf("\n<06> The Queue Is %s\n",(LinkQueueEmpty(LQP)?"Empty":"Not Empty"));
    cout<<"<07> Destroy The Link Queue"<<endl;
        DestroyLinkQueue(LQP);

	#ifdef _WIN32
	SetColor(4,0);
	#endif
	

    cout<<"\n\n-----------SqString-----------"<<endl;
    cout<<"<01> Define SqString.1/2/3"<<endl;
    SqString str1,str2,str3;
    cout<<"<02> Assign acbdedbca To Str.1"<<endl;
    ElemType strs[]="acbdedbca";
        SqStrAssign(str1,strs);
    cout<<"<03> Display Str.1: ";
        DisplaySqStr(str1);
    printf("<04> Str.1 And Str.2 Is %s\n",(SqStrEqual(str1,str2)?"Same":"Not Same"));
    cout<<"<05> Copy Str.1 To Str.2"<<endl;
        SqStrCopy(str2,str1);
    cout<<"<06> Display Str.2: ";
        DisplaySqStr(str2);
    printf("<07> Str.1 And Str.2 Is %s\n",(SqStrEqual(str1,str2)?"Same":"Not Same"));
    cout<<"<08> The Length Of Str.2 Is "<<SqStrLength(str2)<<endl;
    cout<<"<09> Concat Str.1 And Str.2 To Str.3"<<endl;
        str3=SqStrConcat(str1,str2);
    cout<<"<10> Display Str.3: ";
        DisplaySqStr(str3);
    cout<<"<11> The Length Of Str.3 Is "<<SqStrLength(str3)<<endl;
    cout<<"<12> Sub Str.3 From NO.8 To NO.15"<<endl;
        str3=SubSqStr(str3,8,7);
    cout<<"<13> Display Str.3: ";
        DisplaySqStr(str3);
    cout<<"<14> Insert Str.3 To Str.3 At NO.4"<<endl;
        str3=InsSqStr(str3,5,str3);
    cout<<"<15> Display Str.3: ";
        DisplaySqStr(str3);
    cout<<"<16> Delete No.1 To NO.9 From Str.3"<<endl;
        str3=DelSqStr(str3,1,8);
    cout<<"<17> Display Str.3: ";
        DisplaySqStr(str3);
    cout<<"<18> Str.3 Replace Str.1 From 3 To 8"<<endl;
        str3=RepSqStr(str1,3,5,str3);
    cout<<"<19> Display Str.3: ";
        DisplaySqStr(str3);
    cout<<"<20> Destroy Str.1 Str.2 And Str.3"<<endl;
        DestroySqStr(str1);
        DestroySqStr(str2);
        DestroySqStr(str3);
    
    
    cout<<"\n\n-----------LinkString-----------"<<endl;
    LinkStrNode *Dstr1,*Dstr2,*Dstr3;
    cout<<"<01> Assign Link String"<<endl;
        LinkStrAssign(Dstr1,strs);
    cout<<"<02> The Length Of DStr.1 Is: "<<LinkStrLength(Dstr1)<<endl;
    cout<<"<03> Copy DStr.1 To DStr.2"<<endl;
        LinkStrCopy(Dstr2,Dstr1);
    cout<<"<04> Display DStr.2: ";
        DisplayLinkStr(Dstr2);
    printf("<05> DStr.1 And DStr.2 Is %s\n",(LinkStrEqual(Dstr1,Dstr2)?"Same":"Not Same"));
    cout<<"<06> Concat DStr.1 And DStr.2 To DStr.3"<<endl;
        Dstr3=LinkStrConcat(Dstr1,Dstr2);
    cout<<"<07> Display DStr.3: ";
        DisplayLinkStr(Dstr3);
    cout<<"<08> Sub DStr.3 From 5 To 13"<<endl;
        Dstr3=SubLinkStr(Dstr3,5,8);
    cout<<"<09> Display DStr.3: ";
        DisplayLinkStr(Dstr3);
    printf("<10> DStr.1 And DStr.3 Is %s\n",(LinkStrEqual(Dstr1,Dstr3)?"Same":"Not Same"));
    cout<<"<11> Insert DStr.1 At 2 From Str.3"<<endl;
        Dstr3=InsLinkStr(Dstr1,2,Dstr3);
    cout<<"<12> Display DStr.3: ";
        DisplayLinkStr(Dstr3);
    cout<<"<13> Delete DStr.3 4 To 15"<<endl;
        Dstr3=DelLinkStr(Dstr3,4,11);
    cout<<"<14> Display DStr.3: ";
        DisplayLinkStr(Dstr3);
    cout<<"<15> Replace DStr.3 From 2 To 5 With DStr.1"<<endl;
    Dstr3=RepLinkStr(Dstr3,2,3,Dstr1);
    cout<<"<16> Display DStr.3: ";
        DisplayLinkStr(Dstr3);
    cout<<"<17> Destroy DStr.1 DStr.2 And DStr.3"<<endl;
        DestroyLinkStr(Dstr1);
        DestroyLinkStr(Dstr2);
        DestroyLinkStr(Dstr3);
        
    #ifdef _WIN32
	SetColor(7,0);
	#endif



    cout<<"\n\n-----------BtTree-----------"<<endl;
	BTNode *b,*son;
	char ctmd[]="A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    cout<<"<01> CreateBTree"<<endl;
	    CreateBTree(b,ctmd);
    cout<<"<02> Display BTree: ";
        DisplayBTree(b);
    cout<<"\n<03> The Height Of Tree Is: "<<BTreeHeight(b)<<endl;
    cout<<"<04> Find Node E"<<endl;
        son=FindBTreeNode(b,'E');
    cout<<"<05> Display Tree E: ";
        DisplayBTree(son);
    if(Lchrild(son)!=NULL)
        cout<<"\n<06> Lchrild Of E Is: "<<Lchrild(son)->data<<endl;
    else
        cout<<"\n<06> E:No Left Chrild\n";
    if(Rchrild(son)!=NULL)
        cout<<"<07> Rchrild Of E Is: "<<Rchrild(son)->data<<endl;
    else
        cout<<"<07> E:No Right Chrild\n";
    //cout<<"<08> Destroy Tree"<<endl;
        //DestroyBTree(b);
        //DestroyBTree(son);
    cout<<"<08> RecursionPreOrder Tree: ";
    	RecursionPreOrder(b);
    cout<<"\n<09> No RecursionPreOrder 1 Tree: ";
    	PreOrder1(b);
    cout<<"<10> No RecursionPreOrder 2 Tree: ";
    	PreOrder2(b);
    cout<<"<11> RecursionInOrder Tree: ";
    	RecursionInOrder(b);
    cout<<"\n<12> No RecursionInOrder Tree: ";
    	InOrder1(b);
    cout<<"<13> RecursionPostOrder: ";
		RecursionPostOrder(b);
	cout<<"\n<14> No RecursionPostOrder: ";
		PostOrder1(b);
	cout<<"<15> TraveLevel: ";
		TravLevel(b);


    cout<<"\n\n-----------HCTree-----------"<<endl;
    char stence[]="To Day I Have A Good Idea,And I Am Very Happy!";
    HTNode ht[2*MaxSize-1];
    HCode hcd[MaxSize];
    for(short i=0;i<46;i++)
    {
        ht[i].data=stence[i];
        ht[i].weight=(float)stence[i];
    }
    CreateHT(ht,46);
    CreateHCode(ht,hcd,46);
    DispHCode(ht,hcd,46);
    return 0;
}
