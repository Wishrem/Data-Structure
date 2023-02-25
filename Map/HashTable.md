# 映射结构

## 什么是哈希表

### 定义

**哈希表**（HashTable，又称散列表）：一种以「key-value」形式存储数据的数据结构。所谓以「key-value」形式存储数据，是指任意的键值 key 都唯一对应到内存中的某个位置。

### ADT描述

**类型名称**：哈希表（HashTable）

**数据对象集**：哈希表是「key-value」对的集合

**操作集**：$Table\in HashTable, Key\in KeyType, Value\in ValueType$

```c++
HashTable createHashTable(int size); // 创建一个长度为size的哈希表
bool isIn(HashTable h, KeyType k); // 查找特定的Key是否在哈希表中
ValueType find(HashTable h, KeyType k); // 获取哈希表中指定Key对应的属性
HashTable modify(HashTable h, KeyType k, ValueType v); // 将哈希表中指定Key的值修改为v
HashTable insert(HashTable h, KeyType k, ValueType v); // 向哈希表中插入一个「key-value」对
HashTable remove(HashTable h, KeyType k); // 从哈希表中删除一个指定Key的「key-value」对
```

## 哈希函数

### 直接定址法

$h(key) = a\times k + b\quad(a,b为常数)$

### 除留余数法

$h(key)=key\ mod\ p\quad(p为常数，一般为素数)$

### 数字分析法

分析数字关键字在各位上的变化情况，取比较随机的位作为哈希地址

如：取11为手机号码key的后4位作为地址

$h(hey) = atoi(key+7)\quad(char *key)$

### 折叠法

把关键词分割成位数相同的几个部分，然后叠加

![Flod]()

### 平方取中法

![Square]()

### 字符关键词的哈希函数构造

1. ASCII码加和法

$h(key)=(\sum_{i=0}^{len(key)-1} key[i]) mod \ TableSize\quad(char *key)$

**冲突严重**

2. 前3个字符移位法

$hey(key)=(key[0]\times27^2+key[1]\times27+key[2])\ mod\ TableSize\\\quad(char*key)$

**仍有冲突，空间浪费**

3. 移位法

$h(key)=(\sum^{len(key)-1}_{i=0}key[len(key)-i-1]\times32^i)mod\ TableSize\\\quad(char*key)$

**分布很好**

```c++
KeyType h(const char *key, int tableSize) {
  unsigned int h = 0;
  while(*key != '\0')
    h = (h<<5)+*key++;
 	return h%tableSize;
}
```

## 冲突处理

### 开放地址法（Open Addressing）

产生了冲突（该地址已有其他元素），就按某种规则去寻找另一个空地址

规则：若发生了第$i$次冲突，试探的下一个地址将增加$d_i$，基本公式是$h_i(key)=(h(key)+d_i)mod\ TableSize\quad(1\le i\lt TableSize)$

1. 线性探测（Linear Probing）

   以增量序列$1,2,\dots,(TableSize-1)$，循环试探下一个存储地址

2. 平方探测

​		以增量序列$1^2,-1^2,2^2,-2^2,\dots,q^2,-q^2$且$q\le\left \lfloor TableSize/2\right \rfloor $循环试探下一个存储地址

### 链地址法

在同一个地址把冲突对象用链表组织起来

![Separate Chaining]()

