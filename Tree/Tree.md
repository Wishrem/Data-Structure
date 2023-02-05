# 树状结构

建议先看完顺序查找的引子

## 什么是树

### 定义

**树（Tree）：$n$（$n\ge0$）个结点构成的有限集合。**

- **$n=0$使，称为==空树==**
- **对于任意一颗==非空树==（$n\gt 0$），具备以下性质：**
  -  **树中有一个成为==“根”（Root）“==的特殊节点，用$r$表示；**
  - **其余结点可分为$m$（$m\gt0$）个互不相交的有限集$T_1,T_2,\dots,T_m$，其中每个集合本身又是一棵树，称为原来树的==“子树”（SubTree）==**

![Tree](https://github.com/Wishrem/Data-Structure/blob/main/Tree/img/Tree.png)

### 基本术语

1. **结点的度（Degree）**：结点的**子树个数**
2. **树的度**：树的所有**结点中最大的度数**
3. **叶结点（Leaf）**：**度为0**的结点
4. **父结点（Parent）**：有子树的结点是其子树的根结点的父结点
5. **子结点（Child）**：若A结点是B结点的父结点，则称B结点是A结点的子结点；子结点也称**孩子结点**
6. **兄弟结点（Sibling）**：具有同一父结点的各结点彼此是兄弟结点

7. **路径和路径长度**：从结点$n_1$到$n_k$的路径为一个结点序列$n_1,n_2,\dots,n_k$，$n_i$是$n_{i+1}$的父结点。路径所包含边的个数为路径的长度
8. **祖先结点（Ancestor）**：沿树根到某一结点路径上的所有结点都是这个结点的祖先结点。
9. **子孙结点（Descendant）**：某一结点的子树中的所有结点是这个结点的子孙
10. **结点的层次（Level）**：规定根结点在1层，其他任一结点的层数是其父结点的层数加1
11. **树的深度（Depth）**：树中所有结点中的最大层次是这颗树的深度

### 树的表示法

1. **儿子-兄弟表示法**

![Child-Sib](https://github.com/Wishrem/Data-Structure/blob/main/Tree/img/Child-Silb.png)

```c++
typedef struct TNode *Tree;
struct TNode{
  ElementType data;
  Tree child;
  Tree sib;
};

Tree Root;
```

~~不实现，没什么用~~
