t = int(input())
finalAns = []

for i in range(t):
    n = int(input())
    x = list(map(int, input().split()))
    group = []
    person = [x[0]]
    for j in range(1,n):
        if(x[j]-x[j-1]<=2):
            person.append(x[j])
        else:
            group.append(len(person))
            person = []
            person.append(x[j])
    group.append(len(person))
    minInfected = str(min(group))
    maxInfected = str(max(group))
    finalAns.append(minInfected + " " + maxInfected)

from sys import stdout
stdout.write("\n".join(finalAns))