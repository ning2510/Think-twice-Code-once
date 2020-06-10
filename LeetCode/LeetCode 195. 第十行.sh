#!/bin/bash

# 方法一 4ms
awk '{if(NR==10){print $0}}' file.txt
# NR：表示awk开始执行程序后所读取的数据行数。

# 方法二 0ms
grep -n "" file.txt | grep -w "10" | cut -d ":" -f 2
# -n：显示行数
# -w：精确匹配出“10”字符串的
# -d ":"： 以 ":" 为分隔符
# -f 2：获取第二列

# 方法三 4ms
sed -n '10p' file.txt
# p：行号
# -n '10p'：只输出第10行