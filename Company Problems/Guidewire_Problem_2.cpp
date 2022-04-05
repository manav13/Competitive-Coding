#include<bits/stdc++.h>
using namespace std;

vector<string> split(string s, char deli) {
    s+=deli;
    vector<string> splitString;
    string temp = "";
    int size = s.size();
    for(int i=0; i<size; i++) {
        if(s[i] == deli) {
            splitString.push_back(temp);
            temp = "";
            i++;
        }
        temp += s[i];
    }

    return splitString;
}

string solution(string s) {
    vector<string> rows = split(s, '\n');

    string header = rows[0];
    string str = header + "\n";
    int numRows = rows.size();
    for(int i=1; i<numRows; i++) {
        vector<string> cells = split(rows[i], ',');
        bool isDefective = false;

        for(auto cell : cells) {
            if(cell == "NULL") {
                isDefective = true;
                break;
            }
        }
        if(!isDefective) {
            str += rows[i] + "\n";
        }
    }
    str = str.substr(0, str.size()-1);
    return str;
}

int main() {
    cout << solution("id,name,age,score\n1,Jack,NULL,12\n17,Betty,28,11") << endl;
    return 0;
}

// public String solution(String s) {
//         String[] rows = s.split("\n");
//         // get the header of the CSV 
//         String header = rows[0];
//         // to store the rows which doesn't contain
//         // any NULL value
//         String str = header + "\n";
        
//         // iterate through the rows of CSV
//         for(int i = 1; i < rows.length; i++) {
//         // split each row into cells by using "," as delimiter
//         String[] cells = rows[i].split(",");
        
//         // "ag will be set to true if this row is defective
//         boolean isDefective = false;
        
//         // iterate through values of cells
//         for(String cell : cells) {
//         // check if value of cell is NULL or not
//         if(cell.equals("NULL")) {
//         // if it is NULL
//         // then, set "ag as true
//         isDefective = true;
//         // exit the loop because there is no
//         // need to check further
//         break;
//         }
//         }
//         // if this row is not defective
//         if(!isDefective) {
//         // then, concatenate this row to str string variable
//         str += rows[i] + "\n";
//         }
//         }
//         // remove the last newline character
//         str = str.substring(0, str.length() - 1);
//         // return the modi!ed CSV string
//         return str;
//     }