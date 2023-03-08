# 什么是操作系统

一种架构，用于：

管理软硬件资源，**为程序提供服务的程序**。管理软件的软件；

狭义的操作系统（本门课）：

- 对单一计算机硬件系统作出抽象、支撑程序执行的软件系统

1960s的计算机：

- 内存更大，可以同时把多个程序装入内存
  - 有了多进程的概念；当多个程序载入内存时，不同程序的内存需要彼此隔离开；
  - 进程在执行IO时，可以将CPU让给另一个进程
    - 在多个地址空间隔离的程序之间切换
    - 虚拟存储使一个程序出bug不会crash整个系统
- 操作系统自然的增加了进程管理API

1970s的计算机：与今天的计算机差别不大

---
理解操作系统：三个根本问题

1. 操作系统服务谁？
   1. 程序
   2. 课程涉及：多线程Linux应用程序
2. 操作系统为程序提供什么服务？（应用视角）
   1. 操作系统=对象+API
   2. 课程涉及：POSIX + 部分Linux特性
3. 如何实现操作系统提供的服务？
   1. 操作系统=C程序
      1. 完成初始化后就成为interrupt/trap/fault/handler
   2. 课程涉及：xv6，自制迷你操作系统

补基础...

---

## OSTEP preface, chapter1 and chapter2

three easy pieces refers to: virtualization, concurrency, and persistence. 虚拟化、并发、持久性。

理解OS是怎样工作的，包括它如何决定CPU接下来要执行哪一个程序，它怎样处理虚拟内存系统中的内存负载，虚拟机监视器如何工作，如何管理磁盘上的信息，如何去构建一个分布式系统。

there is a body of software, in face, that is responsible for making it easy to run programs (even allowing you to seemingly run many at the same time), allowing programs to share memory, enabling programs to interact with devices, and other fun stuff like that. That is Operate System.

操作系统确保系统能够正确和高效的运行，实现这一点的主要方式是通过一种通用的技术，叫做虚拟化virtualization。具体来说，OS将物理资源，例如处理器、内存、磁盘转化为更通用、强大和易用的虚拟形式。因此我们时常称OS为虚拟机。

为了让用户能够告诉操作系统要做什么，OS同时提供了API接口供用户调用。

---

## 计算机系统基础习题课

- 编译、链接: g++ Main.cpp
  - 预编译 -> 编译 -> 汇编 -> 链接 -> a.out
- 加载执行
  - ./a.out

g++ -c {{source.c}} Compile and assemble source code without linking.

g++ -S Compile only; do not assemble or link.

g++ -E Preprocess only; do not compile, assemble or link.

### 预编译

```c++
#include <stdio.h> //
#include "stdlib.h"
```

### 指针

指针本质上是地址，指向内存中的一片区域；从表面看，指针是一个整数，这个整数的指针指向的内存地址；我们在c++程序中创建的所有变量都有地址，可以通过指针获取这个地址；指针的类型有助于借助指针读写相应的内存区域；例如 int * prt 表示指针ptr指向了一片存储着int 变量的区域，四个字节空间；

```c++
#include <iostream>
#include <cstdlib>
#include <cstring>

int main()
{
    int * buffer = new int[8];
    memset(buffer, 0, sizeof(buffer));
    std::cout << "size of buffer: " << (sizeof(buffer)) << std::endl;
    for (int i = 0; i < sizeof(buffer); i++)
    {
        std::cout << buffer[i] << ' ';
    }
    std::cout << std::endl;
    delete[] buffer;
    return 0;
}
```

指针本身也是变量；所以指针本身也有地址，我们可以构建指向指针的指针，也就是它指向一个地址，这个地址又指向另一个地址；

---

### reference 引用

本质上说，指针和引用是一回事；但是引用不是变量，不需要预先创建，也不占用内存；下面看一下引用的创建方式：

```c++
#include <iostream>
#include <cstdlib>
#include <cstring>

#define Log(x) std::cout << x << std::endl;

int main()
{
    int a = 5;
    int& ref = a; // construct a reference of a;
    std::cout << "a = " << a << std::endl;
    std::cout << "ref = " << ref << std::endl;
    std::cout << "a = " << a << std::endl;
    return 0;
}
```

两种等价的方式：
```c++
#include <iostream>
#include <cstdlib>
#include <cstring>

#define Log(x) std::cout << x << std::endl;

void increment(int * value)
{
   (*value)++;
}

void increment_ref(int& value)
{
   value++;
}

int main()
{
    int a = 5;
    increment(&a);
    Log(a);
    a = 5;
    increment_ref(a);
    Log(a);
    return 0;
}
```

引用能做的事情，指针都能做；但是合理使用引用可以让语法更清晰；

