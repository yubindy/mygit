a=int(input())
flag=0
for i in range(a):
    flag=0
    b=int(input())
    s=[[0]*b]*b
    for j in range(0,b):
        s[j]=input().split()
    for i in range(0,b):
        if flag==1:
            break
        for j in range(0,b):
            if s[i][j]!=s[b-i-1][j]:
                flag=1
            if s[i][j]!=s[i][b-j-1]:
                flag=1
    if flag==1:
        print("no")
    else:
        print("yes")                        

