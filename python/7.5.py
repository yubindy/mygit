try:
    while True:
        m = 0
        list1 = list(map(int,input().split()))
        n = list1.pop(0)
        for i in range(int(n/2)+1):
            Min = min(list1)
            m += int(Min/2)+1
            list1.remove(Min)
        print(m)
except:
    pass