a = int(input())
b = 0
list1 = list(map(int, input().split()))
for i in range(2):
    list1.remove(max(list1))
    list1.remove(min(list1))
for i in range(len(list1)):
    b += int(list1[i])
b=float((b*1.0)/len(list1))
print("aver=%.2f" % b)
