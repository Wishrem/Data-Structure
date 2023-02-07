# 树状结构

## 什么是堆

### 定义

**堆（Heap）：用数组表示的完全二叉树，满足任一结点的关键字是其子树所有结点的最大值（或最小值）**

- **最大堆（Max Heap），也称大顶堆：最大值**
- **最小堆（Min Heap），也称小顶堆：最小值**

### ADT描述

最小堆的ADT描述和实现同理可得

**类型名称**：最大堆（Max Heap）

**数据对象集**：完全二叉树，每个结点的元素值不小于其子结点的元素值

**操作集**：最大堆$H\in MaxHeap$，元素$item\in ElementType$，主要的操作有

```c++
MaxHeap create(int size); // 创建一个空的最大堆
bool isFull(MaxHeap h); // 判断最大堆H是否已满
void insert(MaxHeap h, ElementType item); // 将元素item插入最大堆H
bool isEmpty(MaxHeap h); // 判断最大堆H是否为空
ElementType remove(MaxHeap h); // 返回最大堆H中最大的元素
```

```c++
typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
  ElementType *data; // 数组
  int size;  // 当前存储的元素个数
  int cap; 	// 堆的最大容量
};

MaxHeap Heap;
```

ADT的操作集实现详见Heap/MaxHeap.cpp

### 堆的应用

1. **建立最大堆**

> 将已经存在的N个元素按最大堆的要求存放在一个一维数组中

方法：

- 将N个元素按输入顺序存入，先满足完全二叉树的结构特性
- 调整各结点位置，以满足最大堆的有序特性：

实现详见Heap/CreateMaxHeap.cpp
