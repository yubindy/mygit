try:
    while True:
        a = int(input())
        s = [[0]*a]*a
        st = int(0)
        for i in range(0, a):
            s[i] = input().split()
        for i in range(0+st, a):
            for j in range(0+st, a):
                t = s[i][j]
                s[i][j] = s[j][i]
                s[j][i] = t
            st = st+1
        for i in range(0, a):
            for j in range(0, a):
                if j != a-1:
                    print("%s " % s[i][j], end="")
                else:
                    print("%s" % s[i][j], end="")
            print("")
except EOFError:
    pass
