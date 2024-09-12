// Problem: Image processing service

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateBy90(vector<vector<int>> image) {
    int n = image.size();
    vector<vector<int>> newImage(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            newImage[j][n-1-i] = image[i][j];
        }
    }
    return newImage;
}

vector<vector<int>> getFinalImage(vector<vector<int>> image, int rotation, int vertical_flip, int horizontal_flip) {
    int n = image.size();

    switch(rotation) {
        case 90:
            image = rotateBy90(image);
            break;
        case 180:
            image = rotateBy90(rotateBy90(image));
            break;
        case 180:
            image = rotateBy90(rotateBy90(rotateBy90(image)));
            break;
        default:
            break;
    }

    if(vertical_flip == 1) {
        reverse(image.begin(), image.end());
    }

    if(horizontal_flip == 1) {
        for(int i=0; i<n; i++) {
            reverse(image[i].begin(), image[i].end());
        }
    }

    return image;
}