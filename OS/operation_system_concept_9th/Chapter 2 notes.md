# Chapter 2 Operating-System Structures
----


##2.3 System calls
 
- Application programming interface
  1. Windows API
  2. POSIX API (library is called `libc`
  3. Java API
 
- two ways to invoke system call
  1. directly: invoke actual system call
  2. indirectly: through API
  
- Three general methods to pass parameters to system
  1. simplest : to pass the parameters in registers
  2. parameters are stored in block, table in memory, the address of the block is passed as a parameters in registers (Linux and Solaris)
  3. parameters are stored in stack
  
##2.4 Types of System Calls

- 6 major categories:

 |                         | Windows                         | Unix       |
 | ------------------------| -------------------------------:| :---------:|
 |Process control          | CreateProcess()                 | fork()     |
 				           | ExitProcess()                   | exit()     |
                           | WaitForSingleObject()           | wait()     |
 |File manipulation        | CreateFile()                    | open()     |
                           | ReadFile()                      | read()     |
                           | WriteFile()                     | write()    |
                           | CloseHandle()                   | close()    |
 |Device manipulation      | SetConsoleMode()                | ioctl()    |
                           |ReadConsole()                    | read()     |
                            |WriteConsole()                  | write()    |
 |Information Manipulation | GetCurrentProcessID             | getpid()   |
                           | SetTimer()                      | alarm()    |
                           | Sleep()                         | sleep()    |
 |Communication            | CreatePipe()                    | pipe()     |
                           | CreateFileMapping()             | shm_open() |
                           | MapViewOfFile()                 | mmap()     |
 |Protection               | SetFileSecurity()               | chmod()    |
                           | InitlializeSecurityDescriptor() | umask()    |
                           |SetSecurityDescriptorGroup()     | chown()    | 
 
- process control
  - end, abort
  - load, execute
  - create process, terminate process
  - get process attributes, set process attributes
  - wait for time
  - wait event, signal event
  - allocate and free memory
  
- File Management
  - Create file, delete file
  - open, close
  - read write, reposition
  - get file attribute, set file attribute
  
- Device management

  - request device, release device
  - read write, reposition
  - get device attribute, set device attribute
  - logically attach or detach device
  
- Information maintenance
  - get time or date, set time or date
  - get system data, set system data
  - get process, file, or device attribute
  - set process, file, or device attribute
  
- Communication (Message passing and share memory)
  - create, delete communication connection
  - send, receive message
  - transfer status information
  - attach or detach remote device
  

- Protection
   - set_permission, get_permission
   - allow_user, deny_user

#2.5 System Programs

  - File management
  - Status information
  - File modification
  - Programming-language support
  - Program loading and execution
  - Communications
  - Background
 
#2.6 Operation-System Design and Implementation
 - Design Goals: user goals and system goals. There is no unique solution to define these goals.
 - Mechanisms: *how* to do something
 - policies: *what* will be done
 - mechanisms and policies need to be separated.

#2.7 Operating-SYstem structure

  - Layered approach
    - pro: simplicity of constructing and debugging
    - con: Hard to define layers; less efficient
  - Microkernels
    - **Mach** from Carnegie Mellon
    - communication through message passing
    - Pro: extensibility, more security and liability
    - Con: less efficient
  - Modules
    - loadable kernel modules
    - similar to layered system, but more flexible
    - similar to microkernel, but more efficient for no need of message passing.
    - 3 hybrid operating system: Mac OS X, iOS, Android
    
#2.8 Operating-System debugging
  - *core* and *core dump* 
  - *crash* and *crash dump*
  - performance tuning. *trace listing*
  - **DTrace**: on *Solaris* system. `D` Programming language, Lines ending with `U` are executed in user mode, and lines ending in `K` in kernel mode.   
  - **DTrace** is composed of a compiler, a framework , provider of `probes` written within that framework, and `consumers` of `probes`
  - `consumer` is code that is interested in `probes` and `results`. Within the kernel, actions called `enabling control blocks`, or ECBs, are performed when probes fire.
  
#2.9 Operating-System generation

 `system generation SYSGEN`: a process the system configure or generate for each specific computer site