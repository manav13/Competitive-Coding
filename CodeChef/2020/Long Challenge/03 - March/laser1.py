from sys import stdout
t = int(input())
finalAns = []
for i in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    for j in range(q):
        count = 0
        x1, x2, y = map(int, input().split())
        for k in range(0,n-1):
            px1, py1 = k+1, a[k]
            px2, py2 = k+2, a[k+1]
            if(((py1<y and py2<y) or (py1>y and py2>y) or (px1<x1 and px2<x1) or (px1>x2 and px2>x2) or (py2-py1)==0)):
                continue
            else:
                x = ((y - py1)*(px2 - px1))/(py2 - py1) + px1
                if((x==px2 and x==x1) or (x==px1 and x==x2)):
                    continue
                elif(x>=x1 and x<=x2):
                    count += 1
        finalAns.append(str(count))
stdout.write("\n".join(finalAns))