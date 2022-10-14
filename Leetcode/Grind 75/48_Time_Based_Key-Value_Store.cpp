#include<bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    
    unordered_map<string, vector<pair<string, int>>> hash;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = hash[key].size()-1;
        
        string output = "";
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(timestamp < hash[key][mid].second) {
                right = mid-1;
            }
            else {
                left = mid+1;
                output = hash[key][mid].first;
            }
        }
        return output;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */