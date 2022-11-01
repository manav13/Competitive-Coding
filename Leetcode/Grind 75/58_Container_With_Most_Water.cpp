class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxHeight = 0;
        while(left < right) {
            int curHeight = (right-left) * min(height[left], height[right]);
            maxHeight = curHeight > maxHeight ? curHeight : maxHeight;
            
            if(height[left] <= height[right]) {
                left++;
            }
            else right--;
        }
        return maxHeight;
    }
};