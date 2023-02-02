#include <iostream>
#include <cstdio>

#define MAXSIZE 10

typedef int ElementType;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L;
List PtrL;

List MakeEmpty()
{
    List PtrL;
    PtrL = new LNode;
    PtrL->Last = -1; // PtrL->Last+1 为长度
    return PtrL;
}

int Find(ElementType X, List PtrL)
{
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X)
        i++;

    // 超过表尾元素下标，即未找到
    if (i > PtrL->Last)
        return -1;
    else
        return i;
}

void Insert(ElementType X, int i, List PtrL)
{
    int j;
    // 长度等于最大长度
    if (PtrL->Last + 1 == MAXSIZE)
    {
        puts("表满");
        return;
    }
    // 检查插入位置的合法性
    if (i < 1 || i > PtrL->Last + 2)
    {
        puts("位置不合法");
        return;
    }
    // 需要在i-1插入，需要将Data[i-1...Last]全部向后移1位
    for (j = PtrL->Last; j >= i - 1; j--)
        PtrL->Data[j + 1] = PtrL->Data[j];
    PtrL->Data[i] = X;
    PtrL->Last++;
    return;
}

void Delete(int i, List PtrL)
{
    int j;
    // 检查删除位置的合法性
    if (i < 1 || i > PtrL->Last + 1)
    {
        printf("不存在第%d个元素", i);
        return;
    }
    // 需要删除下标为i-1的元素，需要将Data[i...Last]全部向前移1位
    for (j = i; j <= PtrL->Last; j++)
        PtrL->Data[j - 1] = PtrL->Data[j];
    PtrL->Last--;
    return;
}

int Length(List PtrL)
{
    return PtrL->Last + 1;
}

// Debug

int Rand(int lb, int ub)
{
    return (rand() % (ub - lb + 1) + lb);
}

void Test(List PtrL, void (*fp)(List PtrL, int i), int times)
{
    int lb = 1, ub = times;
    int n = Rand(lb, ub);

    int i;
    for (int j = 0; j < n; j++)
    {
        ub = PtrL->Last + 3;
        i = Rand(lb, ub);
        fp(PtrL, i);
    }
}

void PrintList(List PtrL)
{
    printf("List:");
    for (int i = 0; i < Length(PtrL); i++)
        printf("%d ", PtrL->Data[i]);
    printf("\n");
}

void InsertTest(List PtrL, int i)
{
    ElementType X = Rand(1, 100); // 因为rand都为整数，不考虑类型转换
    printf("尝试在下标i=%d，插入X=%d\n", i, X);
    Insert(X, i, PtrL);
    PrintList(PtrL);
}

void DeleteTest(List PtrL, int i)
{
    printf("尝试删除下标i=%d的元素\n", i);
    Delete(i, PtrL);
    PrintList(PtrL);
}

int main()
{
    // test
    PtrL = MakeEmpty();
    PrintList(PtrL);
    Test(PtrL, InsertTest, MAXSIZE + 3);
    Test(PtrL, DeleteTest, Length(PtrL) / 2);
    return 0;
}