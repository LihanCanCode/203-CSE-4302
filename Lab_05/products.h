#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include<string.h>

using namespace std;

class products
{
    public:
        products();
        virtual ~products();

    protected:

    private:
};

class String {
private:
    string str;
public:
    String(const string& s = "") : str(s) {}
    void setString(const string& s) { str = s; }
    string getString() const { return str; }
    void display() const { cout << str << endl; }
};

class Products {
private:
    String productName;
    String productCategoryName;
    String productDescription;
    int amountInStore;
    float regularPrice;
    float discountRate;

public:

    Products();

    //getset
    void setProductName(const String& name);
    String getProductName() const;

    void setProductCategoryName(const String& category);
    String getProductCategoryName() const;

    void setProductDescription(const String& description);
    String getProductDescription() const;

    void setAmountInStore(int amount);
    int getAmountInStore() const;

    void setRegularPrice(float price);
    float getRegularPrice() const;

    void setDiscountRate(float rate);
    float getDiscountRate() const;

    void PurchaseProduct(int amount);
    void RestockProduct(int amount);

    double calculateDiscount(int amountOfProducts) const;

    double netTotal(int amountOfProducts) const;
};

#endif // PRODUCTS_H

