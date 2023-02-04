# 线性结构

建议先看完算数表达式的引子

## 什么是堆栈

### 定义

**堆栈（Stack）：具有一定操作约束的线性表，只在一端（栈顶，Top）做==插入、删除==**

### ADT描述

**类型名称**：堆栈（Stack）

**数据对象集**：一个有0个或多个元素的有穷线性表

**操作集**：长度为$MaxSize$的堆栈$S\in Stack$，堆栈元素$item\in ElementType$

```c++
Stack CreateStack(int MaxSize); // 生成空堆栈，其最大长度为MaxSize
bool IsFull(Stack S, int MaxSize); // 判断堆栈S是否已满
void Push(Stack S, ElementType item); // 将元素item压入堆栈
bool IsEmpty(Stack S); // 判断堆栈S是否为空
ElementType Pop(Stack S); // 删除并返回栈顶元素
```

**具有后入先出（LIFO）的特点**

### 物理存储实现

1. **顺序存储**

**由一个==一维数组==和一个记录==栈顶==元素位置的变量组成**

![Stack]()

```c++
typedef struct SNode *Stack;
struct SNode{
  ElementType Data[MaxSize];
  int Top; // 指向当前栈顶元素，即从-1开始；若从0开始，则指向栈顶的上一个位置
};

Stack PtrS;
```

ADT的操作集实现详见Stack/Stack.cpp，⚠️这里Top是从-1开始

~~太简单没有运行指令~~

> 例1:请用一个数组实现两个堆栈，要求最大地利用数组空间，使数组只要有空间入栈操作就可以成功。

![Eg1]()

```c++
typedef struct SNode *DStack; // Double Stack
struct SNode{
  ElementType Data[MaxSize];
  int Top1;
  int Top2;
};

DStack PtrS;
PtrS->Top1=-1;
Ptrs->Top2=MaxSize;
```

样例实现详见Stack/Eg1.cpp

~~太简单没有运行指令~~

2. **链式存储**

![LinkedS]()

**由一个==单链表==和==Top==指针构成，叫做==链栈==**

```c++
typedef struct SNode *LinkedS; // Linked Stack
struct SNode{
  ElementType Item;
  LinkedS Next;
};

LinkedS Top;	// 始终指向链表头
```

ADT的操作集实现详见Stack/LinkedS.cpp，⚠️注意这里的Top指针是空的LinkedS和LinkedL中的Head不一样。*严格上来说不能算作指针，算作是指向表头元素的空结点。*

~~太简单没有运行指令~~

### 堆栈应用：中缀表达式求值

先转成后缀表达式，再进行计算



1. **转为后缀表达式**

具体算法：

**从左到右读取==中缀表达式的每个对象==，对不同对象按不同的情况处理。**

- **运算数**：直接输出
- **左括号**：压入堆栈
- **右括号**：将==栈顶的运算符弹出==并==输出==，==直到遇到左括号==（左括号出栈，但不输出；右括号不入栈也不输出）
- **运算符**：
  - 若==优先级大于栈顶运算符==时，则把它==压入堆栈==；
  - 若==优先级小于等于栈顶运算符==时，将==栈顶运算符弹出并输出==；再比较新的栈顶运算符，直到该运算符大于栈顶运算符优先级为止，然后将该==运算符压入堆栈==；
- **若各对象==处理完毕==，则把堆栈中存留的==运算符一并输出==**。

2. **后缀表达式计算**

具体算法（个人表述）：

**从左到右读取==后缀表达式的每个对象==，对不同对象按不同的情况处理。**

- **运算数**：压入堆栈
- **运算符**（opt）：从堆栈中==先弹出一个运算数b==，再从堆栈中==弹出一个运算数a==，==计算a opt b后再次压入堆栈==
- **若各对象==处理完毕==，==最终结果为栈顶元素==**

应用实现详见Stack/Calc.cpp

运行指令：

```bash
g++ Calc.cpp -o Calc.out
./Calc.out [任意表达式]
# *为乘号，/为除号，+-为加和减，左右括号注意为半角符号，没有大括号和花括号的设定，可以为小数
# 1*(3+4/(2+5))
# >>> 3.57143
```

