#include <iostream>

using namespace std;

struct fraction {
    int num;
    char dummy;
    int denum;
};

int main() {
    fraction frac1, frac2, result;

    cout << "Enter first fraction (format: a/b): ";
    cin >> frac1.num >> frac1.dummy >> frac1.denum;

    if (frac1.denum == 0) {
        cout << "Error: Denominator of the first fraction is zero." << endl;
        return 1;
    }

    cout << "Enter second fraction (format: a/b): ";
    cin >> frac2.num >> frac2.dummy >> frac2.denum;

    if (frac2.denum == 0) {
        cout << "Error: Denominator of the second fraction is zero." << endl;
        return 1;
    }

    result.num = frac1.num * frac2.denum + frac1.denum * frac2.num;
    result.denum = frac1.denum * frac2.denum;

    cout << "Sum = " << result.num << frac1.dummy << result.denum << endl;

    return 0;
}
