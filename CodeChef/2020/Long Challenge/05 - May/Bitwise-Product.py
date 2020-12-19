t = int(input())
finalAns = []

for i in range(t):
    x,y,l,r = map(int, input().split())
    if((x==0 or y==0) and l==0):
        finalAns.append('0')
        continue
    z = x|y
    if(z>r):
        x = 1
        while(x<r):
            x *= 2
        x = r|x-1
        z = z&x
    # count = 1
    # while(z>r):
    #     z = z>>count
    #     binZ = bin(z).replace("0b","")
    #     for j in range(count):
    #         binZ += '0'
    #     z = int(binZ, 2)
    #     count += 1      
    finalAns.append(str(z))
from sys import stdout
stdout.write("\n".join(finalAns))