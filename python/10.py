list = []   
while 1:
    a=input()
    if a=='q':
        break
    else:
       list.append(a)
b= []
for i in list:
    for i in b:
        if list[i] in b:
            b[i]=b[i]+1
        else:
            b[i]=1
t=b.max()

    


