n = int(input())
m=1
l = n
n1 = n*(n+1) - n + 1
count = n
for i in range(1,n+1):
    z = "0"
    st = ""
    for j in range(m, m+count):
        st = st + str(j) + z
    for k in range(n1, n1+count):
        if(k==n1+count-1):
            st = st + str(k)
        else:
            st = st + str(k) + z
    m = j+1
    count -= 1
    n1 = n1 - count
    print("**"*(i-1) + st)