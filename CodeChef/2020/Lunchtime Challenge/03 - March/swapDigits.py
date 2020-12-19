def maxSum(a1,b1):
    sum = 0
    for i in range(len(a1)):
        for j in range(len(b1)):
            a2 = list(a1)
            b2 = list(b1)
            a2[i] = b1[j]
            b2[j] = a1[i]
            newSum = int("".join(a2)) + int("".join(b2))
            if(newSum > sum):
                sum = newSum
    return sum

t = int(input())
finalAns = []
for i in range(t):
    a,b = map(int, input().split())
    sum = a + b
    if(int(a/10) == 0 and int(b/10)==0):
        finalAns.append(str(sum))
        continue
    newSum = maxSum(str(a), str(b))
    if(newSum>sum):
        sum = newSum
    finalAns.append(str(sum))
    
from sys import stdout
stdout.write("\n".join(finalAns))