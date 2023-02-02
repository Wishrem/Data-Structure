#include <iostream>
#include <cstdio>

#define MAXSIZE 10

typedef int ElementType;
typedef struct LNode *List;
struct LNode
{
    ElementType Data;
    List Next;
};
List Head;

// List MakeEmpty()
// {
//     List PtrL;
//     PtrL = new LNode;
//     return PtrL;
// }

int Length(List PtrL)
{
    List p = PtrL; // 指向第一个节点，我们不希望修改PtrL的指向
    int j = 0;
    while (p)
    {
        p = p->Next;
        j++;
    }
    return j;

    // 时间复杂度O(n)
}

List FindKth(int K, List PtrL)
{
    List p = PtrL;
    int i = 1;
    // 不为空，且下标小于K
    while (p && i < K)
    {
        p = p->Next;
        i++;
    }
    if (i == K)
        return p;
    else
        return nullptr;
}

List Find(ElementType X, List PtrL)
{
    List p = PtrL;
    while (p && p->Data != X)
        p = p->Next;
    return p;
}

List Insert(ElementType X, int i, List PtrL)
{
    List p, s; // p: 第i个节点的前一个 s: 需要插入的节点
    s = new LNode;
    s->Data = X;
    if (i == 1) // 在表头插入
    {

        s->Next = PtrL;
        return s;
    }
    p = FindKth(i - 1, PtrL);
    if (!p) // p为空
    {
        puts("范围错误");
        return PtrL;
    }

    // 插入
    s->Next = p->Next;
    p->Next = s;
    return PtrL;
}

List Delete(int i, List PtrL)
{
    List p, s;
    if (i == 1)
    {
        s = PtrL;
        if (PtrL)
            PtrL = PtrL->Next;
        free(s);
        return PtrL;
    }
    p = FindKth(i - 1, PtrL);
    if (!p || !p->Next)
    {
        puts("范围错误");
        return PtrL;
    }

    // 删除
    s = p->Next;
    p->Next = s->Next;
    free(s);
    return PtrL;
}

// Debug

int Rand(int lb, int ub)
{
    return (rand() % (ub - lb + 1) + lb);
}

void Test(List PtrL, List (*fp)(List PtrL, int i), int times)
{
    int lb = 1, ub = times;
    int n = Rand(lb, ub);

    int i;
    for (int j = 0; j < n; j++)
    {
        ub = Length(PtrL) + 2;
        i = Rand(lb, ub);
        PtrL = fp(PtrL, i);
    }
}

void PrintList(List PtrL)
{
    printf("LinkedL:");
    List p = PtrL;
    while (p)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

List InsertTest(List PtrL, int i)
{
    ElementType X = Rand(1, 100); // 因为rand都为整数，不考虑类型转换
    printf("尝试在下标i=%d，插入X=%d\n", i, X);
    PtrL = Insert(X, i, PtrL);
    PrintList(PtrL);
    return PtrL;
}

List DeleteTest(List PtrL, int i)
{
    printf("尝试删除下标i=%d的元素\n", i);
    PtrL = Delete(i, PtrL);
    PrintList(PtrL);
    return PtrL;
}

int main()
{
    // test
    Head = Insert(1, 1, Head);
    Test(Head, InsertTest, MAXSIZE + 3);
    Test(Head, DeleteTest, Length(Head) / 2);
    return 0;
}