# 线性结构

建议先看完多项式问题的引子

## 什么是线性表

### 定义

**线性表（Linear List）：由同类型==数据元素==构成==有序序列==的线性结构**

- **长度**：线性表中的元素个数
- **空表**：线性表中没有元素时
- **表头、表尾**：线性表的起始位置和结束位置

### ADT描述

**类型名称**：线性表（List）

**数据对象集**：线性表是$n\ge0$个元素构成的有序序列$(a_1,a_2,\dots,a_n)$

**操作集**：线性表$L\in List$，整数$i$表示位置，元素$X\in ElementType$，线性表基本操作主要有：

```c++
List makeEmpty(); // 初始化一个空线性表L
ElementType findKth(int k, List l); // 根据位序K，返回相应元素
int find(ElementType x, List l); // 在线性表L中查找X的第一次出现位置
void inser(ElementType x, int i, List l); // 在位序i前插入一个新的元素X
void remove(int i, List l); // 删除指定位序i的元素
int length(List l); // 返回线性表L的长度n
```

### 物理存储实现

1. **顺序存储**

![List](https://github.com/Wishrem/Data-Structure/blob/main/Linear/img/List.png)

**利用数组的==连续存储空间顺序存放==线性表的各元素**

```c++
typedef struct LNode *List;
struct LNode{
  ElementType data[MAXSIZE]; // ElementType 需要typedef定义，这里没写
  // MAXSIZE 需要define定义，这里没写
  int last; // 需要知道最后一个元素的位置，可判断是否装满，或者在查找的时候防止越界
};
List PtrL; // List Pointer
```

ADT的操作集实现详见List/List.cpp，⚠️注意实际代码中的下标是从i=0开始，而在ADT描述中下标是从i=1开始

运行指令：

```bash
g++ List.cpp -o List.out
./List.out
```



2. **链式存储**

![LinkedL](https://github.com/Wishrem/Data-Structure/blob/main/Linear/img/LinkedL.png)

**==不要求逻辑上相邻的两个元素物理上也相邻==；通过“链”建立起元素之间的逻辑关系。**

```c++
typedef struct LNode *List;
struct LNode{
  ElementType data;
  List next; // 下一个元素的指针
};
List Head;  // 指向第一个元素
```

ADT的操作集实现详见List/LinkedL.cpp，⚠️注意Head是指向的是第一个指针，并没有创建一个而外的空结点。

运行指令：

```bash
g++ LinkedL.cpp -o LinkedL.out
./LinkedL.out
# 运行时会有感觉比顺序存储慢一些，这个是因为有大量申请和删除空间操作，还有求长度操作
```

插入操作：

![LinkedL Insert](https://github.com/Wishrem/Data-Structure/blob/main/Linear/img/LinkedLInsert.png)

删除操作：

![LinkedL Delete](https://github.com/Wishrem/Data-Structure/blob/main/Linear/img/LinkedLDelete.png)

3. **广义表**

建议先观看讲解例子的视频

> 例1：我们知道了一元多项式的表示，那么二元多项式又该如何表示？比如，给定二元多项式：$P(x,y)=9x^{12}y^2+4x^{12}+15x^8y^3-x^8y+3x^2$

*只要能将二元多项式泛化到其他问题中即可尝试使用广义表。*



- **广义表是==线性表的推广==；**
- **对于线性表而言，$n$个元素都是基本的==单元素==；**
- **广义表中，这些元素不仅可以是单元素也可以是==另一个广义表==。**

```c++
typedef struct GNode *GList; // Generalized List
struct GNode{
  int tag; // 标志域：0表示结点是单元素，1表示结点是广义表
  union{	// 子表指针域SubList与单元素数据域Data复用，即共用存储空间
    ElementType data;
    GList subList;
  }URegion;
  GList next; // 指向后继结点
};
```

例子代码实现待施工

4. **多重链表**

建议先观看讲解例子的视频

> 例2:

![Multiple Linked List](https://github.com/Wishrem/Data-Structure/blob/main/Linear/img/MultipleLinkedList.png)

- **链表中的结点可能同时隶属于多个链；**
- **多重链表中结点的==指针域会有多个==，如前面广义表中包含了Next和SubList两个指针域；**
- **但包含两个指针域的链表并不一定是多重链表，比如在==双向链表不是多重链表==。**

可以运用于构建树和图

例子代码实现待施工
