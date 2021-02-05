
// This File Was Created By Wubin In 2020.11.01
// Copyright (C) 2020s Free Software Foundation
// Version 1.7.1
// Coding: UTF-8,GB2312

// This Head File Included The Omnipotent Head File <bits/stdc++.h>
// The Part Of "Windows API" Functions Can Be Used By (GUN) In Widows Only 
// And These Functions Can Not Be Complied In Unix or Linux Operation System

// But The Other Parts "Data_Structure" Is Support For Unix or Linux

// If The Complier Can Not Find "bits/stdc++.h"
// Replace It With "iostream","cstring","cmath","ctime","cstdlib",etc.
//Or Make A New Folder "bits",And Create "stdc++.h" In It: http://t.cn/A65TsqMm
#pragma once

#ifndef __DATA_H__
#define __DATA_H__

//Avoid duplicate definitions

#include <bits/stdc++.h> //Omnipotent Head Files

using namespace std;

#ifdef _WIN32
#include<windows.h>
//------------------------Windows API-------------------------//

void win_size(short int length, short int width) //Set the windows size
{
    char commd[30];
    sprintf(commd, "mode con cols=%d lines=%d", length, width);
    system(commd);
    return;
}

//Set the upground color and background color of fonts
void SetColor(unsigned short int ForeColor, unsigned short int BackGroundColor)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
    return;
    {
        //1 Deep Blue
        //2 Green
        //3 Small Blue
        //4 Red
        //5 Purple
        //6 Yellow
        //7 White
        //8 Little White
        //9 Normal Bule
    }
}

void dis_win_max() //Disable the windows maximize
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    RemoveMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    DestroyMenu(hMenu);
    ReleaseDC(hWnd, NULL);
    return;
}

void win_on_top() //Set the windows always on top
{
    SetWindowPos(GetForegroundWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    return;
}

void win_centre() //Set the windows at the middle of screen, But It does not work very well
{
    int scrWidth, scrHeight;
    RECT rect;
    HWND hWnd = GetConsoleWindow();
    scrWidth = GetSystemMetrics(SM_CXSCREEN);
    scrHeight = GetSystemMetrics(SM_CYSCREEN);
    GetWindowRect(hWnd, &rect);
    SetWindowPos(hWnd, HWND_TOPMOST, (scrWidth - rect.right) / 2, (scrHeight - rect.bottom) / 2, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
    return;
}

//Useless Functions

void progressbar(float cols, short int speed) //Draw the progress bar,"cols"->space
{
    for (short int i = 1; i <= cols; i++)
    {
        if (i == cols)
            std::cout << "\b";
        SetColor(0, 25);
        printf(" ");
        printf("%2.0f%%", 100.0 / cols * i);
        Sleep(21 - 0.15 * speed);
        printf("\b\b\b");
    }
    SetColor(4, 25);
    cout << "\b\b\b\b\b\b\b\b\b\bComplate " << endl;
    SetColor(7, 0);
}

void jumpdown(short int lines) //Batch output line breaksx, Extraordinary Useless
{
    for (short int i = 1; i <= lines; i++)
        std::cout << std::endl;
    return;
}

void love_graphical(char *word) //draw the love ,max=10 charaters
{
    short int digital = strlen(word), s = 0;
    for (float x = 1.3; x >= -1.1; x -= 0.1)
    {
        for (float y = -2; y <= 1.4; y += 0.053)
        {
            if (pow(x * x + y * y - 1, 3) - x * x * x * y * y <= 0)
            {
                s++;
                if (digital > 0)
                {
                    if (s % digital == 1)
                        printf("%c", word[0]);
                    if (s % digital == 2)
                        printf("%c", word[1]);
                    if (s % digital == 3)
                        printf("%c", word[2]);
                    if (s % digital == 4)
                        printf("%c", word[3]);
                    if (s % digital == 5)
                        printf("%c", word[4]);
                    if (s % digital == 6)
                        printf("%c", word[5]);
                    if (s % digital == 7)
                        printf("%c", word[6]);
                    if (s % digital == 8)
                        printf("%c", word[7]);
                    if (s % digital == 9)
                        printf("%c", word[8]);
                    //Extendable
                    //...
                    //...
                    if (s % digital == 0)
                        printf("%c", word[digital - 1]);
                }
                if (digital == 0)
                    printf("%d", rand() % 10);
                if (digital == -1)
                {
                    SetColor(0, rand() % 6 + 10);
                    printf(" ");
                }
                Sleep(1);
            }
            else
            {
                if (digital == -1)
                    SetColor(0, 0);
                printf(" ");
            }
        }
        printf("\n");
    }
    return;
}

void tower(short int n, unsigned short int stat) //"stat"=0 none ; 1:up ; 2:down ; 3:up+down;
{
    //This Is A Useless Functions!
    short int i, j;
    //Upper Part
    if (stat <= 0 || stat > 3)
        return;
    if (stat >= 1 && stat != 2)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = n - 1; j >= i; j--)
                printf(" ");
            for (j = 1; j <= 2 * i - 1; j++)
                printf("*");
            printf("\n");
        }
    }
    //Lower part
    if (stat >= 2)
    {
        for (i = 1; i <= n - 1; i++)
        {
            for (j = 1; j <= i; j++)
                printf(" ");
            for (j = 2 * n - 2; j >= 2 * i; j--)
                printf("*");
            printf("\n");
        }
    }
}

