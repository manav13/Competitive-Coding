def LCM(arr, n): 
      
    # Find the maximum value in arr[] 
    max_num = 0; 
    for i in range(n): 
        if (max_num < arr[i]): 
            max_num = arr[i]; 
  
    # Initialize result 
    res = 1; 
  
    # Find all factors that are present  
    # in two or more array elements. 
    x = 2; # Current factor. 
    while (x <= max_num): 
          
        # To store indexes of all array 
        # elements that are divisible by x. 
        indexes = []; 
        for j in range(n): 
            if (arr[j] % x == 0): 
                indexes.append(j); 
  
        # If there are 2 or more array  
        # elements that are divisible by x. 
        if (len(indexes) >= 2): 
              
            # Reduce all array elements  
            # divisible by x. 
            for j in range(len(indexes)): 
                arr[indexes[j]] = int(arr[indexes[j]] / x); 
  
            res = res * x; 
        else: 
            x += 1; 
  
    # Then multiply all reduced  
    # array elements 
    for i in range(n): 
        res = res * arr[i]; 
  
    return res; 

t = int(input())
finalAns = []
for i in range(t):
    n,m = map(int, input().split())
    a = list(map(int, input().split()))
    newList = a[:]
    oldLCM = LCM(newList, len(newList))
    ans = 1
    for j in range(1,m+1):
        newList = a[:]
        newList.append(j)
        newLCM = LCM(newList, len(newList))
        if(newLCM > oldLCM):
            ans = j
            oldLCM = newLCM
    finalAns.append(str(ans))
from sys import stdout
stdout.write("\n".join(finalAns))