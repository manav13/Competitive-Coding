# Function from GEEKSOFGEEKS
def minSwaps(arr): 
    n = len(arr) 
    arrpos = [*enumerate(arr)] 
    arrpos.sort(key = lambda it:it[1]) 
      
    vis = {k:False for k in range(n)} 
    nodes = []
    ans = 0
    for i in range(n): 

        if vis[i] or arrpos[i][0] == i: 
            continue

        cycle_size = 0
        j = i 
        singleCycle = []
        while not vis[j]: 

            vis[j] = True
            singleCycle.append(arrpos[j][1])
            j = arrpos[j][0]
            cycle_size += 1
              
        if cycle_size > 0: 
            nodes.append(singleCycle)
            ans += (cycle_size - 1)

    return ans, nodes

def makePairs(cycle):
    finalList = []
    for singleCycle in cycle:
        if(len(singleCycle)==2):
            finalList.append(singleCycle)
        else:
            for i in range(len(singleCycle)-1):
                finalList.append([singleCycle[i], singleCycle[i+1]])
            finalList.append([singleCycle[len(singleCycle)-1], singleCycle[0]])
    return finalList
       


t = int(input())
finalAns = []

for i in range(t):
    n,m = map(int, input().split())
    p = list(map(int, input().split()))
    robotSwap = []
    for j in range(m):
        xyPair = list(map(int, input().split()))
        robotSwap.append(xyPair)
    numSwaps, cycles = minSwaps(p)
    selectedPairs = []
    if(numSwaps == n-1 and m!=0):
        cycleList = makePairs(cycles)
        for swap in robotSwap:
            similarSwap = [swap[1], swap[0]]
            if(swap not in cycleList and similarSwap not in cycleList):
                selectedPairs.append(swap)
    if(m==0):
        finalAns.append(str(numSwaps))
    elif(m==(n*(n-1))/2):
        finalAns.append('0')
    else:
        allNumSwaps = []
        for singleCycle in cycles:
            maxCycleSwaps = len(singleCycle)-1
            flag = 0
            for j in range(len(singleCycle)-1):
                xyPair1 = [singleCycle[j], singleCycle[j+1]]
                xyPair2 = [singleCycle[j+1], singleCycle[j]]
                if(((xyPair1 in robotSwap) or (xyPair2 in robotSwap)) and maxCycleSwaps!=0):
                    if(j==len(singleCycle)-2):
                        flag = 1
                        numSwaps -= 1
                        maxCycleSwaps -= 1
                    else:
                        numSwaps -= 1
                        maxCycleSwaps -= 1
            if(flag==0 or (flag==1 and maxCycleSwaps!=0)):
                xyPair1 = [singleCycle[0], singleCycle[len(singleCycle)-1]]
                xyPair2 = [singleCycle[len(singleCycle)-1], singleCycle[0]]
                if(((xyPair1 in robotSwap) or (xyPair2 in robotSwap)) and maxCycleSwaps!=0):
                    numSwaps -= 1
                    maxCycleSwaps -= 1
        allNumSwaps.append(numSwaps)
        if(len(selectedPairs)>0):
            for pair in selectedPairs:
                p[pair[0]-1], p[pair[1]-1] = p[pair[1]-1], p[pair[0]-1]
                numSwaps, cycles = minSwaps(p)
                p[pair[0]-1], p[pair[1]-1] = p[pair[1]-1], p[pair[0]-1]
                for singleCycle in cycles:
                    maxCycleSwaps = len(singleCycle)-1
                    flag = 0
                    for j in range(len(singleCycle)-1):
                        xyPair1 = [singleCycle[j], singleCycle[j+1]]
                        xyPair2 = [singleCycle[j+1], singleCycle[j]]
                        if(((xyPair1 in robotSwap) or (xyPair2 in robotSwap)) and maxCycleSwaps!=0):
                            if(j==len(singleCycle)-2):
                                flag = 1
                                numSwaps -= 1
                                maxCycleSwaps -= 1
                            else:
                                numSwaps -= 1
                                maxCycleSwaps -= 1
                    if(flag==0 or (flag==1 and maxCycleSwaps!=0)):
                        xyPair1 = [singleCycle[0], singleCycle[len(singleCycle)-1]]
                        xyPair2 = [singleCycle[len(singleCycle)-1], singleCycle[0]]
                        if(((xyPair1 in robotSwap) or (xyPair2 in robotSwap)) and maxCycleSwaps!=0):
                            numSwaps -= 1
                            maxCycleSwaps -= 1
                allNumSwaps.append(numSwaps)
        finalAns.append(str(min(allNumSwaps)))
from sys import stdout
stdout.write("\n".join(finalAns))