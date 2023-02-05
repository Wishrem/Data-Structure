#include <iostream>

#define MAXSIZE 10

typedef struct QNode *LoopQ;
typedef int ElementType;
ElementType ERROR = -1;
struct QNode
{
    ElementType data[MAXSIZE + 1];
    int rear;
    int front;
};

LoopQ PtrQ;

LoopQ createQueue()
{
    LoopQ q = new QNode;
    q->front = q->rear = 0;
    return q;
}

bool isFull(LoopQ &q)
{
    return (q->rear + 1) % (MAXSIZE + 1) == q->front;
}

void push(LoopQ &q, ElementType item)
{
    if (isFull(q))
    {
        puts("队列满");
        return;
    }
    q->data[(q->rear)++] = item;
    q->rear %= (MAXSIZE + 1);
}

bool isEmpty(LoopQ &q)
{
    return q->rear == q->front;
}

ElementType pop(LoopQ &q)
{
    if (isEmpty(q))
    {
        puts("队列空");
        return ERROR; // 是ElementType的特殊值，表示错误
    }
    ElementType item = q->data[(q->front)++];
    q->front %= (MAXSIZE + 1);
    return item;
}
bool randBoolean()
{
    return rand() % 10 <= 4;
}

void print(LoopQ &q)
{
    std::cout << "Queue：";
    int idx = q->front;
    for (int i = 0; i < (q->rear - q->front + MAXSIZE + 1) % (MAXSIZE + 1); i++, idx = (idx + 1) % (MAXSIZE + 1))
    {
        std::cout << q->data[idx] << " ";
    }
    std::cout << std::endl;
}

void test(LoopQ &q, int times)
{
    int item = 0;
    for (int i = 0; i < times; i++)
    {
        if (randBoolean())
        {
            printf("尝试插入item=%d\n", item);
            push(q, item++);
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