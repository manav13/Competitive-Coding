t = int(input())
finalAns = []

for i in range(t):
    n, k = map(int, input().split())
    asorted = list(map(int, input().split()))
    a = asorted.copy()
    asorted.sort()
    flag=0
    if(k==1):
        finalAns.append("yes")
        continue
    for num in asorted:
        indexOrg = a.index(num)
        indexSor = asorted.index(num)
        if(abs(indexOrg-indexSor)%k!=0):
            flag=1
            finalAns.append("no")
            break
    if(flag==0):
        finalAns.append("yes")
            

from sys import stdout
stdout.write("\n".join(finalAns))