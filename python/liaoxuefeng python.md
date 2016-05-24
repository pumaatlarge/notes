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
