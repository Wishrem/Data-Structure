#include <iostream>
#include <queue>

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
    std::queue<BinTree> q;
    if (!node)
        q.push(node);
    BinTree curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        fn(curr);
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

BinTree createBinTree()
{
    BinTree root = new TreeNode;
    root->data = EMPTY;
    return root;
}