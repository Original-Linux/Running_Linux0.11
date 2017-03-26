Linux-0.11
----------------------------------------------------------------------

The legacy Linux kernel source version 0.11 which has 
been tested under modern Linux and Mac OSX.

##1. Build on Linux

### 1.1. Linux Setup

* Setup linux-0.11 dirstribution

  Recommend Ubuntu, Debian, Mint

* Tools

  Needed gcc, qemu, bochs, gdb and etc

* Release hardware image 

  A linux-0.11 hardware image file: hdc-0.11.img

  Please download it from
  ```
  http://www.oldlinux.org
  or
  http://mirror.lzu.edu.cn/os/oldlinux.org/
  ```
* Host PC

  Now, this version already support Ubuntu16.04, enjoy it.

### 1.2. hack linux-0.11

* Build Linux-0.11
  ```
make 
  ```

* Boot Linux-0.11 on qemu
  ```
make start
  ```

* Debug Linux-0.11 in GDB

  On target PC, running target image 
  ```
make debug
  ```
  On debug PC, running GDB as follow:
  ```
gdb tools/system
(gdb)target remote :1234
(gdb)b main
(gdb)c
  ```

* More help
  ```
make help
  ```
