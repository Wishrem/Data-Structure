# 图结构

## 什么是图

### 定义

**图（Graph）：包含一个顶点集合V和一个边集合E，其中顶点对$<v, w>\in E; v,w\in V$表示v指向u的一条边；不考虑重边和自回路**

### ADT描述

**数据类型**：图（Graph）

**数据对象集**：$G(V,E)$由一个非空的有限顶点集合$V$和一个有限边集$E$组成。

**操作集**：对于任意图$G\in Graph$，以及$v\in V,e\in E$

```c++
Graph create(size_t n); // 建立并返回空图
Graph insertVertex(Graph g, Vertex v); // 将v插入G
Graph inserEdge(Graph g, Edge e); // 将e插入G
void dfs(Graph g, Vertex v); // 从顶点v出发深度优先遍历图G
void bfs(Graph g, Vertex v); // 从顶点v出发宽度优先遍历图G
void shortestPath(Graph g, Vertex v, int dist[]); // 计算图G中顶点v到任意其他顶点的最短距离
void MST(Graph g); // 计算图G的最小生成树
```

### 图的表示

1. 邻接矩阵

   `G[N][N]`为二维数组，其中`N`表示顶点个数。

   `G[v][w]`表示`v`到`w`的一条有向边$e=<v,w>$，若`G[v][w]==1`，则存在有向边`e`；若`G[v][w]==0`，则不存在

2. 邻接表

`G[N]`为指针数组，其中`N`表示顶点个数，数组的每一位存储着一个链表，链表存储着顶点参数。

`G[i]`表示第`i`个顶点到链表上每一个顶点的有向边。



ADT的操作集实现详见Graph/Graph.cpp，⚠️注意实际代码用的是邻接表实现，邻接矩阵实现简单，所以不写。

## 遍历

1. DFS

```c++
void dfs(Graph g, Vertex v){
  vis[v] = true;
  for(v所相连的所有顶点u) {
    if(!vis[u])
      dfs(g, u)
  }
}
```

2. BFS

```c++
void bfs(Graph g, Vertex v){
  q = CreateQueue();
  vis[v] = true;
  Push(q, v);
  while(!Empty(q)) {
    Vertex u = Pop(q);
   	for(u所相连的所有顶点w){
      if(!vis[w])
        vis[u] = true;
        Push(q, w);
    }
  }
}
```



## 最短路径问题

### 单源最短路径

从某固定源点出发，求其到所有其他顶点的最短路径

1. 无权图

![sp1](https://github.com/Wishrem/Data-Structure/blob/main/Graph/img/sp1.png)

按照递增（非递减）的顺序找出到各个顶点的最短路

```c++
void bfs(Vertex s) {
  q = CreateQueue();
  Push(q, s);
  while(!Empty(Q)) {
    v = Pop(Q);
    for(v所相连的所有顶点w){
      if(dist[w] == -1) {
        dist[w] = dist[v] + 1;
        path[w] = v;
        Push(q, w);
      }
    }
  }
}
```

2. 有权图

按照递增的顺序找出到各个顶点的最短路

![sp2](https://github.com/Wishrem/Data-Structure/blob/main/Graph/img/sp2.png)

```c++
void djkstra(Vertex s){
	while(1) {
    v = 未收录顶点中dist最小者;
    if(v不存在) break;
    collected[v] = true;
    for(v所相连的所有顶点w) {
      if(!collected[w])
        if(dist[v]+v到w的路径长度<dist[w]) {
          dist[w] = dist[v] + v到w的路径长度;
        }
    }
  }
}
```

无法解决负环

### 多源最短路径

求任意两顶点间的最短路径

```c++
void floyd() {
	for(i=0; i<N; i++)
    for(j=0; j<N; j++)
      d[i][j] = g[i][j];
 	for(k=0; k<N; k++)
    for(i=0; i<N; i++)
      for(j=0; j<N; j++)
        if(d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
}
```

## 图中生成最小树问题

1. Prim

```c++
void prim() {
	MST = {s};
  djkstra(s);
  while(1) {
    v = 未收录顶点中dist最小者;
    if(这样的v不存在) break;
    将v收录进MST;
    dist[v] = 0;
    for (v所相连的所有顶点w)
      if (dist[w]!=0)
        if(v到w的权重<dist[w]) {
          dist[w] = v到w的权重;
        }
  }
  if (MST中收入的顶点不到|V|个)
    Error("不存在生成树"});
}
```

2. Kruskal

```c++
void Kruskal(Graph g) {
  MST = {};
  while(MST中不到|V|-1条边&&E中还有边) {
    从E中取一条权重最小的边E<v,w>；
   	将E<v,w>从E中删除;
    if(E<v,w>不在MST中构成回路)
      将E<v,w>加入MST;
    else
      丢弃E<v,w>; 
  }
}
```

## 拓扑排序

**拓扑序**：如果图中从v到w有一条有向路径，则v一定排在w之前。满足此条件的顶点序列称为一个拓扑序。

- **获取拓扑序的过程就是拓扑排序**

- AOV如果有合理的拓扑序，则必定是有向无环图

> 例：计算机专业排课

![AOV](https://github.com/Wishrem/Data-Structure/blob/main/Graph/img/AOV.png)

```c++
void topSort() {
  q = CreateQueue();
  for(图中每个顶点v)
    if(indegree[v] == 0)
      Push(q, v);
  while(!Empty(q)) {
    v = Pop(q);
    输出，或者记录v的输出序号;
    cnt++;
    for(v所相连的所有顶点w)
      if(--indegree[w]==0)
        Push(q, w);
  }
  if(cnt!=|V|)
    Error("存在回路");
}
```

