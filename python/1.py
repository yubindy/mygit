try:
    while True:
        num = list(map(int, input().split()))
        m = max(int(num[0]), int(num[1]))
        n = min(int(num[0]), int(num[1]))
        r = m % n
        while r != 0:
            m = nn 
            n = r
            r = m % n
        print("{0} {1}".format(n, int(int(num[0]) * int(num[1]) / n)))
except:
    pass