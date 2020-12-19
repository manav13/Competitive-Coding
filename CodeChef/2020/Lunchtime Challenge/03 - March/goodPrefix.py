t = int(input())
finalAns = []
for i in range(t):
    s = input()
    k,x = map(int, input().split())
    count = 0
    dict = {}
    for m in s:
        if m not in dict.keys():
            dict[m] = 1
            count += 1
        else:
            dict[m] += 1
            if(dict[m]<=x):
                count += 1
            else:
                if(k==0):
                    break
                else:
                    k -= 1
                    dict[m] -= 1
    finalAns.append(str(count))
    
from sys import stdout
stdout.write("\n".join(finalAns))