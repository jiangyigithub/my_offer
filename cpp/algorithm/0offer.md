# 剑指offer
[illustration-of-algorithm](https://leetcode-cn.com/leetbook/read/illustration-of-algorithm/55bvvv/)

## 面试 
  1. 剑指offer的NB之处在于提供了一个渐进的优化解法，面试的时候可以参考，不要急于给出最优解，一步一步先给出差的解，然后次优解，最优解，并且伴随分析的过程，这样既表现了自己的算法功底，又展示了自己的现场解决问题的能力，还拖延了时间，省的答完了人家又出一个，问到不熟练的问题。

## 认识
### 数据结构
* 优先队列和堆
* 双向链表
* 平衡二叉树
* 二叉搜索树

### 算法
- 二分搜素数据结构数据结构数据结构数据结构数据结构
- 回溯法（DFS）
- BFS
- 动态规划
- 分而治之

### 对称性
- DFS和BFS
- 顺序存储和链式存储
- 自下而上（循环） 自上而下（递归）
- 实践->量变->质变->认识->实践

### 术
- 调试。循环结构和递归结构，断点法和log法，全局和细节

## 实践
### 1 数据结构
**offer 05**
**offer 06**
1. 基础： 怎么遍历链表，栈数据入栈出栈
   `C++ stack的基本用法` ,`判空 empty`,`取栈头 top`,`压栈 pop`

**offer 09**
1. 删除操作，前一步是删除操作，前一步是添加操作
2. `while` 和 `if` 的差异和共同点


### 2 查找算法

**offer 04**

- 2分查找的矩阵形式，两个方法

### 3 排序

**offer 40**

- 排序的基础操作是`交换`
- 快速排序和二份查找之间的联系

**offer 41**

- 优先队列

**offer 45**

- 重新定义数据大小的metric

**offer 61**

### 4 双指针
- 一般应用于数组，链表，字符串的题目

**offer 18**

- 链表 头节点，尾节点的特殊情况

- 链表的遍历（单指针和双指针）

- 链表的删除操作


- 链表的表示方法只用head就可以表示一个链表， （字符串和数值， 只用指针表示）

**offer 21**

- quick sort 中交换的metric, 以大小为metric，以奇偶为metric

**offer 22**

- 链表查找和链表size的关系

**offer 25**

- 链表成员val的赋值 和 指针的赋值的区别  

- if else 中都要执行的操作放在条件判断的外面

**offer 52**

- 复制链表和原链表 = copyA 和 = A

**offer 57**
- for 循环中，小于size()和小于等于size()-1 这两个边界是一致的
- 注意数值这个递增条件

**offer 58-1**

- if和 while ，只执行一次用if，可能执行多次用while

### 5 搜索与回溯算法

觉得树很难，先用分而治之的办法想想，能不能拆解为基本概念，基本性质和基本问题

- 二叉树算法的返回值特点。遍历是树转化为向量，重构是向量转为树。还可以把树直接转为另一个树
- 递归中的return 语句，如果return 整型会怎么样，return void会怎么样，函数栈怎么传递return的结果
- DFS 决策树 路径 选择列表 剪枝 回溯 

**offer 12 矩阵中的路径**

- 二维数组的遍历与多叉树的遍历的关系
- 二维矩阵的下标与树的指针，数组前后-->上下左右，双向链表pre/next-->左子树/右子树
- 顺序存储和链式存储
- k值怎么加1
- 回溯法的几个普遍问题
  - 找到一条可行路径就退出
  - 剪枝

**offer13 机器人的运动范围**

- (子问题)数位和的求法，数位增量公式
- 怎么把一个矩阵看做一个抽象的二叉树
- 显式metric1-位数和，隐式metric2-无法跨越obstacle
- dfs 和 bfs

**offer 26 二叉树的子树**

- 叶子节点和底层叶子节点的特点

- 怎么一个树是另一个树的子树

- 二叉树的遍历只能一个一个遍历，但为了缓存数据，需要将左子树或右子树缓存，

  对于深度优先（先序，中序，后序），有下层节点先与上层节点被访问，可能会用到栈

- 对于广度优先，需要用到队列

- 树的遍历中递归算法应用于查找子树

**offer 27 二叉树镜像** 

- 二叉树的镜像与层次遍历的逆序

**offer 28 对称的二叉树**

**offer 32-1**二叉树层次遍历

- 关注visit 向量和queue中存的值

- 根判空返回

  队列先进根

  循环取队头

  进值看左右

**offer 32-2** 二叉树按层打印

- queue  的size() 方法 
- 怎么知道当前遍历到哪一层

**offer 32-3** 二叉树蛇形打印

- 怎么判断在奇数层还是在偶数层
- 空层怎么保证不打印出来

**offer 34** 二叉树的路径

- vector的pop_back(),参数为void,与stack的pop()方法不同
- 树的路径搜素 -> 先序遍历的递归版本的变种

```c++
recur(root->left, tar);
recur(root->right, tar);
path.pop_back();
```

- 双重递归函数的调用顺序-->树的遍历的递归方法其实也是双重递归问题
- 递归函数后面的语句什么时候执行 recur; statement;

**? offer 36 二叉搜索树和双向链表**

- 对二叉搜素树进行中序遍历可以得到有序
- 构建链表时使用双指针
- 双向链表的定义，怎么通过一个head来表示一个双向链表

**offer 37 序列化二叉树**

- (子问题)字符串的spilit-->双指针
- 树节点的创建，new TreeNode*

**offer 38 字符串的排列**

- 全排列问题

**offer 54 二叉搜索树的第 k 大节点**

- 遍历完再取值，和边遍历边比较
- 递归中找到对应的值怎么退出递归

**offer 55a 二叉树的深度**

**offer 55b 平衡二叉树**

- 递归有返回值

**offer 64 求1到n的和**

**offer 68 最近公共祖先**

- 最近公共祖先的定义
- 最近公共祖先的情况遍历
- 与链表的公共节点的联系

### 6 分治算法

**offer 07 重建二叉树**

- 中序+先序/后序可重建，必须包含中序

- 重建二叉树关键在于怎么计算递归参数，本题中有3个递归参数:root,left,right

- 在preorder list中确定root的位置，通过root新建二叉树节点-->参数root

- 在inorder list确定左/右子树元素的数量-->参数left,right

- inorder 和 preorder里元素都是相同，重建二叉树需要同时参考这两个列表，两者关联点在于元素，所以把元素作为hashmap的key

- 右子树的根节点索引：根节点索引 + 左子树长度 + 1

- i和1在代码中分开,用index=id

  ```markdown
  先序遍历用来确定根的位置；
  中序遍历用来确定左右子树的数量；
  在递归体中，root表示根的位置in preorder；
  left和right表示左右子树的边界in inorder;
  用到了三次recur，其中参数分别表示：
  
  recur(0,0,len(inorder)-1):本句为建立整棵二叉树，pre[0]为根元素，在inorder中左边界和 右边界分别是整个数组的左右边界
  
  node.left = recur(root+1,left,i-1)：本句为建立左子树，左子树的根在整棵树根的下一个位置（在preorder中找位置）即root+1；左子树的左边界仍为原树的左边界；左子树的右边界在inorder中位于根元素位置的左侧一个，即i-1
  
  node.right = recur(i-left+root+1,i+1,right):本句为建立右子树，右子树的根的位置需要在原树根位置root的基础上加上左子树的元素个数i-left的下一位置（在preorder中找位置）,即root+(i-left)+1；右子树的右边界仍为原树的右边界；右子树的左边界在inorder中位于根元素位置的右侧一个，即i+1
  ```

**offer33 二叉搜索树的后序遍历**

- 后序遍历的特点，左子树->右子树->根，根必然是最后一个元素，设右子树的第一个元素为m，树的第一个元素为i，最后一个元素为j，这树可表示为 (左子树[i:m-1],右子树[m:j-1],根[j])
- 问题是判断是否为二叉搜索树的后序遍历，转化为问题-->判断后序遍历是否为二叉搜索树
- 递归终止条件在递归函数的最开始
- 递归参数tree,i,j

**offer 51 归并排序**

- if else 在递归类函数中的调用，不同递归层次执行的判断条件不一样

- if else 满足交换律，合并等效

- i,j双指针从两个子数组里选元素填到带排序数组中，无论哪中情况，都执行k++，将每个条件都会执行操作单独拿出来。

- 条件逻辑的总结：1递归，2条件顺序交换，3条件合并，4条件执行语句的合并

- 先考虑两个有序数组合并成一个有序数组的问题，再把问题推广到递归解法, recur body在双指针之前，二分之后

- 带返回值的递归，递归终止返回值是什么

- 条件顺序交换，先判断越界条件(不先判断会导致递归程序崩溃--> 递归对判断条件的影响)

- 测试用例中，数组有相同的元素的情况，条件中要带等号 tmp[i] <= tmp[j]

- 逆序对个数m-i+1个

### 7 动态规划

**offer 10a fib**

- fib的四种方法
  1. brute force recur
  2. recur with pruning --> time comlexity optimize
  3. convert top-down to down-top(recur-->loop)
  4. space complexity optimization for DP table
- return `pre` but not `sum`, loop boundry`(i<n)`



**offer 10b**
- different initial value

**offer 19**

**offer 42**
- 求和问题
- 动态规划的几大要素
- 代码简化
  if dp[i−1]>0
    dp[i]= dp[i−1]+nums[i]
  if dp[i−1]≤0  
    dp[i]= nums[i]​
  等价于：
  nums[i] += max(nums[i - 1], 0)


**offer 46**
**offer 47**
1. dp转移方程
if i=0,j=0
  dp(i,j)=grid(i,j)
if i=0,j/=0
  dp(i,j)=grid(i,j) + dp(i,j-1)
if i/=0,j=0
  dp(i,j)=grid(i,j)+dp(i-1,j)
if i/=0,j/=0
  dp(i,j)=grid(i,j)+max(dp(i-1,j),dp(i,j-1))
2. 一维到二维的拓展，剑指 Offer 42. 连续子数组的最大和
3. 题目中的条件，全都是正值
4. 理论上只有一个表达式 dp(i,j)=grid(i,j)+max(dp(i-1,j),dp(i,j-1))，边界项的dp(i-1,j)或dp(i,j-1)为0
5. 对矩阵中dp(i-1,j)为上边的值，dp(i,j-1)为左面的值这一点要熟悉
   上 (i-1,j)
   下 (i+1,j)
   左 (i,j-1)
   右（i,j+1)

**offer 48**
1. 双指针法
一个指针来遍历字符串，怎么决定另一个指针
2. hashmap
`find` `key`
`->second` `value`
3. 这个问题应该是这样的，j指向当前元素，当前元素和上一个当前元素之间的字符串可能为最长子序列，为保证该字符串内无重复数据，应保证左索引为max（i，s[j]上次出现的索引）
4. i 初始化为-1
5. 子问题问题是怎么确定两次重复出现字符之间的间隔
6. 空间复杂度的优化，采用buffer的形成，空间复杂度怎么降低，一块内存更新前和更新后，来实现buffer的功能

**offer 63**
- 求两个极值的差的问题
- 求数组中前m个元素的最小值 min(array[0:i])
- 暴力算法：
  1. 求数组中的最小值 min
  2. 求以最小值为左边界剩余数组中的最大值 max
  3. 最大利润为max - min


### 8  模拟
**offer29**
- 基础问题:打印一行
- 边界初值,边界更新
- 循环结束条件,边界干涉是循环结束





### 9 位运算
**offer 15 二进制中1的个数**

### 10 数学