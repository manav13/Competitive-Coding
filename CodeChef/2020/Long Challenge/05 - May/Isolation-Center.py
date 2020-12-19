t = int(input())
finalAns = []

for i in range(t):
    n, q = map(int, input().split())
    s = list(input())
    group = []
    queue = []
    while(len(s)!=0):
        persons = set(s)
        queue.append(len(persons))
        for singlePerson in persons:
            s.remove(singlePerson)
    for j in range(q):
        numOfCenters = int(input())
        if(numOfCenters >= len(queue)):
            finalAns.append('0')
        else:
            finalAns.append(str(sum(queue[numOfCenters:])))
            
from sys import stdout
stdout.write("\n".join(finalAns))