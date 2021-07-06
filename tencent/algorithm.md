# 算法
若想按部门/难度/题型筛选题目，请进入[CodeTop](https://codetop.cc)查询
|题目|出现次数|链接|comment|
|-|-|-|-|
|206. 反转链表|5|https://leetcode-cn.com/problems/reverse-linked-list|一开始的想法是把最后一个作为链表的开头，不断调用这个函数，使得被reverse的部分越来越长。查看题解是从头到尾一个个的调正确，即第一个被翻转过来的就是原来的开头，维护一个before变量，使得当前的next有所指，并且可以根据没变的next找到以前的下一个|考虑第i个元素时，考虑的是第i-1或i-1与之前（连续的）若干个最好可以提供多少（可能是负），负的话不要前面的了|
|53. 最大子序和|4|https://leetcode-cn.com/problems/maximum-subarray|得关注本质，因为是连续的，只需要考虑：如果考虑上一个（或者再加上上一个或者更之前的带来的效益）是否大于0，不是则只考虑本身，并维护一个max值|
|1143. 最长公共子序列|3|https://leetcode-cn.com/problems/longest-common-subsequence|结合具体例子来考虑（2021.5.16第一次做，隔段时间还需要再回顾）|
|442. 数组中重复的数据|2|https://leetcode-cn.com/problems/find-all-duplicates-in-an-array|完全没思路，第一反应就是排序，看了题解之后发现答案和题设有密切关系,可以巧妙地设立一些标注。|
|300. 最长上升子序列|2|https://leetcode-cn.com/problems/longest-increasing-subsequence|自己想的，用两个数组dp|
|8. 字符串转换整数 (atoi)|2|https://leetcode-cn.com/problems/string-to-integer-atoi|看了别人的题解才知道int会溢出时可以用longlong，而且c++里定义了INT_MAX和INT_MIN常量|
|215. 数组中的第K个最大元素|2|https://leetcode-cn.com/problems/kth-largest-element-in-an-array|快排现在只是用例子验证了princeton的代码的正确性，即：while(true),i、j开始时是lo+1和high，碰到左面大于partition，右面大于partition的交换（等于也都需要交换？），如果i>=j（等于也算），则退出while，lo与j交换(等于时退出循环可以由“10”这个例子知道有效性，最后ij均是1，退出循环，partition元素1与0交换)，但是具体大于/等于号的设定不是特别确定  复制了quicksort的代码修改了一下
|121. 买卖股票的最佳时机|2|https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock|自己只能想到暴力解法，维护一个目前最便宜值就能从n^2变成n|
|141. 环形链表|1|https://leetcode-cn.com/problems/linked-list-cycle|自己想了比较久才想到通过改值的方式标志已经去过一个节点，但好像有点投机取巧，实现一下官方题解的快慢指针|
|21. 合并两个有序链表|1|https://leetcode-cn.com/problems/merge-two-sorted-lists|一开始想的这种方法没有利用到现有两个linked list的空间，浪费空间，想想怎么利用；in place的会了|
|494. 目标和|1|https://leetcode-cn.com/problems/target-sum|将每一个数是加正号还是负号的问题转换为挑出若干个数，它们和一定，将这些数添负号，其余数都是正号。既可以使用二维vector也可以使用一维来实现，一维更省空间|
|227. 基本计算器 II|1|https://leetcode-cn.com/problems/basic-calculator-ii|计算器的四则运算也忘了...维护一个pre op，这样pre op是*时，取栈顶以及当前元素做乘法  题目的各种用例corner case之前还是理解的不仔细，【6.20做的，过几天再试一试】|
|72. 编辑距离|1|https://leetcode-cn.com/problems/edit-distance|通过了，但是一会儿还得再看，用一些具体的例子来考虑【6.20做的，过几天再试一试】|
|633. 平方数之和|1|https://leetcode-cn.com/problems/sum-of-square-numbers|自己完全没思路，只能想到暴力解法【还需要看】|
|125. 验证回文串|1|https://leetcode-cn.com/problems/valid-palindrome|isalnum()和tolower()Api的用法，跳过不关注的字符，注意左右指针只要相交或重合了就算是回文【还需要看】|
|152. 乘积最大子数组|1|https://leetcode-cn.com/problems/maximum-product-subarray|动态规划的题一上来感觉无从下上，但仔细想想和“和最大子数组”有相似之处|
|15. 三数之和|1|https://leetcode-cn.com/problems/3sum|先看了two sum，没想到把已经扫过的东西存在map里，另外不知道c++里unordered_map和map在效率上有什么区别和优劣。3sum这道题提醒了一定要注意sort带来的优势（有时候不明显）|
|105. 从前序与中序遍历序列构造二叉树|1|https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal|自己想的是笨的方法，需要每次构造四个新vector.因为是&引用，所以也可以用index，以及使用unordered_map|
|148. 排序链表|1|https://leetcode-cn.com/problems/sort-list|先做了链表“插入排序”：https://leetcode-cn.com/problems/insertion-sort-list/，自己想的方法做了两个多小时才通过，是复杂的，同时也因为自己对在链表中插入一项的不熟练。看了官方题解，理解了dummyHead带来的便利，而且只需prev无需cur，这种情况下要注意corner case，比如空的输入，还有prev一直到最后一项，这样的情况下prev->next->val都是有问题的【下次还得再看看】
对于归并排序，之前瞅了一下题解自己实现出来了，但是快慢指针可能效率有点低下，官方给的solution是通过tail来比较是否到尾巴，不需要多次判别next。再稍微想一想之后，发现tail不光用来while少判断，而且还是避免了分成两个链表是需要“真正”分成两个，而是只用标注就好，tail并不是真正的tail，而是已经到第二个了或者null【下次重新想】|
|239. 滑动窗口最大值|1|https://leetcode-cn.com/problems/sliding-window-maximum|
|22. 括号生成|1|https://leetcode-cn.com/problems/generate-parentheses|
|75. 颜色分类|1|https://leetcode-cn.com/problems/sort-colors|
|20. 有效的括号|1|https://leetcode-cn.com/problems/valid-parentheses|
|169. 多数元素|1|https://leetcode-cn.com/problems/majority-element|
|171. Excel表列序号|1|https://leetcode-cn.com/problems/excel-sheet-column-number|
|5. 最长回文子串|1|https://leetcode-cn.com/problems/longest-palindromic-substring|
|43. 字符串相乘|1|https://leetcode-cn.com/problems/multiply-strings|
|63. 不同路径 II|1|https://leetcode-cn.com/problems/unique-paths-ii|
|146. LRU缓存机制|1|https://leetcode-cn.com/problems/lru-cache|
|补充题6. 手撕堆排序|1|https://leetcode-cn.com/problems/sort-an-array|很慢，不知道问题在哪里？|
|160. 相交链表|1|https://leetcode-cn.com/problems/intersection-of-two-linked-lists|
|补充题4. 手撕快速排序|1|https://leetcode-cn.com/problems/sort-an-array|增加了排序前shuffle，不然完全有序或者反序的复杂度很高[但是内存/速度都是只超过20%，不知道问题在哪里？]|
|113. 路径总和 II|1|https://leetcode-cn.com/problems/path-sum-ii|
