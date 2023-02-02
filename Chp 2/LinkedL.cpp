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

// 不需要MakeEmpty()

int Length(List Head)
{
    List p = Head; // 指向第一个节点，我们不希望修改Head的指向
    int j = 0;
    while (p)
    {
        p = p->Next;
        j++;
    }
    return j;

    // 时间复杂度O(n)
}

List FindKth(int K, List Head)
{
    List p = Head;
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

List Find(ElementType X, List Head)
{
    List p = Head;
    while (p && p->Data != X)
        p = p->Next;
    return p;
}

List Insert(ElementType X, int i, List Head)
{
    List p, s; // p: 第i个节点的前一个 s: 需要插入的节点
    s = new LNode;
    s->Data = X;
    if (i == 1) // 在表头插入
    {

        s->Next = Head;
        return s;
    }
    p = FindKth(i - 1, Head);
    if (!p) // p为空
    {
        puts("范围错误");
        return Head;
    }

    // 插入
    s->Next = p->Next;
    p->Next = s;
    return Head;
}

List Delete(int i, List Head)
{
    List p, s;
    if (i == 1)
    {
        s = Head;
        if (Head)
            Head = Head->Next;
        free(s);
        return Head;
    }
    p = FindKth(i - 1, Head);
    if (!p || !p->Next)
    {
        puts("范围错误");
        return Head;
    }

    // 删除
    s = p->Next;
    p->Next = s->Next;
    free(s);
    return Head;
}

// Debug

int Rand(int lb, int ub)
{
    return (rand() % (ub - lb + 1) + lb);
}

void Test(List Head, List (*fp)(List Head, int i), int times)
{
    int lb = 1, ub = times;
    int n = Rand(lb, ub);

    int i;
    for (int j = 0; j < n; j++)
    {
        ub = Length(Head) + 2;
        i = Rand(lb, ub);
        Head = fp(Head, i);
    }
}

void PrintList(List Head)
{
    printf("LinkedL:");
    List p = Head;
    while (p)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

List InsertTest(List Head, int i)
{
    ElementType X = Rand(1, 100); // 因为rand都为整数，不考虑类型转换
    printf("尝试在下标i=%d，插入X=%d\n", i, X);
    Head = Insert(X, i, Head);
    PrintList(Head);
    return Head;
}

List DeleteTest(List Head, int i)
{
    printf("尝试删除下标i=%d的元素\n", i);
    Head = Delete(i, Head);
    PrintList(Head);
    return Head;
}

int main()
{
    // test
    Head = Insert(1, 1, Head);
    Test(Head, InsertTest, MAXSIZE + 3);
    Test(Head, DeleteTest, Length(Head) / 2);
    return 0;
}