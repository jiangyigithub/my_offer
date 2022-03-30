`algorithm`
`tutorials`
`demos`
`concepts`
`tools`

# methodology 
`量变引起自变`
`最小必要知识`
`二八原则` 知识点也是不平等的

1. 侯杰视频
   通过一个简单的例子将C++的知识点串起来
2. Effective C++/STL/ 
   条款法，告诉你怎么做大部分情况是对了，当然作为一本书会解释为什么是对的，但个人决定学会使用它比为什么要使用它对初学者来说更有意义，可以猜想这些条款背后可能是某个程序员写了些bug，他花费了很多时间解决了它，不仅如此他还总结了他犯错了原因，给出了下次不范这种错误的原因。
3. C++ prime
   像一本词汇书

程序和文章的区别，作家和程序员的区别，程序员按时计费，作家一份时间可以一直copy

tutorials `C++ Primer` 学习单词
instruction `Effective C++` 写作注意事项
how-tos `operation booklet` 需要但没必要死记的部分，社会中的普通人，单词中的concrete words
写程序抛开对代码的理解，还有些熟练度，工程做法等问题，这些问题往往如果长时间不接触，或时间久了，就会忘记。为了避免重复花时间在这些问题上，希望通过`how-tos`来记录。
concepts `design philosophy` 对编程语言的设计的感悟，是以一种`top-down`的视角来看待程序设计，如程序的设计范式
demos -->`practices` 范文怎么写 范文法

1. 系统设计 PER SIT RPM `现实世界的问题是什么，怎么抽象成物理问题，如何感知环境中的目标，如何定位，如何规划路径，这些都是物理问题，驾驶员模型是对人行为的抽象，所以系统设计即是将现实世界转化为物理世界和人的抽象`

2. 软件系统设计 `怎么将真实世界抽象成软件世界，软件世界是最小单元是代码，组织这些代码的是文件，文件里是类，而设计类的关系即需要设计模式，但这些是上层的设计，重要但低频率`如：runnable 中间层怎么与implement结构，UML中sequence diagram中各个对象怎么交互。

3. 数据结构和算法
`需要自定义哪些对象`

`对象里需要哪些函数`
`保证程序健壮性，需要的const,explict,private`
`多态是程序设计的硬需要`
`如果程序的顶层结构确定，设计函数就是在设计算法`

algorithm `leetcode`
tools `tool chains`



## 写程序需要的工具
`editor` -->vscode
`comment` -->doxygen
`document` -->markdown
`unit test` -->gtest pytest
`build system` -->cmake
`version control` -->git

## 写的程序怎么运行的
- 可执行文件的怎么运行在`操作系统` 多线程程序的开发
- 可执行文件之间之间怎么通信`计算机网络`