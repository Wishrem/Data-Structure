#include <iostream>
#include <deque>

typedef struct TreeNode *BinTree;
typedef int ElementType;
const ElementType EMPTY = -1;
struct TreeNode
{
    ElementType data;
    BinTree left;
    BinTree right;
};

BinTree Root;

bool isEmpty(BinTree &root)
{
    return !root || root->data == EMPTY;
}

// 根左右，fn为访问函数，即需要做什么，可以printf也可以做其他的事，下同
void preOrder(BinTree &node, void (*fn)(BinTree))
{
    if (node)
    {
        fn(node);                  // 根
        preOrder(node->left, fn);  // 左
        preOrder(node->right, fn); // 右
    }
}

// 左根右
void inOrder(BinTree &node, void (*fn)(BinTree))
{
    if (node)
    {
        inOrder(node->left, fn);  // 左
        fn(node);                 // 根
        inOrder(node->right, fn); // 右
    }
}

// 左右根
void postOrder(BinTree &node, void (*fn)(BinTree))
{
    if (node)
    {
        postOrder(node->left, fn);  // 左
        postOrder(node->right, fn); // 右
        fn(node);                   // 根
    }
}

void levelOrder(BinTree &node, void (*fn)(BinTree))
{
    std::deque<BinTree> q; // bfs实现，用deque是因为需要它的size参数

    int n;
    BinTree tmp;
    if (node) // 开始
        q.push_back(node);
    while (!q.empty())
    {
        n = q.size();
        for (size_t i = 0; i < n; i++) // 将同一层的结点全部pop出去
        {
            tmp = q.front();
            q.pop_front();
            fn(tmp); // 访问

            // 将下一层的结点压入q中
            if (tmp->left)
                q.push_back(tmp->left);
            if (tmp->right)
                q.push_back(tmp->right);
        }
    }
}

BinTree createBinTree()
{
    BinTree root = new TreeNode;
    root->data = EMPTY;
    return root;
}