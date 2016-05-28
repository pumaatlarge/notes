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
  1. process control
  2. file manipulation
  3. device manipulation
  4. information maintenance
  5. communication
  6. protection
 
- process control
  - end, abort
  - load, execute
  - create process, terminate process
  - get process attributes, set process attributes
  - wait for time
  - wait event, signal event
  - allocate and free memory
  
 |                | Windows         | Unix       |
 | -------------- | ---------------:| :---------:|
 |Process control | CreateProcess() | fork()     |
 				  | 