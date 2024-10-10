#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    char dummychar;

    cout << "Enter first fraction: ";
    cin >> a >> dummychar >> b;

    if (b == 0) {
        cout << "Error: Denominator of the first fraction is zero." << endl;
        return 1;
    }

    cout << "Enter second fraction: ";
    cin >> c >> dummychar >> d;

    if (d == 0) {
        cout << "Error: Denominator of the second fraction is zero." << endl;
        return 1;
    }

    int n = a * d + b * c;
    int dn = b * d;

    cout << "Sum = " << n << "/" << dn << endl;
    return 0;
}
