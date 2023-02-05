# 树状结构

## 什么是二叉搜索树

### 定义

**二叉搜索树（BST，Binary Search Tree）：一棵二叉树，可以为空；如果不为空，满足以下性质：**

1. **非空左子树的所有==键值小于其根结点==的键值**
2. **非空右子树的所有==键值大于其根结点==的键值**
3. **左、右子树都是二叉搜索树**

### ADT描述（自己写的）

### ADT描述

**类型名称**：二叉搜索树（BST，Binary Search Tree）

**数据对象集**：一个有穷的结点集合。若不为空，则由根结点和其左、右二叉树组成，且满足定义中的性质。

**操作集**：$BST\in BinTree,Item\in ElementType$

```c++
Position find(ElementType x, BinTree bst); // 从二叉搜索树BST中查找元素X，返回其所在结点的地址
Position findMin(BinTree bst); // 从二叉搜索树BST中查找并返回最小元素所在结点的地址
Position findMax(BinTree bst); // 从二叉搜索树BST中查找并返回最大元素所在结点的地址

BinTree insert(ElementType x, BinTree bst); // 在二叉搜索树BST中插入元素X
BinTree remove(ElementType x, BinTree bst); // 在二叉搜索树BST中删除元素X
```

物理结构和BinTree是一样的，插入操作和删除操作保证了BinTree拥有BST的性质

ADT的操作集实现详见BinTree/BinSearchTree.cpp

运行指令：

```bash
g++ BinSearchTree.cpp -o BinSearchTree.out
./BinSearchTree.out
```

