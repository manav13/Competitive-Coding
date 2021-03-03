#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector< int > v(10);
    cout << "Vector size: " << v.size() << endl;
    cout << "Vector Empty? - " << v.empty() << endl;
    cout << "Initial vector elements:\n";
    for (int i=0; i<10; ++i){
        cout << v[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; ++i){
        v[i] = i*i;
    }

    cout << "Size of vector : "<< v.size() << endl;
    cout << "Vector Empty? - " << v.empty() << endl;
    cout << "Printing all the elements" << endl;
    for (int i=0; i<10; ++i){
        cout << v[i] << " ";
    }
}