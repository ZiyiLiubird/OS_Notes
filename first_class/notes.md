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

gcc -c {{source.c}} Compile source code without linking.

