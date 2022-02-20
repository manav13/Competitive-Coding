# Name - Efficient Harvest

def maxProfit(k, profit):
    size = len(profit)
    rotate = size // 2
    winSum = float('-inf')
    iterator = 0
    preSum = [0] * (2 *size + 1)

    for i in range(size):
        preSum[i + 1] = preSum[i] + profit[i]
    for i in range(size):
        preSum[i +size + 1] = preSum[i + size] + profit[i]

    while iterator <= (len(profit) // 2) - 1:
        curSum = (preSum[iterator + k] - preSum[iterator]) + (preSum[iterator + rotate + k] - preSum[iterator + rotate])
        winSum = max(winSum, curSum)
        iterator += 1

    return winSum