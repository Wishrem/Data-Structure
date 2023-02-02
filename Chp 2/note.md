# 线性结构

*强烈建议先看完多项式问题的引子*

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
List MakeEmpty(); // 初始化一个空线性表L
ElementType FindKth(int K, List L); // 根据位序K，返回相应元素
int Find(ElementType X, List L); // 在线性表L中查找X的第一次出现位置
void Inser(ElementType X, int i, List L); // 在位序i前插入一个新的元素X
void Delete(int i, List L); // 删除指定位序i的元素
int Length(List L); // 返回线性表L的长度n
```

### 物理存储实现

1. **顺序存储**

![List]()

**利用数组的==连续存储空间顺序存放==线性表的各元素**

```c++
typedef struct LNode *List;
struct LNode{
  ElementType Data[MAXSIZE]; // ElementType 需要typedef定义，这里没写
  // MAXSIZE 需要define定义，这里没写
  int Last; // 需要知道最后一个元素的位置，可判断是否装满，或者在查找的时候防止越界
};
struct LNode L;
List PtrL; // Pointer List

/**用法：
* 访问下标为i的元素 PtrL->Data[i] 
* 线性表的长度 PtrL->Last+1 （从i=0开始）
*/
```

ADT的操作集实现详见List.cpp，⚠️注意实际代码中的下标是从i=0开始，而在ADT描述中下标是从i=1开始