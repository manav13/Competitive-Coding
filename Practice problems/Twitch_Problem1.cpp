#include<bits/stdc++.h>
using namespace std;

class Twitch {
    private:
    map<string, pair<int, string> > streamers;

    public:
    void StreamerOnline(string name, int views, string category) {
        this->streamers.insert({name, {views, category} });
    }

    void UpdateViews(string name, int views, string category) {
        string currentCategory = this->streamers[name].second;
        if(currentCategory == category) {
            this->streamers[name] = {views, category};
        }
    }

    void UpdateCategory(string name, string cat1, string cat2) {
        string currentCategory = this->streamers[name].second;
        if(currentCategory == cat1) {
            this->streamers[name] = {this->streamers[name].first, cat2};
        }
    }

    void StreamerOffline(string name, string category) {
        string currentCategory = this->streamers[name].second;
        if(currentCategory == category) {
            this->streamers.erase(name);
        }
    }

    int ViewsInCategory(string category) {
        int totalViews = 0;
        for(auto it : this->streamers) {
            if(it.second.second == category) {
                totalViews += it.second.first;
            }
        }
        return totalViews;
    }

    string TopStreamerInCategory(string category) {
        bool isCategory = false;
        int maxViews = -1;
        string topStreamer;
        for(auto it : this->streamers) {
            if(it.second.second == category && it.second.first > maxViews) {
                topStreamer = it.first;
                maxViews = it.second.first;
                isCategory = true;
            }
        }
        return (isCategory ? topStreamer : NULL);
    }

    string TopStreamer() {
        bool isEmpty = this->streamers.empty();
        int maxViews = -1;
        string topStreamer;
        if(!isEmpty) {
            for(auto it : this->streamers) {
                if(it.second.first > maxViews) {
                    maxViews = it.second.first;
                    topStreamer = it.first;
                }
            }
        }

        return (isEmpty ? NULL : topStreamer);
    }

};


void assignCommands(map<string, int> &commandVals) {
    commandVals.insert({"StreamerOnline", 0});
    commandVals.insert({"UpdateViews", 1});
    commandVals.insert({"UpdateCategory", 2});
    commandVals.insert({"StreamerOffline", 3});
    commandVals.insert({"ViewsInCategory", 4});
    commandVals.insert({"TopStreamerInCategory", 5});
    commandVals.insert({"TopStreamer", 6});
}

int main() {
    int n;
    cin >> n;
    vector<string> commands;
    Twitch t1;
    for(int i=0; i<n; i++) {
        string temp;
        getline(cin, temp);
        commands.push_back(temp);
    }
    int i=0;
    map<string, int> commnadVals;

    while(i<n) {
        switch(commnadVals[commands[i]]) {
            case 0:
                t1.StreamerOnline(commands[i+1], stoi(commands[i+2]), commands[i+3]);
                i+=3;
                break;
            case 1:
                t1.UpdateViews(commands[i+1], stoi(commands[i+2]), commands[i+3]);
                i+=3;
                break;
            case 2:
                t1.UpdateCategory(commands[i+1], commands[i+2], commands[i+3]);
                i+=3;
                break;
            case 3:
                t1.StreamerOffline(commands[i+1], commands[i+2]);
                i+=2;
                break;
            case 4:
                cout << t1.ViewsInCategory(commands[i+1]) << endl;
                i+=1;
                break;
            case 5:
                cout << t1.TopStreamerInCategory(commands[i+1]) << endl;
                i+=1;
                break;
            case 6:
                cout << t1.TopStreamer() << endl;
                break;
        }
    }

    return 0;
}