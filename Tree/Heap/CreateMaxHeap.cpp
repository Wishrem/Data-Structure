#include <iostream>
#include <vector>

typedef struct HeapStruct *MaxHeap;
typedef int ElementType;
ElementType MAXDATA = INT32_MAX;
struct HeapStruct
{
    std::vector<ElementType> data; // 数组
    int size;                      // 当前存储的元素个数
    int cap;                       // 堆的最大容量
};

MaxHeap createMaxHeap(std::vector<ElementType> &data)
{
    MaxHeap h = new HeapStruct;
    h->cap = data.size();
    h->size = data.size();
    h->data = data;

    ElementType tmp;
    int i = (h->size >> 1); // 最后一个非叶子结点
    for (int child, fa; i != 0; i--)
    {
        fa = i;
        tmp = h->data[fa];
        for (; fa <= (h->size >> 1); fa = child)
        {
            child = fa << 1;
            if (child != h->size &&
                h->data[child] < h->data[child + 1])
                ++child;

            if (tmp > h->data[child])
                break;

            h->data[fa] = h->data[child];
        }
        h->data[fa] = tmp;
    }
    return h;
}

ElementType remove(MaxHeap h)
{
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

int main()
{
    puts("输入任意正整数，以-1结尾：");
    int x;
    std::vector<ElementType> data;
    data.push_back(MAXDATA);
    while (true)
    {
        std::cin >> x;
        if (x == -1)
            break;
        data.push_back(x);
    }
    MaxHeap h = createMaxHeap(data);
    for (int i = 0; i < data.size() - 1; i++)
    {
        std::cout << remove(h) << " ";
    }
    std::cout << std::endl;
    return 0;
}