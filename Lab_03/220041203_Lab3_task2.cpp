#include<iostream>

using namespace std;

class RationalNumber {
    private:
        int numerator;
        int denominator;

    public:
        RationalNumber(int num=0, int denom=1): numerator(num), denominator(denom) {
            if (!validate()) {
                denominator = 1; // Reset to a valid denominator
            }
        }

        bool validate() const {
            if (denominator == 0) {
                cout << "You cannot assign 0 as denominator." << endl;
                return false;
            }
            return true;
        }

        void assign(int num, int denom) {
            numerator = num;
            denominator = denom;
            if (!validate()) {
                return; // Reset to a valid denominator
            }
        }

        double convert() const {
            if (!validate()) return 0.0;
            return (1.0 * numerator) / denominator;
        }

        void invert() {
            if (numerator == 0) {
                denominator = 1; // Invert to 0/1 if numerator is 0
                return;
            }
            swap(numerator, denominator);
            if (!validate()) {
                swap(numerator, denominator); // Revert swap if invalid
            }
        }

        void print() const {
            if (!validate()) return;

            if (numerator == 0)
                cout << "The Rational Number is 0" << endl;
            else if (denominator == 1)
                cout << "The Rational Number is " << numerator << endl;
             else
                cout << "The Rational Number is " << numerator << "/" << denominator << endl;

        }
};

int main() {
    RationalNumber rn;
    rn.assign(7, 0);
    rn.print();
    cout << "Decimal equivalent: " << rn.convert() << endl;
    rn.invert();
    rn.print();
    //rn.assign(1, 0);
    //rn.invert();
    return 0;
}
