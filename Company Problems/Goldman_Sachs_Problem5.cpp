using namespace std;

#include <bits/stdc++.h>

class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < arr.size() - 2; i++) {
      count += searchPair(arr, target - arr[i], i);
    }
    return count;
  }

 private:
  static int searchPair(const vector<int> &arr, int targetSum, int first) {
    int count = 0;
    int left = first + 1, right = arr.size() - 1;
    while (left < right) {
      if (arr[left] + arr[right] <= targetSum) {  // found the triplet
        // since arr[right] >= arr[left], therefore, we can replace arr[right] by any number between
        // left and right to get a sum less than the target sum
        count += right - left;
        left++;
      } else {
        right--;  // we need a pair with a smaller sum
      }
    }
    return count;
  }
};

int main() {
  int n, t;
  vector<int> vec;
  cin >> n >> t;
  for(int i=0; i<n; i++) {
      int temp;
      cin >> temp;
      vec.push_back(temp);
  }
  cout << TripletWithSmallerSum::searchTriplets(vec, t) << endl;
  return 0;
}