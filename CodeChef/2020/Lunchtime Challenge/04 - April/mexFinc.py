def mex(l):
    if(len(l)==0):
        return 1
    else:
        i=1
        while(True):
           if(i not in l):
               return i
           else:
               i += 1

# From GEEKSFROMGEEKS
def printSubsequences(arr, index, subarr): 
      
    # Print the subsequence when reach  
    # the leaf of recursion tree 
    if index == len(arr): 
          
        # Condition to avoid printing 
        # empty subsequence 
        if len(subarr) != 0: 
            # print(subarr) 
            subList.append(subarr)
      
    else: 
        # Subsequence without including  
        # the element at current index
        printSubsequences(arr, index + 1, subarr)
          
        # Subsequence including the element 
        # at current index
        printSubsequences(arr, index + 1, subarr+[arr[index]])
        # return subList
    return

t = int(input())
finalAns = []

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    subList = []
    printSubsequences(a,0,[])
    sum = 0
    for subL in subList:
        sum += mex(subL)
    finalAns.append(str(sum+1))

from sys import stdout
stdout.write("\n".join(finalAns))