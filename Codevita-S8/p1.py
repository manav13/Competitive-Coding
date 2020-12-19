slabs = input().split(' ')
percent = input().split(' ')
# rebate = input()
# tax_paid = input().split(' ')
# salary = list()
max_tax = list()

for i in range(len(slabs)+1):
    if(i==0):
        max_tax.append(0)
    else:
        amt = (int(slabs[i+1]) - int(slabs[i]))*(int(percent[i])/100)
        max_tax.append(amt)

print(max_tax)
