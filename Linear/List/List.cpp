#include <iostream>
#include <cstdio>

#define MAXSIZE 10

typedef int ElementType;
typedef struct LNode *List;
struct LNode
{
    ElementType data[MAXSIZE];
    int last;
};
List PtrL;

List makeEmpty()
{
    List l;
    l = new LNode;
    l->last = -1; // l->last+1 为长度
    return l;
}

// findKth没有实现，因为太简单了

int find(ElementType X, List l)
{
    int i = 0;
    while (i <= l->last && l->data[i] != X)
        i++;

    // 超过表尾元素下标，即未找到
    if (i > l->last)
        return -1;
    else
        return i;
}

void insert(ElementType X, int i, List l)
{
    int j;
    // 长度等于最大长度
    if (l->last + 1 == MAXSIZE)
    {
        puts("表满");
        return;
    }
    // 检查插入位置的合法性
    if (i < 1 || i > l->last + 2)
    {
        puts("位置不合法");
        return;
    }
    // 需要在i-1插入，需要将Data[i-1...last]全部向后移1位
    for (j = l->last; j >= i - 1; j--)
        l->data[j + 1] = l->data[j];
    l->data[i] = X;
    l->last++;
    return;
}

void remove(int i, List l)
{
    int j;
    // 检查删除位置的合法性
    if (i < 1 || i > l->last + 1)
    {
        printf("不存在第%d个元素", i);
        return;
    }
    // 需要删除下标为i-1的元素，需要将Data[i...last]全部向前移1位
    for (j = i; j <= l->last; j++)
        l->data[j - 1] = l->data[j];
    l->last--;
    return;
}

int length(List l)
{
    return l->last + 1;
}

// Debug

int randi(int lb, int ub)
{
    return (rand() % (ub - lb + 1) + lb);
}

void test(List l, void (*fp)(List l, int i), int times)
{
    int lb = 1, ub = times;
    int n = randi(lb, ub);

    int i;
    for (int j = 0; j < n; j++)
    {
        ub = l->last + 3;
        i = randi(lb, ub);
        fp(l, i);
    }
}

void printList(List l)
{
    printf("List:");
    for (int i = 0; i < length(l); i++)
        printf("%d ", l->data[i]);
    printf("\n");
}

void insertTest(List l, int i)
{
    ElementType X = randi(1, 100); // 因为rand都为整数，不考虑类型转换
    printf("尝试在下标i=%d，插入X=%d\n", i, X);
    insert(X, i, l);
    printList(l);
}

void deleteTest(List l, int i)
{
    printf("尝试删除下标i=%d的元素\n", i);
    remove(i, l);
    printList(l);
}

int main()
{
    // tests
    PtrL = makeEmpty();
    printList(PtrL);
    test(PtrL, insertTest, MAXSIZE + 3);
    test(PtrL, deleteTest, length(PtrL) / 2);
    return 0;
}