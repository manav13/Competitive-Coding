#include <bits/stdc++.h>
using namespace std;

string convert_time_24hrs (string time, string time_am_pm) {
    if (time_am_pm == "PM") {
        int hr = stoi(time.substr(0,2));
        if(hr != 12) {
            hr += 12;
            char tmp[3];
            sprintf(tmp, "%d", hr);
            time[1] = tmp[1];
            time[0] = tmp[0];
        }
    }
    else {
        int hr = stoi(time.substr(0,2));
        if (hr == 12) {
            char tmp[3];
            sprintf(tmp, "%d", 0);
            time[0] = tmp[0];
            time[1] = tmp[0];
        }
    }
    return time;
}

int meeting (string chef_time, string l_time, string r_time) {
    
    if ( stoi(chef_time.substr(0,2)) > stoi(l_time.substr(0,2)) &&
         stoi(chef_time.substr(0,2)) < stoi(r_time.substr(0,2)) )
    {
        return 1;
    }
    else if (stoi(chef_time.substr(0,2)) == stoi(l_time.substr(0,2))) {

        if (stoi(chef_time.substr(0,2)) < stoi(r_time.substr(0,2))) {
            if (stoi(l_time.substr(3,5)) <= stoi(chef_time.substr(3,5))) return 1;
            else return 0;
        }
        else if (stoi(chef_time.substr(0,2)) == stoi(r_time.substr(0,2))) {
            if ((stoi(l_time.substr(3,5)) <= stoi(chef_time.substr(3,5))) && (stoi(r_time.substr(3,5)) >= stoi(chef_time.substr(3,5)))) return 1;
            else return 0;
        }
        else return 0;
    }
    else if (stoi(chef_time.substr(0,2)) == stoi(r_time.substr(0,2))) {
        if (stoi(r_time.substr(3,5)) >= stoi(chef_time.substr(3,5))) return 1;
        else return 0;
    }
    else return 0;
}

int main () {
    
    int t;
    cin >> t;

    while (t!=0) {
        
        string chef_time;
        string chef_am_pm;
        
        cin >> chef_time >> chef_am_pm;
        chef_time = convert_time_24hrs(chef_time, chef_am_pm);

        // cout << "Chef Time: " << chef_time << endl;
        int n;
        cin >> n;

        string output = "";

        for (int i=0; i<n; i++) {
            string l_time;
            string l_am_pm;

            string r_time;
            string r_am_pm;

            cin >> l_time >> l_am_pm >> r_time >> r_am_pm;
            l_time = convert_time_24hrs(l_time, l_am_pm);
            r_time = convert_time_24hrs(r_time, r_am_pm);

            if (meeting(chef_time, l_time, r_time) == 1) output += '1';
            else output += '0';
        }
        cout << output << endl;
        
        t--;
    }
    
    return 0;
}