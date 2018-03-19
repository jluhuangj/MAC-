# MAC-encrypt
通过绑定MAC地址，实现程序加密功能

---

1.添加.h和.cpp文件到自己的工程目录


2.在.h里添加，这里换成自己的MAC地址。
>* Windows：ipconfig/all
>* Linux:   ifconfig -a

```c++
const std::string uiHelperGlobal ="54:ee:75:98:f8:b0";
```
 3.在.cpp里这段话里添加刚才的变量
```c++
if (macAdd[i] == uiHelperGlobal || macAdd[i] == “刚才添加的变量”)
{
	watchVal=TRUE;
	break;
}
```
4.函数调用
>* 调用UIHelper()，实现MAC地址加密
>* 调用TimeHelper()，实现运行时间加密
