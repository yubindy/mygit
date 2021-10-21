# a = int(input())
# W = 100
# G = 100
# for i in range(a):
#     G *= 1.001
#     if (i % 5) <= 2:
#         W *= 1.002
#     else:
#         W *= 0.999
# print("{0:.5f},{1:.5f}".format(G, W))
a = int(input())
W = 100
G = 100
for i in range(a):
    G *= 1.001
    if (i % 5) <= 2:
        W *= 1.002
    else:
        W *= 0.999
print("%.5lf" % G,end=" ")
print("%.5lf" % W,end="")
