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
