#include <iostream>

#define MAXSIZE 10

typedef struct HeapStruct *MaxHeap;
typedef int ElementType;
ElementType MAXDATA = INT32_MAX;
struct HeapStruct
{
    ElementType *data; // 数组
    int size;          // 当前存储的元素个数
    int cap;           // 堆的最大容量
};

MaxHeap Heap;

MaxHeap create(int size)
{
    MaxHeap h = new HeapStruct;
    h->data = new int[size + 1];
    h->data[0] = MAXDATA; // 哨兵元素
    h->size = 0;
    h->cap = size + 1;
    return h;
}

bool isFull(MaxHeap h)
{
    return h->size == h->cap;
}

bool isEmpty(MaxHeap h)
{
    return h->size == 0;
}

void insert(MaxHeap h, ElementType item)
{
    if (isFull(h))
    {
        puts("最大堆已满");
        return;
    }

    int i;

    i = ++h->size; // 先向后+1
    // 找每个子树的根结点，并对比值的大小
    for (; h->data[i / 2] < item; i /= 2)
        h->data[i] = h->data[i / 2]; // 根结点小于子结点，对换
    h->data[i] = item;
}

ElementType remove(MaxHeap h)
{
    if (isEmpty(h))
    {
        puts("最大堆为空");
        return;
    }

    int fa, child;
    ElementType max, tmp;
    // 用最后一个元素从根结点开始向上过滤下层结点
    max = h->data[1], tmp = h->data[h->size--];
    for (fa = 1; fa <= (h->size >> 1); fa = child)
    {
        child = fa << 1;
        if ((child != h->size) &&                  // 防止越界
            (h->data[child] < h->data[child + 1])) // 指向较大者
            child++;

        if (tmp >= h->data[child])
            break;

        // 向上移动
        h->data[fa] = h->data[child];
    }
    h->data[fa] = tmp;
    return max;
}