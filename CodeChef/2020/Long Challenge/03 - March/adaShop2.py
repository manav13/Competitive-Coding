t= int(input())
finalAns = []
for i in range(t):
    r0, c0 = map(int, input().split())
    m = ["19","2 2","3 1","8 6","6 8","1 3","2 2","3 3","5 1","8 4","4 8","1 5","3 3","4 4","7 1","8 2","2 8","1 7","4 4","8 8"]
    if(r0==1 and c0==1):
        finalAns.append(m)
        continue
    else:
        m[0] = "21"
        n = int((r0 + c0)/2)
        
        m.insert(1,str(n) + " " + str(n))
        m.insert(2,"1 1")
    
    finalAns.append(m)    
    
for x in finalAns:
    print("\n".join(x))