
#include "products.h"
#include <iostream>
#include<string.h>

products::products()
{
    //ctor
}

products::~products()
{
    //dtor
}

Products::Products() : amountInStore(0), regularPrice(0.0), discountRate(0.0) {}

//getset
void Products::setProductName(const String& name) { productName = name; }
String Products::getProductName() const { return productName; }

void Products::setProductCategoryName(const String& category) { productCategoryName = category; }
String Products::getProductCategoryName() const { return productCategoryName; }

void Products::setProductDescription(const String& description) { productDescription = description; }
String Products::getProductDescription() const { return productDescription; }

void Products::setAmountInStore(int amount) { amountInStore = amount; }
int Products::getAmountInStore() const { return amountInStore; }

void Products::setRegularPrice(float price) { regularPrice = price; }
float Products::getRegularPrice() const { return regularPrice; }

void Products::setDiscountRate(float rate) { discountRate = rate; }
float Products::getDiscountRate() const { return discountRate; }

void Products::PurchaseProduct(int amount) {
    if (amount <= amountInStore) {
        amountInStore -= amount;
    } else {
        cout << "Not enough stock available." << endl;
    }
}

void Products::RestockProduct(int amount) {
    amountInStore += amount;
}

double Products::calculateDiscount(int amountOfProducts) const {
    float discount = 0.0;
    if (amountOfProducts >= 5) {
        discount = discountRate;
        if (amountOfProducts >= 10) {
            discount += 3.0;
        }
    }
    return (regularPrice * amountOfProducts * (discount / 100));
}

double Products::netTotal(int amountOfProducts) const {
    double discount = calculateDiscount(amountOfProducts);
    return (regularPrice * amountOfProducts) - discount;
}
