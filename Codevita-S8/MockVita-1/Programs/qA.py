def rotate(str, d, mag):
    if (d=="L"):
        return str[mag:] + str[0:mag]
    elif (d=="R"):
        return str[len(str)-mag:] + str[0: len(str)-mag]

def checkAnagram(str1, str2):
    if(sorted(str1)==sorted(str2)):
        return True
    else:
        return False
    
def subString(s, n, ans): 
    for i in range(n): 
        for leng in range(i+1,n+1):
            sub = s[i:leng]
            if(len(sub)==len(ans)):
                if(checkAnagram(sub,ans)):
                    return True
    return False

str = input().split(" ")
str1 = str[0]
str2 = str1
q = int(str[1])
ans = ""
d = list()
mag = list()
str3 = str[2:]
for i in range(len(str3)):
    if (i%2==0):
        d.append(str3[i])
    else:
        mag.append(int(str3[i]))

#str1 = input()
#str2 = str1
#q = int(input())
#d = list()
#mag = list()
#ans = ""
#for i in range(q):
#    d.append(input())
#    mag.append(int(input()))
for i in range(q):
    str2 = rotate(str2,d[i],mag[i])
    ans = ans + str2[0]

if(subString(str1,len(str1),ans)):
    print("YES")
else:
    print("NO")
