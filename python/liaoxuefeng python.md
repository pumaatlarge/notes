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


##模块 Module

1. `_author_`: 标明作者
 
2.	
		if __name__=='__main__':
		test()

当我们在命令行运行hello模块文件时，Python解释器把一个特殊变量__name__置为__main__，而如果在其他地方导入该hello模块时，if判断将失败，因此，这种if测试可以让一个模块通过命令行运行时执行一些额外的代码，最常见的就是运行测试。

3. 类似`__xxx__`这样的变量是特殊变量，`__author__`, `__name__`, `__doc__`
4. 类似__xxx和___xxx这样的函数或变量就是非公开的（private），不应该被直接引用，比如`_abc`，`__abc`等；
5. Python中，安装第三方模块，是通过包管理工具`pip`完成的。


## Object oriented programming

###Encapsulation,
### inheritance, 
### polymorphism


1. class and instance: 面向对象最重要的概念就是类（Class）和实例（Instance）
 
      	class Student (object):
    		pass
		bart = Student();

2. `__init__` method, 限制属性  在class中的function第一个参数永远是`self`
3. 和静态语言不同，Python允许对实例变量绑定任何数据，也就是说，对于两个实例变量，虽然它们都是同一个类的不同实例，但拥有的变量名称都可能不同
4. 双下划线开头的实例变量是不是一定不能从外部访问呢？其实也不是。不能直接访问__name是因为Python解释器对外把__name变量改成了_Student__name，所以，仍然可以通过_Student__name来访问__name变量
5. `isinstance()`判断变量是否某个类型。 eg: `isinstance(a, list)`
6. 对于静态语言（例如Java）来说，如果需要传入Animal类型，则传入的对象必须是Animal类型或者它的子类，否则，将无法调用run()方法。
    对于Python这样的动态语言来说，则不一定需要传入Animal类型。我们只需要保证传入的对象有一个run()方法就可以了

7. `type()` 判断基本对象类型  `isinstance` 判断class类型 而且能用type()判断的基本类型也可以用isinstance()判断。 并且还可以判断一个变量是否是某些类型中的一种，比如下面的代码就可以判断是否是list或者tuple：

 		isinstance([1, 2, 3], (list, tuple))
			True
 		isinstance((1, 2, 3), (list, tuple))
			True
8. `dir`() 去获得一个对象的所有属性和方法   `getattr()`, `setattr()`, `hasattr()`
9. `__slots__`变量限制class实例能加的属性， 仅对当前类实例起作用， 对继承的子类不起作用， 除非在子类中也定义`__slots__`，这样，子类实例允许定义的属性就是自身的__slots__加上父类的__slots__。
10. `@property` 设置 setter 和 getter
11. 多重继承， 一个子类就可以同时获得多个父类的所有功能。  `Mixin` 
12. `__str__` 和 `__repr__`, `__iter__`, `__getitem__`, `__getattr__`, `__call__`和 `callable()`
13. 枚举类型， `@unique`装饰器保证没有重复值
14. `type()`可以用来返回一个对象的类型， 又可以创建新的类型
	         
    	Hello = type('Hello', (object,), dict(hello=fn)) # 创建Hello class
> 1. class的名称；
> 
> 2. 继承的父类集合，注意Python支持多重继承，如果只有一个父类，别忘了tuple的单元素写法；
> 
> 3. class的方法名称与函数绑定，这里我们把函数fn绑定到方法名hello上。

15. metalcass
   
> 但是如果我们想创建出类呢？那就必须根据metaclass创建出类，所以：先定义metaclass，然后创建类。
> metaclass是Python面向对象里最难理解，也是最难使用的魔术代码