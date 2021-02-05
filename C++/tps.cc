#include <stdio.h>
#include <malloc.h>
#include <math.h>
typedef struct node
{
    long index;                             //  当前结点对应的记录下标
    int level;                              //  当前结点的层次->树的高度
    struct node *lchild;                    //  左孩子指针
    struct node *rchild;                    //  右孩子指针
}dec_node;                                  //  判定树结点类型
/**
*   功能:
*       由create_dec_tree调用以建立判定树。由R[low...high]创建根结点
*   的判定树，height为树的高度，初始时，由R[0...n-1]创建判定树，height
*   的初始值为1。
*
*/
static void create_dec_tree1(dec_node *&b, long low, long high, int height)     //  指针的引用
{
    int mid;
    if(low <= high)
    {
        mid = (low + high) / 2;
        b = (dec_node *)malloc(sizeof(dec_node));                               //  动态分配存储空间
        b->index = mid;
        b->level = height;                                                      //  树的高度
        create_dec_tree1(b->lchild, low, mid - 1, height + 1);
        create_dec_tree1(b->rchild, mid + 1, high, height + 1);
    }
    else
        b = NULL;
}
/*------------------建立判定树b------------------*/
static void create_dec_tree(dec_node *&b, long n)
{
    create_dec_tree1(b, 0, n - 1, 1);
}
/*-----------------销毁判定树b------------------*/
static void destroy_dec_tree(dec_node *&b)
{
    if(b != NULL)
    {
        destroy_dec_tree(b->lchild);
        destroy_dec_tree(b->rchild);
        free(b);
    }
}
/*----------------以括号表示法输出判定树b------------------*/
static void disp_dec_tree(dec_node *b)
{
    if(b != NULL)
    {
        printf("%d[%d]", b->index, b->level);
        if(b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");                    //  有孩子结点时才输出(
            disp_dec_tree(b->lchild);       //  递归处理左子树
            if(b->rchild != NULL)
                printf(",");                //  有右孩子结点时才输出,
            disp_dec_tree(b->rchild);       //  递归处理右子树
            printf(")");                    //  有孩子结点时才输出)
        }
    }
}
/*----------------求判定树b中比较的总次数------------------*/
static int sum(dec_node *b)
{
    if(b != NULL)
    {
        if(b->lchild == NULL && b->rchild == NULL)
            return b->level;
        else
            return sum(b->lchild) + sum(b->rchild) + b->level;
    }
    else
        return 0;
}
/*----------------求成功情况下的平均查找长度------------------*/
static double asl_succ(dec_node *b, long n)
{
    return 1.0 * sum(b) / n;
}
int main(int argc, char *argv[])
{
    dec_node *b;
    long n = 11;
    double d, asl1, asl2;
    create_dec_tree(b, n);                  //  建立判定树b
    printf("R[0...%d]判定树:\n\t", n - 1);
    disp_dec_tree(b);
    printf("\n\tASL = %g\n", asl_succ(b, n));
    destroy_dec_tree(b);
    printf("成功平均查找长度分析:\n");
    printf("\tn\t\tASL1\t\tASL2\t\t差值\n");
    for(n = 10; n <= 1000000; n *= 10)
    {
        create_dec_tree(b, n);
        asl1 = asl_succ(b, n);
        asl2 = log(n + 1) - 1;
        d = asl1 - asl2;
        printf("%10d\t\t%g\t\t%g\t\t%g\n", n, asl1, asl2, d);
        destroy_dec_tree(b);
    }
    return 0;
}

