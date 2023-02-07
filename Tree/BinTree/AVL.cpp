#include <iostream>
#include <algorithm>
#define max(x, y) (x > y ? x : y)

typedef struct TreeNode *BinTree;
typedef BinTree Position;
typedef int ElementType;
const ElementType EMPTY = -1;
struct TreeNode
{
    ElementType data;
    BinTree left;
    BinTree right;
};

BinTree Root;

// 因为平衡二叉树的深度不会很大，所以递归的开销可以忽略
// 而递归的代码十分的优雅和简单，所以使用递归实现
int height(BinTree root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int difference(BinTree root)
{
    return height(root->left) - height(root->right);
}

BinTree rr(BinTree root)
{
    BinTree tmp;
    tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

BinTree ll(BinTree root)
{
    BinTree tmp;
    tmp = root->left;
    root->left = tmp->left;
    tmp->right = root;
    return tmp;
}

BinTree lr(BinTree root)
{
    BinTree tmp;
    tmp = root->left;
    root->left = rr(tmp);
    return ll(root);
}

BinTree rl(BinTree root)
{
    BinTree tmp;
    tmp = root->right;
    root->right = ll(tmp);
    return rr(root);
}

BinTree balance(BinTree root)
{
    int bf = difference(root);
    if (bf > 1) // 说明左子树的高度大
    {
        if (difference(root->left) > 0) // 说明在左子树上
            root = ll(root);
        else
            root = lr(root);
    }
    else if (bf < -1) // 同理
    {
        if (difference(root->right) > 0) // 同理
            root = rl(root);
        else
            root = rr(root);
    }
    return root;
}

BinTree insert(BinTree root, ElementType x)
{
    if (!root)
    {
        root = new TreeNode;
        root->data = x;
        root->left = root->right = nullptr;
    }

    if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = insert(root->right, x);
    }
    return balance(root);
}

BinTree findMin(BinTree root)
{
    if (!root->right)
        return root;
}

BinTree remove(BinTree root, ElementType x)
{
    if (!root)
        return root;

    if (x < root->data)
    {
        root->left = remove(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = remove(root->right, x);
    }
    else
    {
        BinTree tmp;
        if (root->left && root->right)
        {
            tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = remove(root->right, tmp->data);
        }
        else
        {
            tmp = !root->left ? root->right : root->left;
            if (!tmp)
            {
                tmp = root;
                root = nullptr;
            }
            else
                *root = *tmp;
            free(tmp);
        }
    }

    return balance(root);
}

// 你会发现，求高度操作会使用非常多次
// 但是在插入和旋转的时候是可以对高度进行维护的
// 是否可以在TreeNode中加入一个新的height的成员
// 表示若当前结点为一个树的根，那么他的高度为多少。