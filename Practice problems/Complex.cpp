#include<bits/stdc++.h>
using namespace std;
class Complex {
    private:
    
    int real;
    int img;

    public:

    Complex (int real, int img) {
        this->real = real;
        this->img = img;
    }

    void print() {
        cout << real << " + " << img << "i" << endl;
    }

    void add(Complex const &c2) {
        this->real += c2.real;
        this->img += c2.img;
    }

    void multiply(Complex const &c2) {
        this->real *= c2.real;
        this->img *= c2.img;
    }
};

int main() {
    int real1, real2, img1, img2;

    cout << "Enter first complex number:" << endl;
    cin >> real1 >> img1;
    cout << "Enter second complex number:" << endl;
    cin >> real2 >> img2;

    Complex c1(real1, img1);
    Complex c2(real2, img2);

    int choice;
    cout << "Choice: 1.Add 2.Multiply" << endl;
    cin >> choice;

    if (choice == 1) {
        c1.add(c2);
        c1.print();
    }
    else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
}