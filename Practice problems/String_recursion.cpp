#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(char str[]) {
    // Base Case
    if (str[0] == '\0') {
        return;
    }
    
    // Handle first character and then call recusion
    if (str[0] != str[1]) {
        removeDuplicates(str+1);
    } else {
        int i=1;
        for (; str[i]!='\0'; i++) {
            str[i-1] = str[i];
        }
        str[i-1] = str[i];
        removeDuplicates(str);
    }
}

int subsequence(string input, string output[]) {
    // Base Case
    if(input == "") {
        output[0] = "";
        return 1;
    }

    // Call recursion on later part of string
    int size = subsequence(input.substr(1), output);
    for(int i=0; i<size; i++) {
        output[size+i] = input[0] + output[i];
    }
    return size*2;
}

void subsequence_print(string input, string output) {
    // Base Case
    if(input == "") {
        cout << output << endl;
        return;
    }

    subsequence_print(input.substr(1), output);
    subsequence_print(input.substr(1), output + input[0]);
    return;
}

string num_key(int num) {
    vector <string> v;
    v.push_back("+++");
    v.push_back("ONE");
    v.push_back("abc");
    v.push_back("def");
    v.push_back("ghi");
    v.push_back("jkl");
    v.push_back("mno");
    v.push_back("pqrs");
    v.push_back("tuv");
    v.push_back("wxyz");

    return v[num];
}

int keypad_subsequence(int num, string output[]) {
    // Base Case
    if (num==0) {
        output[0] = "";
        return 1;
    }

    string keypad = num_key(num%10);
    int keypad_size = keypad.size();
    int size = keypad_subsequence(int(num/10), output);

    for(int i=0; i<keypad_size*size; i++) {
        output[i] = output[i%size];
    }

    int count=0;
    for(int i=0; i<keypad_size*size; i++) {
        output[i] = output[i] + keypad[count];
        if((i+1)%size==0) count++;
    }
    return keypad_size*size;
}

int main() {

    // char str[100];
    // cin >> str;
    // removeDuplicates(str);
    // cout << str << endl;

    int input;
    cin>>input;

    int size = (int) (pow(4, to_string(input).size()) + 0.5);
    string *output = new string[size];

    int output_size = keypad_subsequence(input, output);
    cout << "Output size: " << output_size << endl;

    for(int i=0; i<output_size; i++) {
        if(output[i] == "") {
            cout << "Null" << endl;
        } else {
            cout << output[i] << endl;
        }
    }
    // subsequence_print(input, "");
    return 0;
}