void strdelc(char *s,char c) //Delete the space,all the spaces!
{
    char *p = s, *d = s;
    while (*s != '\0')
    {
        p = s;
        if (*p++ == c)
        {
            d = s;
            while (*d != '\0')
            {
                *d = *p;
                d++;
                p++;
            }
            strdelc(s,c); //The Recursive Calls
        }
        s++;
        //if(*d!=32&&*d!='\0')s1++;
    }
}

#endif

//------------------------Data Structure-------------------------//

/*---------------------------------------------------------------*/
/*-----------------------Sequence Table--------------------------*/
/*---------------------------------------------------------------*/

#define MaxSize 50     //Global Variable
typedef char ElemType; //Modifiable Type


typedef struct SequenceTable
{
    ElemType data[MaxSize];
    int length;
} SqList; //define a new type of struct

void CreateSqList(SqList *&L, ElemType a[], int n)
{
    int i = 0, k = 0;
    L = (SqList *)malloc(sizeof(SqList)); //Allocate Space And Format The Space
    while (i < n)
    {
        L->data[k] = a[i];
        k++;
        i++;
    }
    L->length = k;
}

void InitSqList(SqList *&L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

void DestroySqList(SqList *&L)
{
    free(L);
}

bool SqListEmpty(SqList *L)
{
    return (L->length == 0);
}

int SqListLength(SqList *L)
{
    return (L->length);
}

void DisplaySqList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
        cout << L->data[i] << " ";
    cout << endl;
}

bool GetSqListElem(SqList *L, int i, ElemType &e)
{
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i - 1];
    return true;
}

int LocateSqListElem(SqList *L, ElemType e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;
    if (i >= L->length)
        return 0;
    else
        return i + 1;
}

bool SqListInsert(SqList *&L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1 || L->length == MaxSize)
        return false;
    i--;
    for (int j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
    return true;
}

