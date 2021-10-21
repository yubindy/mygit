try:
    while(1):
        a = input()
        b = a.split(" ")
        c = int(b[0])
        d = int(b[1])
        x=c
        y=d
        flag = 0
        print("")
        while d != 0:
            t = c % d
            c = d
            d = t
        print("%d" % c,end=" ")
        for i in range(1, x+1):
            if (flag == 1):
                break
            e = x*i
            for j in range(1, y+1):
                f = y*j
                if f == e:
                    print("%d" % e,end=" ")
                    flag = 1
                    break
except:
    pass
