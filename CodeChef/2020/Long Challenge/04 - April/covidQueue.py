t = int(input())
finalAns = []
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    count = 0
    flag = 0
    index = 0
    for j in range(n):
        if(a[j]==1):
            index = j
            break
    a = a[index:len(a)]
    for j in range(1,len(a)):
        if(a[j]==0):
            count += 1
        elif(a[j]==1 and count<5):
            flag = 1
            finalAns.append('NO')
            break
        elif(a[j]==1 and count>=5):
            count = 0
    if(flag==0):
        finalAns.append('YES')
from sys import stdout
stdout.write("\n".join(finalAns))