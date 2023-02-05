#include <iostream>

#define MAXSIZE 20

typedef struct SNode *DStack;
typedef int ElementType;
ElementType ERROR = -1;
struct SNode
{
    ElementType Data[MAXSIZE];
    int Top1;
    int Top2;
};

DStack PtrS;

DStack CreateStack()
{
    DStack PtrS = new SNode;
    PtrS->Top1 = -1;
    PtrS->Top2 = MAXSIZE;
    return PtrS;
}

bool IsFull(DStack PtrS)
{
    return PtrS->Top1 + 1 == PtrS->Top2;
}

bool IsValidTag(int Tag)
{
    if (Tag != 1 || Tag != 2)
    {
        puts("Tag错误");
        return false;
    }
    return true;
}

bool IsEmpty(DStack PtrS, int Tag)
{
    if (!IsValidTag)
        return false;

    if (Tag == 1)
        return PtrS->Top1 == -1;
    return PtrS->Top2 == MAXSIZE;
}

void Push(DStack PtrS, ElementType item, int Tag)
{
    if (!IsValidTag)
        return;

    if (IsFull(PtrS))
    {
        puts("堆栈满");
        return;
    }

    if (Tag == 1)
        PtrS->Data[++(PtrS->Top1)] = item;
    PtrS->Data[--(PtrS->Top2)] = item;
}

ElementType Pop(DStack Ptrs, int Tag)
{
    if (!IsValidTag(Tag))
        return ERROR; // 是ElementType的特殊值，表示错误

    if (IsEmpty(PtrS, Tag))
    {
        puts("堆栈空");
        return ERROR;
    }

    if (Tag == 1)
        return PtrS->Data[(PtrS->Top1)--];
    return PtrS->Data[(PtrS->Top2)++];
}

int main() {}