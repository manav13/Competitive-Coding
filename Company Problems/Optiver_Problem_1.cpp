#include<bits/stdc++.h>
using namespace std;

class LogServer {
    private:
    
        int maxLogs;

        // timestamp, id
        map<int, int> logStorage;
    
    public:

        LogServer(int maxLogs) : maxLogs(maxLogs) {
        }

        void recordLogs(int logId, int timestamp) {
            
            // Store log
            this->logStorage[timestamp] = logId;

            // Remove all the logs whose timestamp is greater than 3600
            int largestTimeStamp = this->logStorage.rbegin()->first;
            if(largestTimeStamp > 3600) {
                int cutOff = largestTimeStamp - 3600;
                // remove all the timestamps from 0 to cutoff;
                int count = 0;
                for(auto it : this->logStorage) {
                    if(it.first <= cutOff)
                        count++;
                }

                // Remove top elements
                while(count != 0) {
                    this->logStorage.erase(this->logStorage.begin());
                    count--;
                }
            }
        }

        string getLogs() {
            string ans = "";
            if(this->logStorage.size() > this->maxLogs) {
                int count = 0;
                for(auto it=this->logStorage.rbegin(); it!=this->logStorage.rend(); it++) {
                    count ++;
                    ans = ", " + to_string((*it).second) + ans;
                    if(count == this->maxLogs) {
                        break;
                    }
                }
                return ans.substr(2, ans.size());
            }
            else {
                for(auto it : this->logStorage) {
                    ans = ans + to_string(it.second) + ", ";
                }
            }
            return ans.substr(0, ans.size()-2);
        }

        int getLogCount() {
            return this->logStorage.size();
        }
};

int main() {
    int m, q;
    cin >> m >> q;
    LogServer l = LogServer(m);

    for(int i=0; i<q; i++) {
        int n;
        cout << "Insert query: " << endl;
        cin >> n;

        if(n==1) {
            int id, timestamp;
            cin >> id >> timestamp;
            l.recordLogs(id, timestamp);
        }
        else if(n==2) { 
            cout << "Called getLogs, find ans below:" << endl;
            cout << l.getLogs() << endl;
        }
        else if(n==3) {
            cout << "Called getLogCount, find ans below:" << endl;
            cout << l.getLogCount() << endl;
        } 
    }
}