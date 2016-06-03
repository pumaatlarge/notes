#Python study

---

[廖雪峰网站](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000) python 学习

##python 基础知识
1. 转义字符， 用 `r''` to `''` 表示内部不用转义。
2. 用`'''` 到 `'''`代替`\n`
3. 在计算机内存中，统一使用Unicode编码，当需要保存到硬盘或者需要传输的时候，就转换为UTF-8编码。
4. `str`和 `bytes`
5. list and tuple:  list 可变 使用 中括号：`append`, `insert`, `pop`， tuple 使用 小括号 元素不可变， 但是元素指向的对象可变。
6. dict and set: dict 使用 大括号， use `in` or `get` 方法判断key是否在dict中，`pop(key)`删除。 key必须为不可变元素。 set 为 key 的集合， 具有唯一性。 `add(key)`, `remove(key)`.

#function
1. `use help(function)` 来学习使用具体的函数
2. use `pass` 作为占位符
3. an example to generate error

  ``` python
  def my_abs(x):
    if not isinstance(x, (int, float)):
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x
  ```
4. 可以返回多个值， 实际上是返回含多个值的tuple

5. 默认参数之大坑 
> Python函数在定义的时候，默认参数L的值就被计算出来了，即[]，因为默认参数L也是一个变量，它指向对象[]，每次调用该函数，如果改变了L的内容，则下次调用时，默认参数的内容就变了，不再是函数定义时的[]了。
=======

# 高级特性
1. 切片 slice 正向 反向都可以， 注意反向的第一个元素是-1  ( I feel better than substring method in java and C#).
  ```
  >>> 'ABCDEFG'[::2]
  'ACEG'
  ```
2. 迭代， 通过`for ... in`来完成。 默认情况下，dict迭代的是key。如果要迭代value，可以用`for value in d.values()`，如果要同时迭代key和value，可以用`for k, v in d.items()`.  判断对象是否可迭代：`isinstance('abc', Iterable)`.   Python内置的enumerate函数可以把一个list变成索引-元素对，这样就可以在for循环中同时迭代索引和元素本身：
3. List comprehensions, 列表生成式， 使用`[]`
4. generator 生成器 ， 使用`()`或者在函数中用`yield`命令，这里generator和函数的执行流程不一样。函数是顺序执行，遇到return语句或者最后一行函数语句就返回。而变成generator的函数，在每次调用`next()`的时候执行，遇到yield语句返回，再次执行时从上次返回的yield语句处继续执行。但是用for循环调用generator时，发现拿不到generator的return语句的返回值。如果想要拿到返回值，必须捕获StopIteration错误，返回值包含在`StopIteration`的value中    quiz: 用generator 和list comprehensions 打印杨辉三角的值
5. iterator 和 iterable  

  > * 凡是可作用于for循环的对象都是Iterable类型；
  > * 凡是可作用于next()函数的对象都是Iterator类型，它们表示一个惰性计算的序列；
  > * 集合数据类型如list、dict、str等是Iterable但不是Iterator，不过可以通过iter()函数获得一个Iterator对象。
  

# 高阶函数

1. `map`函数接收两个参数，一个是函数，一个是`Iterable`，`map`将传入的函数依次作用到序列的每个元素，并把结果作为新的`Iterator`返回。

2. `reduce`把一个函数作用在一个序列[x1, x2, x3, ...]上，这个函数必须接收两个参数，`reduce`把结果继续和序列的下一个元素做累积计算，
3. `filter()`把传入的函数依次作用于每个元素，然后根据返回值是True还是False决定保留还是丢弃该元素。

4. `sorted()`函数也是一个高阶函数，它还可以接收一个key函数来实现自定义的排序，例如按绝对值大小排序

5. 函数作为返回值： 高阶函数除了可以接受函数作为参数外，还可以把函数作为结果值返回。  我们在函数`lazy_sum`中又定义了函数`sum`，并且，内部函数`sum`可以引用外部函数`lazy_sum`的参数和局部变量，当`lazy_sum`返回函数sum时，相关参数和变量都保存在返回的函数中，这种称为“闭包（Closure）”的程序结构拥有极大的威力。  返回闭包时牢记的一点就是：返回函数不要引用任何循环变量，或者后续会发生变化的变量
6. decorator:   every object has a property `_name_`; 本质上，decorator就是一个返回函数的高阶函数; wrapper()函数的参数定义是`(*args, **kw)`，因此，`wrapper()`函数可以接受任意参数的调用。不需要编写`wrapper.__name__ = func.__name__`这样的代码，Python内置的`functools.wraps`就是干这个事的
 
7. partial function: 当函数的参数个数太多，需要简化时，使用`functools.partial`可以创建一个新的函数，这个新函数可以固定住原函数的部分参数，从而在调用时更简单。