#include <iostream>
#include <cstdio>

#define MAXSIZE 10

typedef int ElementType;
typedef struct LNode *List;
struct LNode
{
    ElementType data;
    List next;
};
List Head;

// 不需要MakeEmpty()

int length(List head)
{
    List p = head; // 指向第一个节点，我们不希望修改Head的指向
    int j = 0;
    while (p)
    {
        p = p->next;
        j++;
    }
    return j;

    // 时间复杂度O(n)
}

List findKth(int k, List head)
{
    List p = head;
    int i = 1;
    // 不为空，且下标小于k
    while (p && i < k)
    {
        p = p->next;
        i++;
    }
    if (i == k)
        return p;
    else
        return nullptr;
}

List find(ElementType x, List head)
{
    List p = head;
    while (p && p->data != x)
        p = p->next;
    return p;
}

List insert(ElementType x, int i, List head)
{
    List p, s; // p: 第i个节点的前一个 s: 需要插入的节点
    s = new LNode;
    s->data = x;
    if (i == 1) // 在表头插入
    {

        s->next = head;
        return s;
    }
    p = findKth(i - 1, head);
    if (!p) // p为空
    {
        puts("范围错误");
        return head;
    }

    // 插入
    s->next = p->next;
    p->next = s;
    return head;
}

List remove(int i, List head)
{
    List p, s;
    if (i == 1)
    {
        s = head;
        if (head)
            head = head->next;
        free(s);
        return head;
    }
    p = findKth(i - 1, head);
    if (!p || !p->next)
    {
        puts("范围错误");
        return head;
    }

    // 删除
    s = p->next;
    p->next = s->next;
    free(s);
    return head;
}

// Debug

int rand(int lb, int ub)
{
    return (rand() % (ub - lb + 1) + lb);
}

void test(List head, List (*fp)(List head, int i), int times)
{
    int lb = 1, ub = times;
    int n = rand(lb, ub);

    int i;
    for (int j = 0; j < n; j++)
    {
        ub = length(head) + 2;
        i = rand(lb, ub);
        head = fp(head, i);
    }
}

void printList(List head)
{
    printf("LinkedL:");
    List p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

List insertTest(List head, int i)
{
    ElementType x = rand(1, 100); // 因为rand都为整数，不考虑类型转换
    printf("尝试在下标i=%d，插入X=%d\n", i, x);
    head = insert(x, i, head);
    printList(head);
    return head;
}

List deleteTest(List head, int i)
{
    printf("尝试删除下标i=%d的元素\n", i);
    head = remove(i, head);
    printList(head);
    return head;
}

int main()
{
    // test
    Head = insert(1, 1, Head);
    test(Head, insertTest, MAXSIZE + 3);
    test(Head, deleteTest, length(Head) / 2);
    return 0;
}