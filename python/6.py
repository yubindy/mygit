a = int(input())
s = [[0]*a]*a
    for i in range(0, a):
        s[i] = input().split()
    for i in range(0, a):
        for j in range(0, a):
            t = a[i][j]
            s[i][j] = s[a-i-1][a-1-j]
            s[a-i-1][a-1-j] = t
    for i in range(0, a):
        for j in range(0, a):
            print("%d", s[i][j])

