# def FactList(x, k):
#     n = 1 
#     while(n <=10000):
#         factlist = []   # Reset the list of factors
#         primelist = []
#         countfact = 0   # Reset the number of factors. 
#         for i in range(1,n+1):
#             if n % i == 0: # If i is a factor of n..
#                 countfact += 1 # Increment the factor count of n.
#                 factlist +=[i]
                     
#         if countfact == x:
#             for num in factlist:
#                 if(isPrime(num)):
#                     primelist.append(num)
#             if(len(primelist)==k):
#                 print (n, "has", x ,"factors:")
#                 print (factlist)
#                 print (primelist)
              
#         n += 1

# def isPrime(n) : 
#     # Corner cases 
#     if (n <= 1) : 
#         return False
#     if (n <= 3) : 
#         return True
  
#     # This is checked so that we can skip  
#     # middle five numbers in below loop 
#     if (n % 2 == 0 or n % 3 == 0) : 
#         return False
  
#     i = 5
#     while(i * i <= n) : 
#         if (n % i == 0 or n % (i + 2) == 0) : 
#             return False
#         i = i + 6
  
#     return True


import math
def primeFactorization(n):
      
    # Print the number of two's that divide n 
    primeFact = []
    while n % 2 == 0: 
        primeFact.append(2) 
        n = n / 2
          
    # n must be odd at this point 
    # so a skip of 2 ( i = i + 2) can be used 
    for i in range(3,int(math.sqrt(n))+1,2): 
          
        # while i divides n , print i ad divide n 
        while n % i== 0: 
            primeFact.append(i) 
            n = n / i 
              
    # Condition if n is a prime 
    # number greater than 2 
    if n > 2: 
        primeFact.append(n) 
    return primeFact

t = int(input())
finalAns = []
for i in range(t):
    x,k = map(int, input().split())
    primeFact = primeFactorization(x)
    if(len(primeFact)>=k):
        finalAns.append('1')
    else:
        finalAns.append('0')

        
from sys import stdout
stdout.write("\n".join(finalAns))