#Operation System concepts 9th 恐龙书 notes

----

##Chapter 1 Introduction

- Operation system : kernel (System program + application program, mobile device may have middleware)
- Read only memory : ROM.;  Random access memory: RAM; electrically erasable programmable read-only
memory, EEPROM
- storage structure : register - cache - main memory - SSD ...
- I/O structure : Direct Memory Access (DMA)
- Computer system architecture: 
  1. Single processor system
  2. Multiple processor system (paralleled system or multicore system) : asymmetric multiprocessing (boss-worker) and **symmetric multriprocessing** (SMP)
  3. Clustered system : asymmetic clustering (host-standby mode), symmetic clustering (more efficiently)
  > It is important to note that while multicore systems are multiprocessor systems, not all multiprocessor systems are multicore,

- Operation System operations
  1. Dual mode and multi mode: *user mode* and *kernel mode* (*mode bit*), Virtural machine manager (VMM)
  2. Timer

- Kernel Data Structures  (ref: `<linux/list.h>, <linux/rbtree.h>`)
  1. Array
  2. List: O(n), linked list
  3. Stack:Last in, first out (LIFO)
  4. Queue: First in, first, out (FIFO)
  5. Trees
  6. Hash functions and maps
  7. Bitmaps 
    