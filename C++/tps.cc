#include <stdio.h>
#include <malloc.h>
#include <math.h>
typedef struct node
{
    long index;                             //  ��ǰ����Ӧ�ļ�¼�±�
    int level;                              //  ��ǰ���Ĳ��->���ĸ߶�
    struct node *lchild;                    //  ����ָ��
    struct node *rchild;                    //  �Һ���ָ��
}dec_node;                                  //  �ж����������
/**
*   ����:
*       ��create_dec_tree�����Խ����ж�������R[low...high]���������
*   ���ж�����heightΪ���ĸ߶ȣ���ʼʱ����R[0...n-1]�����ж�����height
*   �ĳ�ʼֵΪ1��
*
*/
static void create_dec_tree1(dec_node *&b, long low, long high, int height)     //  ָ�������
{
    int mid;
    if(low <= high)
    {
        mid = (low + high) / 2;
        b = (dec_node *)malloc(sizeof(dec_node));                               //  ��̬����洢�ռ�
        b->index = mid;
        b->level = height;                                                      //  ���ĸ߶�
        create_dec_tree1(b->lchild, low, mid - 1, height + 1);
        create_dec_tree1(b->rchild, mid + 1, high, height + 1);
    }
    else
        b = NULL;
}
/*------------------�����ж���b------------------*/
static void create_dec_tree(dec_node *&b, long n)
{
    create_dec_tree1(b, 0, n - 1, 1);
}
/*-----------------�����ж���b------------------*/
static void destroy_dec_tree(dec_node *&b)
{
    if(b != NULL)
    {
        destroy_dec_tree(b->lchild);
        destroy_dec_tree(b->rchild);
        free(b);
    }
}
/*----------------�����ű�ʾ������ж���b------------------*/
static void disp_dec_tree(dec_node *b)
{
    if(b != NULL)
    {
        printf("%d[%d]", b->index, b->level);
        if(b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");                    //  �к��ӽ��ʱ�����(
            disp_dec_tree(b->lchild);       //  �ݹ鴦��������
            if(b->rchild != NULL)
                printf(",");                //  ���Һ��ӽ��ʱ�����,
            disp_dec_tree(b->rchild);       //  �ݹ鴦��������
            printf(")");                    //  �к��ӽ��ʱ�����)
        }
    }
}
/*----------------���ж���b�бȽϵ��ܴ���------------------*/
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
/*----------------��ɹ�����µ�ƽ�����ҳ���------------------*/
static double asl_succ(dec_node *b, long n)
{
    return 1.0 * sum(b) / n;
}
int main(int argc, char *argv[])
{
    dec_node *b;
    long n = 11;
    double d, asl1, asl2;
    create_dec_tree(b, n);                  //  �����ж���b
    printf("R[0...%d]�ж���:\n\t", n - 1);
    disp_dec_tree(b);
    printf("\n\tASL = %g\n", asl_succ(b, n));
    destroy_dec_tree(b);
    printf("�ɹ�ƽ�����ҳ��ȷ���:\n");
    printf("\tn\t\tASL1\t\tASL2\t\t��ֵ\n");
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

