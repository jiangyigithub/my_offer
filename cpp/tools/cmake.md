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