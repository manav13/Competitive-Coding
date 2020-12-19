import math

def isPrime(n):
    if n == 1:
        return False

    i = 2
    while i*i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

t = int(input())
finalAns = []

for i in range(t):
    n = int(input())
    
    if(n<4):
        readList = [i for i in range(1,n+1)]
        readList.insert(0,1)
        finalAns.append(str(1))
        finalAns.append(readList)
        continue
    
    readList = [[1]]   
    for j in range(2, n+1):
        count = 1
        if(isPrime(j)):
            readList[0].append(j)
        elif(j%2==0):
            readList.append([j])
        else:
            while True:
                flag = 0
                for m in readList[count]:
                    if(math.gcd(m, j)!=1):
                        count+=1
                        flag=1
                        break
                if(flag==0):
                    readList[count].append(j)
                    break
    
    finalAns.append([len(readList)])
    for j in range(len(readList)):
        readList[j].insert(0, len(readList[j]))    
        finalAns.append(readList[j])

for i in range(len(finalAns)):
    print(" ".join(map(str, finalAns[i])))