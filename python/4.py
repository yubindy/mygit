import random           #要实现随机抽取，理所当然需要引入random库
import string           #引入string库方便字符列表的生成
x = int(input())
random.seed(x)          #设置种子数
n=int(input())
m=int(input())
s = list(string.ascii_letters+string.digits)
for i in range(n):              #外for循环决定行数，内for循环决定每行的数据个数（列数）
    for j in range(m):
        print(random.choice(s),end="")
    if i<n-1:                   #使形成的每列都换行，但是最后一列不换行，满足输出要求
       print()