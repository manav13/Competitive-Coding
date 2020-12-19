def decToBin(n):
    if(n==0): return True
    ones = 1
    while(n>1):
        ones += n%2
        n = int(n/2)
    return (ones%2==0)

from sys import stdout
t = int(input())
finalAns = []
for i in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    for k in range(q):
        p = int(input())
        evenOnes = 0
        for j in range(n):
            ans = p^a[j]
            if(decToBin(ans)):
                evenOnes += 1
        finalAns.append(str(evenOnes)+" "+str(n-evenOnes))
stdout.write("\n".join(finalAns))