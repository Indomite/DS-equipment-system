# DS-equipment-system
 laboratory equipment management system

1.	在系统设计之前一定要想好结构体的相关内容，比如说相关的字段的类型，一些类型在使用或者判断时更加方便的情况，在设计过程中，没有考虑到字符串类型排序会很不方便，导致后续添加排序功能出现字符串排序
2.	写入文件时，为了文件的展示的美观，选择在每行数据结束之后换行，但是这导致了一个问题，就是输出的时候，由于会有换行，但是在该字符集下，空行会导致输出一堆配置变量，通过判断是否是最后一行解决该问题
3.	在程序之间调用其他的函数时，需要注意类型匹配这一问题
4.	在程序设计时，应该更多的考虑文件的分类，全都写在一个文件感觉耦合度太高，不利于文件后续的修改
5.	相关信息的格式如果能够有要求的输入应该会更好
6.	程序需要不断地修改，不断优化，精益求精



更新用户管理功能，供高级语言程序课程设计

文件将头文件拆分出来，实现代码分模块，没有那么拥挤

页面调整了一下

