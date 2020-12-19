t = int(input())
finalAns = []
for i in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    sum = 0
    p.sort(reverse = True)
    for i in range(n):
        carVal = p[i] - i
        if(carVal<=0):
            break
        else:
            sum += carVal
    finalAns.append(str(sum%1000000007))
from sys import stdout
stdout.write("\n".join(finalAns))