#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> result;
    int * occurence = new int[nums.size()];

    for(auto itr = nums.begin(); itr != nums.end(); itr++) {

        if(occurence[*(itr)-1] == 1) {
            occurence[*(itr)-1] = 2;
            result.push_back(*(itr));
        }
        else {
            occurence[*(itr)-1] = 1;
        }

    }

    for(int i = 0; i < nums.size(); i++) {
        if(occurence[i]!=1 && occurence[i]!=2) {
            result.push_back(i+1);
            break;
        }
    }

    return result;

}

int main() {
    // cout << findErrorNums(nums) << endl;
    int n;
    cin >> n;

    vector<int> nums;

    while(n) {
        int temp;
        cin >> temp;

        nums.push_back(temp);
        n--;
    }

    vector<int> result = findErrorNums(nums);

    for (auto itr = result.begin(); itr != result.end(); itr++) {
        cout << *(itr) << " ";
    }
    cout << endl;

    return 0;
}