#include <iostream>
#include <queue>
#include <deque>
#include <vector>

typedef struct TreeNode *Huffman;
typedef int ElementType;
struct TreeNode
{
    int weight;
    Huffman left, right;
};

bool cmp(Huffman l, Huffman r)
{
    return l->weight > r->weight;
};

Huffman Huff;
/*用优先队列代替最小堆*/
std::priority_queue<Huffman, std::vector<Huffman>, std::function<bool(Huffman, Huffman)>> q(cmp);

template <typename Q>
Huffman createHuffmanTree(Q q)
{
    Huffman huff;
    while (q.size() != 1)
    {
        huff = new TreeNode;
        huff->left = q.top(), q.pop();
        huff->right = q.top(), q.pop();
        huff->weight = huff->left->weight + huff->right->weight;
        q.push(huff);
    }
    huff = q.top(), q.pop();
    return huff;
}

template <typename T>
void print(T huff)
{
    if (!huff)
        return;
    std::deque<T> q;
    q.push_back(huff);
    size_t n;
    T curr;
    while (!q.empty())
    {
        n = q.size();
        for (size_t i = 0; i < n; i++)
        {
            curr = q.front(), q.pop_front();
            std::cout << curr->weight << " ";
            if (curr->left)
                q.push_back(curr->left);
            if (curr->right)
                q.push_back(curr->right);
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

int main()
{
    const auto data = {1, 5, 2, 4, 3};
    Huffman huff;
    for (auto &x : data)
    {
        huff = new TreeNode;
        huff->weight = x;
        huff->left = huff->right = nullptr;
        q.push(huff);
    }

    Huff = createHuffmanTree(q);
    print(Huff);
    return 0;
}