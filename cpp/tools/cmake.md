https://inside-docupedia.bosch.com/confluence/display/CCD/CMake+--+Best+Practices
构建一个target需要哪些事情
1. 内部依赖
   - 静态链接库
   - 动态链接库

2. 外部依赖
   - 基础库 `vfc` `stl` `boost`
   - 中间层 `daddy`
   - GUI `qt5`find package
   - Unit Test `gtest`

3. target

https://zhuanlan.zhihu.com/p/119426899

selena 构建实例
- parse
- code generation

## cmake file 
file(GLOB_RECURSE XXX XXX)
add_library(XXX INTERFACE)

include_directories(
  include
)

https://inside-docupedia.bosch.com/confluence/display/CCDAEHS/Useful+Info

http://derekmolloy.ie/hello-world-introductions-to-cmake/#Introduction

https://www.jianshu.com/p/e7de3de1b0fa

Effective Modern CMake
https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1

## CMake 实践

### introduction

```c
cmake_minimum_required(VERSION 3.0.0)
project(code VERSION 0.1.0)
add_executable()
```

`set`
`message`


### 自己有多个文件，且文件分布在不同的文件夹
`include_directories`


### 涉及到其他的第三方库，需要添加lib
1. 第三方库打包成lib
   `file`  
   `find_package`

### 怎么处理测试代码(link 单元测试库，生成)

### advanced
#### .cmake 文件
#### function
#### macro