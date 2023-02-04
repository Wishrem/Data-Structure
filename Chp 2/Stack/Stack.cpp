#include <iostream>

#define MaxSize 10

typedef struct SNode *Stack;
typedef int ElementType;
ElementType ERROR = -1;
struct SNode
{
    ElementType Data[MaxSize];
    int Top;
};

Stack PtrS;

Stack CreateStack()
{
    Stack PtrS = new SNode;
    PtrS->Top = -1;
    return PtrS;
}

bool IsFull(Stack PtrS)
{
    return PtrS->Top - 1 == MaxSize;
}

bool IsEmpty(Stack PtrS)
{
    return PtrS->Top == -1;
}

void Push(Stack PtrS, ElementType Item)
{
    if (IsFull(PtrS))
    {
        puts("堆栈满");
        return;
    }

    PtrS->Data[++(PtrS->Top)] = Item;
}

ElementType Pop(Stack Ptrs)
{
    if (IsEmpty(PtrS))
    {
        puts("堆栈空");
        return ERROR; // 是ElementType的特殊值，表示错误
    }
    return PtrS->Data[(PtrS->Top)--];
}

int main() {}