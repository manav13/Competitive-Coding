t = int(input())
finalAns = []
for i in range(t):
    n, s = map(int, input().split())
    p = list(map(int, input().split()))
    ptype = list(map(int, input().split()))
    minDef = 100
    minFor = 100
    for j in range(n):
        if(ptype[j]==0):
            if(p[j]<minDef):
                minDef = p[j]
        else:
            if(p[j]<minFor):
                minFor = p[j]
    if((minDef+minFor)<=100-s):
        finalAns.append("yes")
    else:
        finalAns.append("no")
from sys import stdout
stdout.write("\n".join(finalAns))