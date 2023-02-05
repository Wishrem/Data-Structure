# 树状结构

## 什么是二叉树

### 定义

**二叉树（$T$）：一个有穷的结点集合**

- **集合可以为空**
- **非空则它是由根结点和称为其左子树$T_L$和右子树$T_R$的两个不相交的二叉树组成**

五种基本状态

![Binary Tree Status]()

### 重要性质

1. **第$i$层的最大结点数为：$2^{i-1},i\ge1$**
2. **深度为$k$的二叉树有最大结点总数为：$2^k-1,k\ge1$**
3. **对任何非空二叉树$T$，若$n_0$表示叶结点的个数、$n_2$是度为2的非叶结点个数，那么两者满足关系$n_0=n_2+1$**

### ADT描述

**类型名称**：二叉树（Binary Tree）

**数据对象集**：一个有穷的结点集合。若不为空，则由根结点和其左、右二叉树组成。

**操作集**：$BT\in BinTree,Item\in ElementType$

```c++
bool isEmpty(BinTree bt);	// 判别BT是否为空
void Traversal(BinTree bt);	// 遍历，按某顺序访问每个结点
BinTree createBinTree();	// 创建一个二叉树

// 遍历
void preOrderTraversal(BinTree bt); // 先序：根左右
void inOrderTraversal(BinTree bt);	// 中序：左根右
void postOrderTraversal(BinTree bt);	// 后序：左右根
void levelOrderTraversal(BinTree bt);	// 层次：上到下，左到右
```

### 物理存储实现

1. **顺序存储**

![BinTree]()

~~实际运用较少~~

2. **链表存储**

```c++
typedef struct TreeNode *BinTree;
struct TreeNode{
  ElementType data;
  BinTree left;
  BinTree right;
};

BinTree Root;
```

ADT的操作集实现详见BinTree/BinTree1.cpp和BinTree/BinTree2.cpp，前者为递归版本的遍历，后者为非递归版本的遍历

### 遍历二叉树的应用

1. **输出叶子结点**

fn方法

```c++
void printLeaves(BinTree node){
  if(!node->left && !node->right)
		std::cout<<node->data<<" ";
}
```

2. **求二叉树的高度**

```c++
int height(BinTree root){
	if (!root)
    return 0;
  int HL, HR, MaxH;
  HL = height(root->left);
  HR = height(root->right);
  MaxH = HL > HR ? HL : HR;
  return MaxH+1;
}
```

3. **二元运算表达式树及其遍历**

   ![BinTree eg3]()

4. **由两种遍历序列确定二叉树**

**没有中序不能确定**
