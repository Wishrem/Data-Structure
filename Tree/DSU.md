# 树状结构

## 什么是并查集

### 定义

**并查集（Disjoint-set datastruct）**：并查集是一种用于管理元素所属集合的数据结构，实现为一个森林，其中每棵树表示一个集合，树中的节点表示对应集合中的元素。

### ADT描述

**类型名称**：并查集（Disjoint-set datastruct）

**数据对象集**：一组有穷节点的集合

**操作集**：$item\in ElementType, dsu\in Dsu$

```c++
Dsu createDsu(int size); // 创建一个大小为size的并查集
ElementType find(Dsu dsu, ElementType item); // 在并查集中查找item所属的集合
void unite(Dsu dsu, ElementType x, ElementType y); // 将并查集中x和y所属的集合合并
void remove(Dsu dsu, ElementType item); // 将并查集中item元素删除
void move(Dsu dsu, ElementType x, ElementType y); // 将并查集中x移入y所属的集合中
```

### 路径压缩

查询过程中经过的每个元素都属于该集合，可以在查询过程中更新每个元素所指向的父亲节点。

```c++
ElementType find(Dsu dsu, ElementType item) {
  return fa[item] == item ? item : fa[item] = find(fa[item]);
}
```

### 启发式合并

将深度较小的树连接到深度较大的树中。

```c++
void unite(Dsu dsu, ElementType x, ElementType y) {
  x = find(x), y = find(y);
  if (x==y) return;
  if (size(x) < size(y)) swap(x, y);
  fa[y] = x;
  size[x] += size[y];
}
```

### 删除和移动

需要保证操作的元素都是叶子，可以牺牲一定的空间制作每一个结点的副本，并将其副本作为父亲结点。

```c++
void remove(Dsu dsu, ElementType item) {
    --size[find(item)];
    fa[item] = item;
}

void move(Dsu dsu, ElementType x, ElementType y) {
  auto fx = find(x), fy = find(y);
  if (fx == fy) return;
  fa[x] = fy;
  --size[fx], ++size[fy];
}
```

