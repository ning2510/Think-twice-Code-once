# Read from the file file.txt and output all valid phone numbers to stdout.

cat file.txt | grep -P '([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}' file.txt
# -P：利用PERL的正则语法进行匹配
# {3}：前面的数重复3次
# \(\)：取消括号的特殊含义
# |：指明两项之间的一个选择
