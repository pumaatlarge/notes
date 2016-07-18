#Chapter 3

--------------------------------

>   A process is the unit of work in a modern time-sharing system

## 3.1 Process Concept

1. process in memory:  stack, heap, data, text
![](http://i.imgur.com/W3FhVcK.jpg)
2. states: new, running, waiting, ready, terminated   
3. `process control block (PCB)` : process state, program counter, CPU registers, CPU-scheduling information, Memory-management information, accounting information, I/O status information
4. threads


##3.2 Process scheduling
 
1. `ready queue` and `device queue`
2. scheduler: 
	- long-term scheduler (job scheduler): control the `degree of multiprogramming`, balance the select from `I/O-bound process` and `CPU-bound process`
	- short-term scheduler(CPU scheduler): executes at least once every 100 ms
	- UNIX and Windows has no `long-term scheduler`
	- medium-term scheduler : `swapping`
	
3. context switch: switching the CPU to another process requires performing a state save of the current process and a state restoration of a different process

##3.3 Operations on processes

1. 
