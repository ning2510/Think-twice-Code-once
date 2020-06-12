# Read from the file words.txt and output the word frequency list to stdout.

# 方法一 awk
awk '{for(i=1;i<=NF;i++){asso_array[$i]++;}};END{for(x in asso_array){print x,asso_array[x];}}' words.txt | sort -rn -k2

# 方法二 xargs uniq
cat words.txt | xargs -n1 | sort | uniq -c | sort -rn | awk '{print $2,$1}'

# xargs [选项]
# -n：指定输出时每行输出的列数