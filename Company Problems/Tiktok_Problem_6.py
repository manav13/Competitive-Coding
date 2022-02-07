# Name - Is Possible 
def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)
 
def solve(a, b, x, y):
    if(gcd(a,b) == gcd(x,y)):
        return "Yes"
    else: 
        return "No"

print(solve(1,4,62,45))