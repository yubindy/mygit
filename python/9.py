a = input()
s = ""
dict1 = {'0': '零', '1': '壹', '2': '贰', '3': '叁', '4': '肆',
    '5': '伍', '6': '陆', '7': '柒', '8': '捌', '9': '玖'}
dict2 = {0: '拾', 1: '佰', 2: '仟', 3: ''}
dict3 = {0: '万', 1: '亿', 2: ''}
if len(a) % 4 == 0:
    t = int(len(a)/4)
else:
    t = int(len(a)/4)+1
for i in range(t):
    for j in range(4):
        if(len(a)-i*4-j-1 < 0):
                break
        s+=dict1[a[len(a)-i*4-j-1]]
        if(len(a)-i*4-j-1==0):
                break
        s+=dict2[j]
    if((len(a)-i*4)>4):
        s+=dict3[i]
ptr=s[::-1]+'圆'
print(ptr)

