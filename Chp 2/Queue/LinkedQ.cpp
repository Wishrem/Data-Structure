#include <iostream>

typedef struct QNode *LinkedQ;
typedef struct Node *NPtr;
typedef int ElementType;
ElementType ERROR = -1;
struct Node
{
    ElementType item;
    NPtr next;
};

struct QNode
{
    NPtr rear;
    NPtr front;
};

LinkedQ PtrQ;

LinkedQ createQueue()
{
    LinkedQ q = new QNode;
    q->rear = q->front = new Node;
    return q;
}

// 内存足够多，永远不会满

void append(LinkedQ &q, ElementType item)
{
    q->rear->item = item;
    q->rear->next = new Node;
    q->rear = q->rear->next;
}

bool isEmpty(LinkedQ &q)
{
    return q->rear == q->front;
}

ElementType pop(LinkedQ &q)
{
    if (isEmpty(q))
    {
        puts("队列空");
        return ERROR; // 是ElementType的特殊值，表示错误
    }
    NPtr node = q->front;
    ElementType item = node->item;
    q->front = q->front->next;
    free(node);
    return item;
}

void print(LinkedQ &q)
{
    std::cout << "Queue:";
    NPtr tail = q->front;
    while (tail != q->rear)
    {
        std::cout << tail->item << " ";
        tail = tail->next;
    }
    std::cout << std::endl;
}

bool randBoolean()
{
    return rand() % 10 <= 4;
}

void test(LinkedQ &q, int times)
{
    int item = 0;
    for (int i = 0; i < times; i++)
    {
        if (randBoolean())
        {
            printf("尝试插入item=%d\n", item);
            append(q, item++);
        }
        else
        {
            printf("尝试弹出:\n");
            std::cout << pop(q) << std::endl;
        }
        print(q);
        std::cout << "-----------" << std::endl;
    }
}
int main()
{
    PtrQ = createQueue();
    test(PtrQ, 20);
    return 0;
}