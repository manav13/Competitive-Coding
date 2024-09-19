#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto num : arr) {
		sum += num;
	}

	int expectedSum = (n*(n+1))/2;

	// Now going back to basic mathematics
	// if x = repeating number and
	//    y = missing number
	// x - y = sum - expectedSum

	int xMinusY = sum - expectedSum;

	// x-y = val is out first equation
	// Need to find the second equation in order to solve it
	// If we subtract sum of square then we will get x2 - y2 value
	// Which we can use it for (x + y)*(x - y), from which we can obtain 2nd equation i.e. x + y = 2ndVal
	// Then its easy to find the individual values

	int sumSquares = 0;
	for(auto num : arr) {
		sumSquares += pow(num,2);
	}

	int expectedSumSquares = (n * (n+1) * (2*n+1))/6;

	int x2Minusy2 = sumSquares - expectedSumSquares;
	int xPlusY = x2Minusy2/xMinusY;

	int x = (xMinusY + xPlusY)/2;
	int y = xPlusY - x;

	return {y, x};
}
