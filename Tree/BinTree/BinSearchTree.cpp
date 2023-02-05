#include <iostream>
#include <deque>
#include <vector>

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

Position find(ElementType &x, BinTree &bst)
{
    ElementType val;
    BinTree curr = bst;
    while (curr)
    {
        val = curr->data;
        if (val < x) // 根结点的值小于需要查找的值，则向更大的右子树去查找
            curr = curr->right;
        else if (val > x) // 同理
            curr = curr->left;
        // 找到了
        else
            return curr;
    }

    return nullptr;
}

// 最左的叶子结点是最小的
Position findMin(BinTree &bst)
{
    BinTree curr = bst;
    if (!curr)
        return nullptr;
    while (curr->left)
        curr = curr->left;
    return curr;
}

// 最右的叶子结点是最大的
// 可以尝试将两个方法合并
Position findMax(BinTree &bst)
{
    BinTree curr = bst;
    if (!curr)
        return nullptr;
    while (curr->right)
        curr = curr->right;
    return curr;
}

void insert(BinTree &bst, ElementType x)
{
    BinTree *curr = &bst;
    while (*curr != nullptr)
    {
        if (x < (*curr)->data)
            curr = &(*curr)->left;
        else if (x > (*curr)->data)
            curr = &(*curr)->right;
        else // 存在就退出
            return;
    }
    *curr = new TreeNode;
    (*curr)->data = x;
    (*curr)->left = (*curr)->right = nullptr;
}

void remove(BinTree &bst, ElementType x)
{
    // 找到x的爹和x自己
    ElementType val;
    BinTree fa, target = bst;
    while (target)
    {
        if (target->data == x)
            break;

        fa = target;
        val = target->data;
        if (val < x)
            target = target->right;
        else if (val > x)
            target = target->left;
    }

    if (!target) // 不存在
        return;

    BinTree tmp;
    if (target->right && target->left) // 同时存在左右子树
    {
        tmp = findMin(target->right);
        target->data = tmp->data;

        // 右子树最小的结点，只可能有右结点或者没有结点
        if (tmp->right)
        {
            tmp->data = tmp->right->data;
            free(tmp->right);
            tmp->right = nullptr;
        }
        else
            free(tmp);
    }
    else // 存在左子树或者右子树，或者一个都没有
    {
        tmp = !target->left ? target->right : target->left;
        if (!fa) // target为根结点
        {
            BinTree *dog = &bst;
            *dog = tmp;
        }
        else if (fa->left == target)
            fa->left = tmp;
        else if (fa->right == target)
            fa->right = tmp;
        free(target);
    }
}

int randi(int lb, int ub)
{
    return rand() % (ub - lb + 1) + lb;
}

bool randBoolean()
{
    return (rand() % 10) <= 4;
}

void print(BinTree root)
{
    puts("打印结果：");
    std::deque<BinTree> q;
    if (!root)
        return;

    size_t n;
    BinTree curr;
    q.push_back(root);
    while (!q.empty())
    {
        n = q.size();
        for (size_t i = 0; i < n; i++)
        {
            curr = q.front();
            q.pop_front();
            printf("%d ", curr->data);
            if (curr->left)
                q.push_back(curr->left);
            if (curr->right)
                q.push_back(curr->right);
        }
        printf("\n");
    }
}

void test(BinTree &bst, size_t size)
{
    std::vector<int> items;
    // generate
    int item;
    for (size_t i = 0; i < size; i++)
    {
        item = randi(0, 100);
        insert(bst, item);
        items.push_back(item);
    }
    print(bst);

    for (size_t i = 0; i < size; i++)
    {
        if (randBoolean())
        {
            item = items[randi(0, items.size())];
            printf("尝试删除: %d\n", item);
            remove(bst, item);
            print(bst);
        }
    }
}

int main()
{
    test(Root, 10);
    return 0;
}