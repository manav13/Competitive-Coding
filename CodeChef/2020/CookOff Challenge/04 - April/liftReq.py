t = int(input())
finalAns = []
for i in range(t):
    n, q = map(int, input().split())
    nFloors = 0
    prevDes = 0
    for j in range(q):
        f, d = map(int, input().split())       
        if(j==0):
            nFloors += f
            nFloors += abs(d-f)
            prevDes = d
        else:
            nFloors += abs(prevDes-f)
            nFloors += abs(d-f)
            prevDes = d
    finalAns.append(str(nFloors))
from sys import stdout
stdout.write("\n".join(finalAns))