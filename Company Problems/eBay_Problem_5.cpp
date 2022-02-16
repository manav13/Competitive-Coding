// Not solved yet (TC passed = 6/7)

#include<bits/stdc++.h>
using namespace std;

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
            if(wordSize <= curWidth) {
                wordsCanFit.push_back(word);
                if(j==0) curWidth -= wordSize;
                else curWidth -= (wordSize+1);
            }
            else {
                string line = "*";
                if(side == "LEFT") {
                    int s = wordsCanFit.size();
                    for(int k=0; k<s; k++) {
                        line += wordsCanFit[k];
                        if(k!=s-1) line += " ";
                    }
                    
                    for(int k=0; k<curWidth; k++) {
                        line += " ";
                    }
                    
                    line += "*";
                    output.push_back(line);
                    
                    // Cleaning
                    while(!wordsCanFit.empty()) {
                        wordsCanFit.pop_back();
                    }
                    wordsCanFit.push_back(word);
                    curWidth = width - wordSize;
                }
                else {
                    for(int k=0; k<curWidth; k++) {
                        line += " ";
                    }
                    
                    int s = wordsCanFit.size();
                    for(int k=0; k<s; k++) {
                        line += wordsCanFit[k];
                        if(k!=s-1) line += " ";
                    }
                    
                    line += "*";
                    output.push_back(line);
                    
                    // Cleaning
                    while(!wordsCanFit.empty()) {
                        wordsCanFit.pop_back();
                    }
                    wordsCanFit.push_back(word);
                    curWidth = width - wordSize;
                }
            }
        }  
        string line = "*";
        if(side == "LEFT") {
            int s = wordsCanFit.size();
            for(int k=0; k<s; k++) {
                line += wordsCanFit[k];
                if(k!=s-1) line += " ";
            }
            
            for(int k=0; k<curWidth; k++) {
                line += " ";
            }
            
            line += "*";
            output.push_back(line);
        }
        else {
            for(int k=0; k<curWidth; k++) {
                line += " ";
            }
            
            int s = wordsCanFit.size();
            for(int k=0; k<s; k++) {
                line += wordsCanFit[k];
                if(k!=s-1) line += " ";
            }
            
            line += "*";
            output.push_back(line);
        } 
    }
    
    output.push_back(firstRow);
    return output;
}

int main() {
    return 0;
}