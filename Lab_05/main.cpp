

#include "Products.h"
#include <iostream>
#include <string>

using namespace std;

string generateRandomWord(int seed) {
    string word;
    int length = 3 + (seed % 5);
    for (int i = 0; i < length; ++i) {
        word += 'a' + (seed % 26);
        seed /= 26;
    }
    return word;
}

void generateInformationRandom(Products& product, int seed) {
    string productName = generateRandomWord(seed) + " " + generateRandomWord(seed + 1) + " " + generateRandomWord(seed + 2);
    product.setProductName(String(productName));

    string productCategoryName = generateRandomWord(seed + 3);
    product.setProductCategoryName(String(productCategoryName));

    string productDescription;
    for (int i = 0; i < 10; ++i) {
        productDescription += generateRandomWord(seed + 4 + i) + " ";
    }
    product.setProductDescription(String(productDescription));

    product.setAmountInStore((seed % 100) + 1);
    product.setRegularPrice(static_cast<float>((seed % 1000) + 1) / 10);
    product.setDiscountRate(static_cast<float>((seed % 13) + 3));
}

void EditInformationByKeyboard(Products& product) {
    string input;
    int intInput;
    float floatInput;

    cout << "Enter Product Name: ";
    getline(cin, input);
    product.setProductName(String(input));

    cout << "Enter Product Category Name: ";
    getline(cin, input);
    product.setProductCategoryName(String(input));

    cout << "Enter Product Description: ";
    getline(cin, input);
    product.setProductDescription(String(input));

    cout << "Enter Amount in Store: ";
    cin >> intInput;
    product.setAmountInStore(intInput);

    cout << "Enter Regular Price: ";
    cin >> floatInput;
    product.setRegularPrice(floatInput);

    cout << "Enter Discount Rate: ";
    cin >> floatInput;
    product.setDiscountRate(floatInput);

    cin.ignore();
}

void ShowAllDiscount(Products ar[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Product Name: " << ar[i].getProductName().getString()
             << ", Discount: " << ar[i].calculateDiscount(5) << endl;
    }
}

void grossTotal(Products ar[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; ++i) {
        int amountToPurchase = (i % 20) + 1; // Simple deterministic value
        total += ar[i].netTotal(amountToPurchase);
        ar[i].PurchaseProduct(amountToPurchase);
    }
    cout << "Total amount to pay: " << total << endl;
    cout << "Confirm purchase? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        cout << "Purchase confirmed." << endl;
    } else {
        cout << "Purchase cancelled." << endl;
    }
}


void ShowAllAlphabetically(Products ar[], int size) {

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (ar[j].getProductName().getString() > ar[j + 1].getProductName().getString()) {
                Products temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << "Product Name: " << ar[i].getProductName().getString()
             << ", Amount in Store: " << ar[i].getAmountInStore() << endl;
    }
}

int main() {
    Products products[100];


    for (int i = 0; i < 2; ++i) {
        EditInformationByKeyboard(products[i]);
    }

    for (int i = 2; i < 100; ++i) {
        generateInformationRandom(products[i], i);
    }

    ShowAllDiscount(products, 100);

    grossTotal(products, 100);

    ShowAllAlphabetically(products, 100);

    return 0;
}
