#include<bits/stdc++.h>
using namespace std;

int isWinner(char a[3][3], char val) {
    int flag = 0;
    for(int row=0; row<3; row++) {
        if(a[row][0] == val && a[row][1] == val && a[row][2] == val) flag++;
    }
    for(int col=0; col<3; col++) {
        if(a[0][col]== val && a[1][col]== val && a[2][col]== val) flag++;
    }
    if(a[0][0]==val && a[1][1]==val && a[2][2]==val) flag++;
    if(a[0][2]==val && a[1][1]==val && a[2][0]==val) flag++;
    return flag;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        char a[3][3];
        int flagX = 0, flagO = 0, flagU = 0;
        int countX = 0, countO = 0, countU = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cin >> a[i][j];
                if(a[i][j] == '_') {
                    flagU = 1;
                    countU++;
                }
                else if(a[i][j] == 'X') {
                    countX++;
                }
                else if(a[i][j] == 'O') {
                    countO++;
                }
            }
        }
        int realX = (9-countU)/2;
        int realO = (9-countU)/2;
        if((9-countU)%2 != 0) realX++;

        flagX = isWinner(a, 'X');
        flagO = isWinner(a, 'O');
        
        if((flagX == 1 && flagO == 1) || realX!=countX || realO!=countO || (flagX == 1 && countO>=countX) || (flagO == 1 && countX>countO)) cout << "3" << endl;
        else if (flagO==0 && flagX==0 && flagU==1) cout << "2" << endl;
        else cout << "1" << endl;
    }
    return 0;
}