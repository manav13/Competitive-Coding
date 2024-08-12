class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        
        // Brute Force
        // Start all the k cards from left
        // Remove one from left and add from right
        // Maintain the maxPoints
        int sum = 0;
        for(int i=0; i<k; i++) {
            sum += cardPoints[i];
        }
        int l = k-1, r = size-1;
        int maxPoint = sum;
        while(l >= 0) {
            sum = sum - cardPoints[l];
            sum = sum + cardPoints[r];
            maxPoint = max(maxPoint, sum);
            l--;
            r--;
        }
        return maxPoint;
    }
};