#include <iostream>

ElementType ERROR = -1;
typedef struct SNode *LinkedS;
typedef int ElementType;
struct SNode
{
    ElementType Item;
    LinkedS Next;
};

LinkedS Top; // 始终指向链表头

LinkedS CreateStack()
{
    LinkedS Top = new SNode;
    Top->Next = nullptr;
    return Top;
}

// 永远不会满，只要内存够

bool IsEmpty(LinkedS Top)
{
    return !Top->Next;
}

void Push(LinkedS Top, ElementType Item)
{
    LinkedS TmpCell = new SNode;
    TmpCell->Item = Item;

    TmpCell->Next = Top->Next;
    Top->Next = TmpCell;
}

ElementType Pop(LinkedS Top)
{
    if (IsEmpty(Top))
    {
        puts("堆栈空");
        return ERROR; // 是ElementType的特殊值，表示错误
    }
    LinkedS FirstCell = Top->Next;
    ElementType Item = FirstCell->Item;
    Top->Next = FirstCell->Next;
    free(FirstCell);
    return Item;
}

int main() {}