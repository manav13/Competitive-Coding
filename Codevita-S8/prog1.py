slabs = input().split(' ')
percent = input().split(' ')
rebate = input()
tax_paid = input().split(' ')
salary = list()
max_tax = list()

for i in range(len(slabs)):
    if i == 0:
        max_tax.append(0)
    else:
        amt = (int(slabs[i]) - int(slabs[i-1]))*(int(percent[i-1])/100)
        max_tax.append(amt)


for i in range(len(tax_paid)):
    tax_amt = int(tax_paid[i])
    sal = 0
    for j in range(len(max_tax)):
        if tax_amt >= max_tax[j]:
            if(j==0):
                sal = sal + int(slabs[j])
                tax_amt = tax_amt - max_tax[j]
            else:
                sal = sal + int(slabs[j]) - int(slabs[j-1])
                tax_amt = tax_amt - max_tax[j]
        else:
            sal = sal + tax_amt/(int(percent[j-1])/100)
            tax_amt=0
    if(tax_amt>0):
        sal = sal + (tax_amt/(int(percent[len(percent)-1])/100))
    sal = sal + int(rebate)
    salary.append(sal)
total = 0
for i in range(len(salary)):
    total = total + salary[i]

print(int(total))