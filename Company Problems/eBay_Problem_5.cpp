#include<bits/stdc++.h>
using namespace std;

string buildLine(vector<string> wordsCanFit, int spaceLength, string align) {
    string line = "*";
    int size = wordsCanFit.size();

    // Add right spaces
    if(align == "RIGHT") for(int i=0; i<spaceLength; i++) line += " ";

    // Add words
    for(int i=0; i<size; i++) {
        line += wordsCanFit[i];
        if(i!=size-1) line += " ";
    }

    // Add left spaces
    if(align == "LEFT") for(int i=0; i<spaceLength; i++) line += " ";
    
    line += "*";
    return line;
}

vector<string> solution(vector<vector<string>> paragraphs, vector<string> aligns, int width) {
    vector<string> output;
    string firstRow = "";
    
    for(int i=0; i<width+2; i++) {
        firstRow += "*";
    }
    output.push_back(firstRow);
    int size = aligns.size();
    
    for(int i=0; i<size; i++) {
        vector<string> para = paragraphs[i];
        string side = aligns[i];
        
        int noOfWords = para.size();
        int curWidth = width;
        vector<string> wordsCanFit;
        
        for(int j=0; j<noOfWords; j++) {
            string word = para[j];
            int wordSize = word.size();
            if((wordsCanFit.empty() && wordSize <= curWidth) || (wordSize < curWidth)){
                if(wordsCanFit.empty()) curWidth -= wordSize;
                else curWidth -= (1+wordSize);
                wordsCanFit.push_back(word);
            }
            else {
                output.push_back(buildLine(wordsCanFit, curWidth, side));
                wordsCanFit.clear();
                wordsCanFit.push_back(word);
                curWidth = width - wordSize;
            }
        }
        output.push_back(buildLine(wordsCanFit, curWidth, side));
    }
    output.push_back(firstRow);
    return output;
}

int main() {
    vector<vector<string>> paragraphs;
    
    // paragraphs.push_back({"there are"});
    // paragraphs.push_back({"four seasons", "in a year"});
    // paragraphs.push_back({"summer", "autumn", "winter", "spring"});
    paragraphs.push_back({"hello", "world"});
    paragraphs.push_back({"How", "areYou", "doing"});
    paragraphs.push_back({"Please look", "and align", "to right"});

    vector<string> aligns;
    // aligns.push_back("RIGHT");
    // aligns.push_back("LEFT");
    // aligns.push_back("RIGHT");
    aligns.push_back("LEFT");
    aligns.push_back("RIGHT");
    aligns.push_back("RIGHT");

    int width = 16;

    vector<string> result = solution(paragraphs, aligns, width);

    for(auto str : result) {
        cout << str << endl;
    }
    return 0;
}