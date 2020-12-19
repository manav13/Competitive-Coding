t = int(input())
finalAns = []
p = (int)(1e9+7)
for j in range(t):
    n, a = map(int, input().split())
    sum = 0
    newMat = a
    for i in range(1,n*2,2):
        numMul = (newMat**i)%p
        sum = sum%p + numMul%p
        newMat = (numMul%p * newMat%p)%p
    finalAns.append(str(sum))
from sys import stdout
stdout.write("\n".join(finalAns))