bool SqListDelete(SqList *&L, int i, ElemType &e)
{
    if (i < 1 || i > L->length)
        return false;
    i--;
    e = L->data[i];
    for (int j = i; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return true;
}

/*---------------------------------------------------------------*/
/*--------------------Single Linked List-------------------------*/
/*---------------------------------------------------------------*/

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;

void CreateLinkListF(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

void CreateLinkListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void InitLinkList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
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

bool LinkListEmpty(LinkNode *L)
{
    return (L->next == NULL);
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

void DisplayLinkList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool GetLinkListElem(LinkNode *L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L;
    if (i < 0)
        return false;
    while (j < i && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        e = p->data;
        return true;
    }
}

int LocateLinkListElem(LinkNode *L, ElemType e)
{
    int i = 1;
    LinkNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return false;
    else
        return i;
}

bool LinkListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 0;
    LinkNode *p = L, *s;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

bool LinkListDelete(LinkNode *&L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L, *q;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        q = p->next;
        if (q == NULL)
            return false;
        e = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}

/*---------------------------------------------------------------*/
/*--------------------Double Linked List-------------------------*/
/*---------------------------------------------------------------*/

typedef struct DoubleLinkedList
{
    ElemType data;
    struct DoubleLinkedList *prior;
    struct DoubleLinkedList *next;
} DLinkNode;

void CreateDLinkListF(DLinkNode *&L, ElemType a[], int n)
{
    DLinkNode *s;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;
        if (L->next != NULL)
            L->next->prior = s;
        L->next = s;
        s->prior = L;
    }
}

void CreateDLinkListR(DLinkNode *&L, ElemType a[], int n)
{
    DLinkNode *s, *r;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}

bool DLinkListInsert(DLinkNode *&L, int i, ElemType e)
{
    int j = 0;
    DLinkNode *p = L, *s;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        if (p->next != NULL)
            p->next->prior = s;
        s->prior = p;
        p->next = s;
        return true;
    }
}

bool DLinkListDelete(DLinkNode *&L, int i, ElemType &e)
{
    int j = 0;
    DLinkNode *p = L, *q;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return true;
    else
    {
        q = p->next;
        if (q == NULL)
            return false;
        e = q->data;
        p->next = q->next;
        if (q->next != NULL)
            q->next->prior = p;
        free(q);
        return true;
    }
}

void DestroyDLinkList(DLinkNode *&L)
{
    DLinkNode *pre=L,*p=L->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
    return ;
}

void DisplayDLinkList(DLinkNode *&L)
{
    DLinkNode *s=L->next;
    while(s!=NULL)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
    return ;
}

/*---------------------------------------------------------------*/
/*-----------------------Sequence Stack--------------------------*/
/*---------------------------------------------------------------*/

typedef struct SqStack
{
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitSqStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

void DestroySqStack(SqStack *&s)
{
    free(s);
}

bool SqStackEmpty(SqStack *s)
{
    return s->top == -1;
}

bool SqStackPush(SqStack *&s, ElemType e)
{
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool SqStackPop(SqStack *&s, ElemType &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetSqStackTop(SqStack *&s, ElemType &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

/*---------------------------------------------------------------*/
/*-------------------------Linked Stack--------------------------*/
/*---------------------------------------------------------------*/

typedef struct LinkStackNode
{
    ElemType data;
    struct LinkStackNode *next;
} LinkStNode;

void InitLinkStack(LinkStNode *&s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

void DestroyLinkStack(LinkStNode *&s)
{
    LinkStNode *pre = s, *p = s->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool LinkStackEmpty(LinkStNode *s)
{
    return (s->next == NULL);
}

void LinkStackPush(LinkStNode *&s, ElemType e) //HeadInsert
{
    LinkStNode *p;
    p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

bool LinkStackPop(LinkStNode *&s, ElemType &e)
{
    LinkStNode *p;
    if (s->next == NULL)
        return false;
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool GetLinkStackTop(LinkStNode *s, ElemType &e)
{
    if (s->next == NULL)
        return false;
    e = s->next->data;
    return true;
}

/*---------------------------------------------------------------*/
/*------------------------Circular Queue-------------------------*/
/*---------------------------------------------------------------*/

typedef struct SqQueue
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitSqQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

void DestroySqQueue(SqQueue *&q)
{
    free(q);
}

bool SqQueueEmpty(SqQueue *q)
{
    return (q->rear == q->front);
}

bool enSqQueue(SqQueue *&q, ElemType e)
{
    if ((q->rear + 1) % MaxSize == q->front)
        return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

bool deSqQueue(SqQueue *&q, ElemType &e)
{
    if (q->front == q->rear)
        return false;
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}

/*---------------------------------------------------------------*/
/*-------------------------Linked Queue--------------------------*/
/*---------------------------------------------------------------*/

typedef struct QuDataNode
{
    ElemType data;
    struct QuDataNode *next;
} LinkQuDataNode;

typedef struct QuPiontNode
{
    LinkQuDataNode *front;
    LinkQuDataNode *rear;
} LinkQuPointerNode;

void InitLinkQueue(LinkQuPointerNode *&q)
{
    q = (LinkQuPointerNode *)malloc(sizeof(LinkQuPointerNode));
    q->front = q->rear = NULL;
    return ;
}

void DestroyLinkQueue(LinkQuPointerNode *&q)
{
    LinkQuDataNode *pre=q->front,*p;
    if(pre!=NULL)
    {
        p=pre->next;
        while(pre!=NULL)
        {
            free(pre);
            pre=p;
            p=pre->next;
        }
        free(pre);
    }
    free(q);
    return ;
}

void enLinkQueue(LinkQuPointerNode *&q,ElemType e)
{
    LinkQuDataNode *p;
    p=(LinkQuDataNode *)malloc(sizeof(LinkQuDataNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL)
        q->front=q->rear=p;
    else
    {
        q->rear->next=p;
        q->rear=p;
    }
    return ;
}

bool deLinkQueue(LinkQuPointerNode *&q,ElemType &e)
{
    LinkQuDataNode *t;
    if(q->rear==NULL)
        return false;
    t=q->front;
    if(q->front==q->rear)
        q->front=q->rear=NULL;
    else
        q->front=q->front->next;
    e=t->data;
    free(t);
    return true;
}

bool LinkQueueEmpty(LinkQuPointerNode *q)
{
    if(q->rear==NULL)
        return true;
    else
        return false;
}

/*---------------------------------------------------------------*/
/*------------------------Sequence String------------------------*/
/*---------------------------------------------------------------*/

typedef struct SqString
{
    char data[MaxSize];
    int length;
}SqString;

void SqStrAssign(SqString &s,char cstr[])
{
    int i;
    for(i=0;cstr[i]!='\0';i++)
        s.data[i]=cstr[i];
    s.length=i;
    return ;
}

void DestroySqStr(SqString &s)
{
    //This is a sequence string.
    //The storage space of the string is managed by the operating system.
    //Its storage space will be released when it is out of scope.
    //So there is no operation here.
    return ;
}

void SqStrCopy(SqString &s,SqString t)
{
    int i;
    for(i=0;t.data[i]!='\0';i++)
        s.data[i]=t.data[i];
    s.length=t.length;
    return ;
}

bool SqStrEqual(SqString s,SqString t)
{
    bool same=true;
    int i;
    if(s.length!=t.length)
        same=false;
    else
        for(i=0;i<s.length;i++)
        {
            if(s.data[i]!=t.data[i])
            {
                same=false;
                break;
            }
        }
    return same;
}

int SqStrLength(SqString s)
{
    return s.length;
}

SqString SqStrConcat(SqString s,SqString t)
{
    int i;
    SqString str;
    str.length=s.length+t.length;
    for(i=0;i<s.length;i++)
        str.data[i]=s.data[i];
    for(i=0;i<t.length;i++)
        str.data[s.length+i]=t.data[i];
    return str;
}

//Return a string of J consecutive characters starting from NO.i
SqString SubSqStr(SqString s,int i,int j)
{
    int k;
    SqString str;
    str.length=0;
    if(i<0||i>s.length||j<0||i+j-1>s.length)
        return str;//empty string
    for(k=i-1;k<i+j-1;k++)
        str.data[k-i+1]=s.data[k];
    str.length=j;
    return str;
}

SqString InsSqStr(SqString s1,int i,SqString s2)
{
    int j;
    SqString str;
    str.length=0;
    if(i<0||i>s1.length)
        return str;
    for(j=0;j<i-1;j++)
        str.data[j]=s1.data[j];
    for(j=0;j<s2.length;j++)
        str.data[j+i-1]=s2.data[j];
    for(j=i-1;j<s1.length;j++)
        str.data[j+s2.length]=s1.data[j];
    str.length=s1.length+s2.length;
    return str;
}

SqString DelSqStr(SqString s,int i,int j)
{
    int k;
    SqString str;
    str.length=0;
    if(i<=0||i>s.length||j<0||i+j-1>s.length)
        return str;
    for(k=0;k<i-1;k++)
        str.data[k]=s.data[k];
    for(k=i+j-1;k<s.length;k++)
        str.data[k-j]=s.data[k];
    str.length=s.length-j;
    return str;
}

SqString RepSqStr(SqString s,int i,int j,SqString t)
{
    int k;
    SqString str;
    str.length=0;
    if(i<=0||i>s.length||i+j-1>s.length||j<0)
        return str;
    for(k=0;k<i-1;k++)
        str.data[k]=s.data[k];
    for(k=0;k<t.length;k++)
        str.data[k+i-1]=t.data[k];
    for(k=i+j-1;k<s.length;k++)
        str.data[k-j+t.length]=s.data[k];
    str.length=s.length+t.length-j;
    return str;
}

void DisplaySqStr(SqString s)
{
    int i;
    if(s.length>0)
    {
        for(i=0;i<s.length;i++)
            cout<<s.data[i]<<" ";
        cout<<endl;
    }
}

/*---------------------------------------------------------------*/
/*------------------------Linked String--------------------------*/
/*---------------------------------------------------------------*/

typedef struct LinkStringNode
{
    char data;
    struct LinkStringNode *next;
}LinkStrNode;

void LinkStrAssign(LinkStrNode *&s,char cstr[])
{
    int i;
    LinkStrNode *r,*q;
    s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    r=s;
    for(i=0;cstr[i]!='\0';i++)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=cstr[i];
        r->next=q;
        r=q;
    }
    r->next=NULL;
}

void DestroyLinkStr(LinkStrNode *&s)
{
    LinkStrNode *pre=s,*p=s->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

void LinkStrCopy(LinkStrNode *&s,LinkStrNode *t)
{
    LinkStrNode *p=t->next,*q,*r;
    s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    r=s;
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
}

bool LinkStrEqual(LinkStrNode *s,LinkStrNode *t)
{
    LinkStrNode *p=s->next,*q=t->next;
    while (p!=NULL&&q!=NULL&p->data==q->data)
    {
        p=p->next;
        q=q->next;
    }
    if(p==NULL&&q==NULL)
        return true;
    else
        return false;
}

int LinkStrLength(LinkStrNode *s)
{
    int i=0;
    LinkStrNode *p=s->next;
    while (p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}

LinkStrNode *LinkStrConcat(LinkStrNode *s,LinkStrNode *t)
{
    LinkStrNode *str,*p=s->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    r=str;
    while(p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    p=t->next;
    while(p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LinkStrNode *SubLinkStr(LinkStrNode *s,int i,int j)
{
    int k;
    LinkStrNode *str,*p=s->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0||i>LinkStrLength(s)||j<0||i+j-1>LinkStrLength(s))
        return str;
    for(k=1;k<i;k++)
        p=p->next;
    for(k=1;k<=j;k++)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LinkStrNode *InsLinkStr(LinkStrNode *s,int i,LinkStrNode *t)
{
    LinkStrNode *str,*p=s->next,*pl=t->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0||i>LinkStrLength(s)+1)
        return str;
    for(int k=1;k<i;k++)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    while (pl!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=pl->data;
        r->next=q;
        r=q;
        pl=pl->next;
    }
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LinkStrNode *DelLinkStr(LinkStrNode *s,int i,int j)
{
    int k;
    LinkStrNode *str,*p=s->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0||i>LinkStrLength(s)||j<0||i+j-1>LinkStrLength(s))
        return str;
    for(k=1;k<i;k++)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    for ( k = 0; k < j; k++)
        p=p->next;
    while(p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LinkStrNode *RepLinkStr(LinkStrNode *s,int i, int j,LinkStrNode *t)
{
    int k;
    LinkStrNode *str,*p=s->next,*pl=t->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0||i>LinkStrLength(s)||j<0||i+j-1>LinkStrLength(s))
        return str;
    for(k=0;k<i-1;k++)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        q->next=NULL;
        r->next=q;
        r=q;
        p=p->next;
    }
    for(k=0;k<j;k++)
        p=p->next;
    while (pl!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=pl->data;
        q->next=NULL;
        r->next=q;
        r=q;
        pl=pl->next;
    }
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        q->next=NULL;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

void DisplayLinkStr(LinkStrNode *s)
{
    LinkStrNode *p=s->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}


/*---------------------------------------------------------------*/
/*----------------------------BtTree-----------------------------*/
/*---------------------------------------------------------------*/


typedef struct TreeNode 
{	
	ElemType data;			
	struct TreeNode *lchild;	
	struct TreeNode *rchild;	
} BTNode;

void CreateBTree(BTNode *&b,char *str)
{
    BTNode *St[MaxSize],*p;
    short int top=-1,j=0;
    bool k;
    char ch;
    b=NULL;
    ch=str[j];
    while (ch!='\0')
    {
        switch(ch)
        {
            case '(':
                {
                    top++;
                    St[top]=p;
                    k=true;
                    break;
                }
            case ')':
                    top--;
                    break;
            case ',':
                    k=false;
                    break;
            default :
                {
                    p=(BTNode *)malloc(sizeof(BTNode));
                    p->data=ch;
                    p->lchild=p->rchild=NULL;
                    if(b==NULL)
                        b=p;
                    else
                    {
                        if(k)
                            St[top]->lchild=p;
                        else
                            St[top]->rchild=p;
                    }
                    
                }
        }
        j++;
        ch=str[j];
    }
}

BTNode *Lchrild(BTNode *b)
{
    return b->lchild;
}

BTNode *Rchrild(BTNode *b)
{
    return b->rchild;
}

void DestroyBTree(BTNode *&b)
{
    if(b!=NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

BTNode *FindBTreeNode(BTNode *b,ElemType e)
{
    BTNode *p;
    if(b==NULL)
        return NULL;
    else if(b->data==e)
        return b;
    else
    {
        p=FindBTreeNode(b->lchild,e);
        if(p!=NULL)
            return p;
        else
            return FindBTreeNode(b->rchild,e);
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

void RecursionPreOrder(BTNode *b)
{
	if (b!=NULL)  
	{	
		cout<<b->data<<" ";
		RecursionPreOrder(b->lchild);
		RecursionPreOrder(b->rchild);
	}
}

void PreOrder1(BTNode *b)
{
	BTNode *p=b,*St[MaxSize];
    short int top =-1;
    if(b!=NULL)
    {
        St[++top]=b;
        while(top!=-1)
        {
            cout<<St[top]->data<<" "; 
            p=St[top--];
            if(p->rchild!=NULL)
                St[++top]=p->rchild;
            if(p->lchild!=NULL)
                St[++top]=p->lchild;
        }
        cout<<endl;
    }
}

void PreOrder2(BTNode *b)
{
	BTNode *p=b,*St[MaxSize];
	short int top=-1;
	while(top!=-1 || p!=NULL)
	{
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			St[++top]=p;
			p=p->lchild;
		}
		if(top!=-1)
		{
			p=St[top--];
			p=p->rchild;
		}
	}
	cout<<endl;
}

void RecursionInOrder(BTNode *b)
{
	if (b!=NULL)  
	{	
		RecursionInOrder(b->lchild);
		cout<<b->data<<" ";
		RecursionInOrder(b->rchild);
	}
}

void InOrder1(BTNode *b)
{
	BTNode *p=b,*St[MaxSize];
	short int top=-1;
	while(top!=-1 || p!=NULL)
	{
		while(p!=NULL)
		{
			St[++top]=p;
			p=p->lchild;	
		}
		if(top!=-1)
		{
			p=St[top--];
			cout<<p->data<<" ";
			p=p->rchild;
		}
	}
	cout<<endl;
}

void RecursionPostOrder(BTNode *b)
{
	if (b!=NULL)  
	{	
		RecursionPostOrder(b->lchild);
		RecursionPostOrder(b->rchild);
		cout<<b->data<<" ";
	}
}

void PostOrder1(BTNode *b)
{
	BTNode *p,*St[MaxSize];
	short int top=-1;
	bool flag;
	if (b!=NULL)
	{
		do
		{
			while (b!=NULL)
			{
				St[++top]=b;
				b=b->lchild;
			}
			p=NULL;
			flag=true;
			while (top!=-1 && flag)
			{
				b=St[top];
				if (b->rchild==p)
				{
					cout<<b->data<<" "; 
					top--;
					p=b;
				}
				else
				{
					b=b->rchild;
					flag=false;	
				}
			}
		} while (top!=-1);
		cout<<endl;
	}
}

void TravLevel(BTNode *b)
{
	BTNode *Qu[MaxSize];
	short int front,rear;
	front=rear=0;
    if (b!=NULL) 
		cout<<b->data<<" ";
	Qu[++rear]=b;
    while (rear!=front)
    {
		front=(front+1)%MaxSize;
		b=Qu[front];
		if (b->lchild!=NULL)
		{
			cout<<b->lchild->data<<" ";
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL)
		{
			cout<<b->rchild->data<<" ";
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->rchild;
		}
	} 
	cout<<endl;
}

/*---------------------------------------------------------------*/
/*----------------------------HtTree-----------------------------*/
/*---------------------------------------------------------------*/

typedef struct HTNode
{
	char data;	
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

typedef struct HCode
{
	char cd[MaxSize];
	int start;
} HCode;

void CreateHT(HTNode ht[],int n)
{
	int i,k,lnode,rnode;
	int min1,min2;
	for (i=0;i<2*n-1;i++)
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=n;i<2*n-1;i++)
	{
		min1=min2=32767;
		lnode=rnode=-1;
		for (k=0;k<=i-1;k++)
			if (ht[k].parent==-1)
			{
				if (ht[k].weight<min1)
				{
					min2=min1;rnode=lnode;
					min1=ht[k].weight;lnode=k;
				}
				else if (ht[k].weight<min2)
				{
					min2=ht[k].weight;rnode=k;
				}
			}
		ht[lnode].parent=i;ht[rnode].parent=i;
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;ht[i].rchild=rnode;
	}
}

void CreateHCode(HTNode ht[],HCode hcd[],int n)
{
	int i,f,c;
	HCode hc;
	for (i=0;i<n;i++)
	{
		hc.start=n;c=i;
		f=ht[i].parent;
		while (f!=-1)
		{
			if (ht[f].lchild==c)
				hc.cd[hc.start--]='0';
			else
				hc.cd[hc.start--]='1';
			c=f;f=ht[f].parent;
		}
		hc.start++;
		hcd[i]=hc;
	}
}

void DispHCode(HTNode ht[],HCode hcd[],int n)
{
	int i,k;
	int sum=0,m=0,j;
	printf("DisPlay HCode: \n"); 
	for (i=0;i<n;i++)
	{
		j=0;
		printf("      %c:\t",ht[i].data);
		for (k=hcd[i].start;k<=n;k++)
		{
			printf("%c",hcd[i].cd[k]);
			j++;
		}
		m+=ht[i].weight;
		sum+=ht[i].weight*j;
		printf("\n");
	}
	printf("Average Length=%g\n",1.0*sum/m);
}

/*---------------------------------------------------------------*/
/*-----------------------------Graph-----------------------------*/
/*---------------------------------------------------------------*/

#define MAXV MaxSize
#define INF 32767           //define Infinity
typedef char InfoType;


//Adjacency Matrix
typedef struct VertexType
{
    int no;
    InfoType info;
}VertexType;

typedef struct MatGraph
{
    int edges[MAXV][MAXV];
    int n,e;
    VertexType vex[MAXV];
}MatGraph;


//Adjacency List
typedef struct ANode
{
    int adjvex;
    struct ANode *nextarc;
    int weight;
}ArcNode;

typedef struct VNode
{
    InfoType info;
    ArcNode *firstarc;
}VNode;

typedef struct AdjGraph
{
    VNode adjlist[MAXV];
    int n,e;
}AdjGraph;

void CreateMat(MatGraph &g,int A[MAXV][MAXV],int n,int e)
{
    int i,j;
    g.n=n;g.e=e;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            g.edges[i][j]=A[i][j];
}

void DisplayMat(MatGraph g)
{
    int i,j;
    for(i=0;i<g.n;i++)
    {
        for(j=0;j<g.n;j++)
            if (g.edges[i][j]!=INF)
				printf("%4d",g.edges[i][j]);
			else
				printf("%4s","¡Þ");
        printf("\n");
    }
}

void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)
{
    int i,j;ArcNode *p;
    G=(AdjGraph *)malloc(sizeof(AdjGraph));
    for(i=0;i<n;i++)
        G->adjlist[i].firstarc=NULL;
    for(i=0;i<n;i++)
        for(j=n-1;j>=0;j--)
            if(A[i][j]!=0 && A[i][j]!=INF)
            {
                p=(ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex=j;p->weight=A[i][j];
                p->nextarc=G->adjlist[i].firstarc;
                G->adjlist[i].firstarc=p;
            }
    G->n=n;
    G->e=e;
}

void DisplayAdj(AdjGraph *G)
{
    int i;ArcNode *p;
    for(i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        printf("%3d: ",i);
        while(p!=NULL)
        {
            printf("%3d[%3d]->",p->adjvex,p->weight);
            p=p->nextarc;
        }
        printf("\n");
    }
}

void DestroyAdj(AdjGraph *&G)
{
    int i;ArcNode *pre,*p;
    for(i=0;i<G->n;i++)
    {
        pre=G->adjlist[i].firstarc;
        if(pre!=NULL)
        {
            p=pre->nextarc;
            while(p!=NULL)
            {
                free(pre);
                pre=p;
                p=p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

void MatToList(MatGraph g,AdjGraph *&G)
{
    int i,j;
    ArcNode *p;
    
}

#endif //end of define of this head file
