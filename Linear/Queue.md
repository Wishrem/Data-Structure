# 线性结构

## 什么是队列

### 定义

**队列（Queue）：具有一定操作约束的线性表，只能在==一端插入==，而在==另一端删除==。**

### ADT描述

**类型名称**：队列（Queue）

**数据对象集**：一个有0个或多个元素的有穷线性表。

**操作集**：长度为$MaxSize$的队列$Q\in Queue$，队列元素$item\in ElementType$

```c++
Queue createQueue(int maxSize); // 生成长度为MaxSize的空队列
bool isFull(Queue q, int maxSize); // 判断队列Q是否已满
void append(Queue q, ElementType item); // 将数据元素item插入队列Q中
bool isEmpty(Queue q); // 判断队列Q是否为空
ElementType pop(Queue q); // 将队头数据元素从队列中删除并返回
```

### 物理存储实现

1. **顺序存储**

**由一个==一位数组==和一个记录队列头元素位置的变量==front==以及一个记录队列尾元素位置的变量==rear==组成**

![Queue](https://github.com/Wishrem/Data-Structure/blob/main/Linear/img/Queue.png)

```c++
typedef struct QNode *Queue;
struct QNode{
  ElementType data[MaxSize];
  int rear;
  int front;
};

Queue PtrQ;
```

~~不实现，用处太小~~

2. **顺环队列**

![LoopQ](https://github.com/Wishrem/Data-Structure/blob/main/Linear/img/LoopQ.png)

```c++
typedef struct QNode *LoopQ;
struct QNode{
  ElementType data[MaxSize+1]; // 多开一个空间，用于区分队列为空和队列为满的状态
  int rear;
  int front;
};

LoopQ PtrQ;
```

ADT的操作集实现详见Queue/LoopQ.cpp，⚠️注意rear和front的初始值都为0，front==rear时为空，rear%MaxSize\==front时为满

运行指令：

```bash
g++ LoopQ.cpp -o LoopQ.out
./LoopQ.out
```

3. **链式存储**

**用一个==单链表==实现，插入在队尾进行，删除在队头进行 **

![LinkedQ](https://github.com/Wishrem/Data-Structure/blob/main/Linear/img/LinkedQ.png)

```c++
typedef struct QNode *LinkedQ; // Linked Queue
typedef struct Node *NPtr;
struct Node{
  ElementType item;
  NPtr next;
};

struct QNode{
  NPtr rear;
  NPtr front;
};

LinkedQ PtrQ;
```

ADT的操作集实现详见Queue/Linked.cpp，⚠️注意rear和front与List/LinkedL中的Head一致都是指向内容的指针。

运行指令：

```bash
g++ LinkedQ.cpp -o LinkedQ.out
./LinkedQ.out
```

### 队列应用：多项式加法运算

先咕



