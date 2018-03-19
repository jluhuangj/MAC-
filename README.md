# MAC-encrypt
通过绑定MAC地址，实现程序加密功能

---

1.添加.h和.cpp文件到自己的工程目录

2.查询自己的MAC地址
>* Windows：ipconfig/all
>* Linux:   ifconfig -a

3.在.h里添加下面这句话，后面这个MAC地址换成自己的MAC地址。
```c++
const std::string “自定义变量” ="54:ee:75:98:f8:b0";
```

4.在.cpp里这段话里添加刚才的变量
```c++
if (macAdd[i] == uiHelperGlobal || macAdd[i] == “刚才添加的变量”)
{
	watchVal=TRUE;
	break;
}
```
5.在自己要加密的程序里进行函数调用
>* 调用UIHelper()，实现MAC地址加密
>* 调用TimeHelper()，实现运行时间加密
