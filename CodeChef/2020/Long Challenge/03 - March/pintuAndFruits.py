testCase = int(input())
finalMinPrice = [0 for k in range(testCase)]
for t in range(testCase):
    noOfBaskets, noOfFruits = map(int, input().split())
    fruitType = list(map(int, input().split()))
    price = list(map(int, input().split()))
    sumofPrice = [0 for i in range(noOfFruits)]
    for i in range(noOfFruits):
        for j in range(noOfBaskets):
            if(fruitType[j]==i+1):
                sumofPrice[i] += price[j]
    #print(sumofPrice)
    for i in range(noOfFruits-len(set(fruitType))):
        if(min(sumofPrice)==0):
            sumofPrice.remove(0)
    #print(sumofPrice)
    finalMinPrice[t] = min(sumofPrice)
for x in finalMinPrice:
    print(x)