# 树状结构

## 什么是哈夫曼树

### 定义

**哈夫曼树（Huffman Tree）：WPL最小的二叉树**

**其中WPL为带权路径长度（WPL）：设二叉树有n个叶子结点，每个叶子结点，每个叶子结点带有权值$w_k$，从根结点到每个叶子结点的长度为$l_k$，则每个叶子结点的带权路径长度之和就是$WPL=\sum^n_{k=1}w_kl_k$**

大大提高了查找效率

### 哈夫曼树的构造

ADT的描述和二叉树一致

```c++
typedef struct TreeNode *Huffman;
struct TreeNode{
  int weight;
  Huffman left, right;
}

Huffman Huff;
```

构造的具体实现详见BinTree/HuffmanTree.cpp