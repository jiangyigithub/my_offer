Targets and Properties,Imagine Targets as Objects

https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/

## • Constructors:
• add_executable()
• add_library()

## • Member variables:
• Target properties (too many to list here).

## • Member functions:
• get_target_property()
• set_target_properties()
• get_property(TARGET)
• set_property(TARGET)
• target_compile_definitions()
• target_compile_features()
• target_compile_options()
• target_include_directories()
• target_link_libraries()
• target_sources()



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

集成VFC
https://inside-docupedia.bosch.com/confluence/display/CCDAEHS/Integration+of+VFC+library

集成GTEST
https://github.com/google/googletest/tree/main/googletest
https://inside-docupedia.bosch.com/confluence/display/CCDAEHS/Integration+of+GoogleTest
https://www.youtube.com/watch?v=Lp1ifh9TuFI

good article
http://derekmolloy.ie/hello-world-introductions-to-cmake/#Introduction

头文件Include
https://www.jianshu.com/p/e7de3de1b0fa
https://zhuanlan.zhihu.com/p/82244559

Effective Modern CMake
https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
https://raw.githubusercontent.com/boostcon/cppnow_presentations_2017/master/05-19-2017_friday/effective_cmake__daniel_pfeifer__cppnow_05-19-2017.pdf
https://www.youtube.com/watch?v=bsXLMQ6WgIk

find_package
https://zhuanlan.zhihu.com/p/97369704

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
`add_executable`
`add_library`


`target_include_directories`
`target_link_libraries`

obsolete
`include_directories`

### 涉及到其他的第三方库，需要添加lib
1. 第三方库打包成lib
   `file`  
   `find_package`

### 怎么处理测试代码(link 单元测试库，生成)

### advanced
1. solution 1 --> multi CMakeList.txt
`add_subdirectory`
`CMakeLists.txt`

2. solution 2 --> .cmake 文件
`include`
`XXX.cmake`

#### function
#### macro


## DACORE 实践
1. 编写CMakeLists.txt
2. 通过python call cmake
3. 通过shell 来执行python

`target_compile_definitions`
target_compile_definitions(${PROJECT_NAME} PUBLIC USE_ROS)