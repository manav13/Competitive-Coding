lmin = int(input())
lmax = int(input())
wmin = int(input())
wmax = int(input())

count = 0
totalcount = 0
l = [[0 for i in range(wmax-wmin+1)] for j in range(lmax-lmin+1)]
for i in range(lmin,lmax+1):
    for j in range(wmin,wmax+1):
        if (l[i-lmin][j-wmin]!=0):
            totalcount = totalcount + l[i-lmin][j-wmin]
        else:
            count = 0
            min1 = min(lmin, wmin)
            max1 = max(lmin, wmin)
            while (True):
                if (min1 == 1 or min1 == 0):
                    count = count + max1 * min1
                    break
                else:
                    count += 1
                    max1 = max1 - min1
                    if (min1 > max1):
                        min1, max1 = max1, min1
            totalcount = totalcount + count
            l[i-lmin][j-wmin] = count
print(totalcount)