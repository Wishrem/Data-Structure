#include <iostream>
#include <deque>
#include <stack>

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

/**
 * 遇到一个结点，就先访问它
 * 然后先将它的右子树压入栈，再将其左子树压入栈
 */
void preOrder(BinTree &node, void (*fn)(BinTree))
{
    BinTree curr = node; // 当前访问的结点
    std::stack<BinTree> st;
    if (curr)
        st.push(curr);
    while (!st.empty())
    {
        curr = st.top();
        st.pop();
        fn(curr);
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}
/**
 * 遇到一个结点，就把它压入栈，并去遍历它的左子树
 * 当左子树遍历结束后，从栈顶弹出这个结点并访问它
 * 然后按其右指针再去中序遍历该结点的右子树
 */
void inOrder(BinTree &node, void (*fn)(BinTree))
{
    BinTree curr = node; // 当前访问的结点
    std::stack<BinTree> st;

    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        // 左子树遍历完毕
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
            fn(curr);
            curr = curr->right; // 转向右子树
        }
    }
}

/**
 * 栈的特点是后入先出
 * st1为返回上一层的栈，st2为用于打印的栈
 * 先压入st1的最后才会被压入st2
 * 所以压入st2的顺序为根右左
 * 该算法效率不是最高的，但是最容易理解的和实现的
 */
void postOrder1(BinTree &node, void (*fn)(BinTree))
{
    BinTree curr = node; // 当前访问的结点
    if (!curr)
        return;
    std::stack<BinTree> st1,
        st2; // st2 用于倒序打印
    st1.push(curr);

    while (!st1.empty())
    {
        curr = st1.top(); // 根
        st1.pop();
        st2.push(curr); // 最先进st2最后出st2
        if (node->left) // 左 最先进st1最后出st1 也即最后进入st2
            st1.push(node->left);
        if (node->right) // 右 最后进st1最先出st1 也即第二个进入st2
            st1.push(node->right);
    }
    while (!st2.empty())
    {
        fn(st2.top()); // 左右根顺序出
        st2.pop();
    }
}

/**
 * 利用last记入最后访问的结点
 * 先遍历完左子树，然后再遍历右子树，最后访问根结点
 */
void postOrder2(BinTree &node, void (*fn)(BinTree))
{
    if (!node)
        return;
    BinTree last = node;
    std::stack<BinTree> st;
    st.push(node);

    BinTree curr;
    while (!st.empty())
    {
        curr = st.top();
        // 优先遍历完左子树
        // 最后访问的结点不是当前结点的左右子树，若是，则当前结点为根结点不应该压入
        if (curr->left && curr->left != last && curr->right != last)
        {
            st.push(curr->left); // 左
        }
        // 遍历右子树
        else if (curr->right && curr->right != last)
        {
            st.push(curr->right);
        }
        else
        {
            fn(curr);
            st.pop();
            last = curr;
        }
    }
}

void levelOrder(BinTree &node, void (*fn)(BinTree))
{
    std::deque<BinTree> q;

    int n;
    BinTree tmp;
    if (node)
        q.push_back(node);
    while (!q.empty())
    {
        n = q.size();
        for (size_t i = 0; i < n; i++)
        {
            tmp = q.front();
            q.pop_front();
            fn(tmp);
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