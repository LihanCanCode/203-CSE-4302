
#include<iostream>
#include<string>
#include<vector>


using namespace std;

class product{

    private:
        string name;
        int id;
        double price;
        int quantity;
        int maxQuantity;

    public:
        product(string name, int id, double price, int quantity, int maxQuantity)
            : name(name),id(id),price(price),quantity(quantity),maxQuantity(maxQuantity){}

        void add(int added) {
            if (quantity + added <= maxQuantity)
                quantity += added;
            else
                cout << "Cannot add more than max quantity." << endl;
        }

        bool isAvailable() {
            return quantity > 0;
        }

        void purchase(int purchased){
            if(isAvailable() && purchased<=quantity)
                quantity-=purchased;
            else
                cout<<"Not enough quantity available"<<endl;

        }

        void updatePrice(int discount) {
            price-=price*discount/100.0;
        }

        void displayValue(){
            cout<<"Inventory Value: "<<quantity*price<<endl;
        }

        void displayDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Quantity: "<<quantity<<endl;
            cout<<"Availability Status : "<<(isAvailable() ? "Available" : "Not Available")<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
        }

        static void displayTotalInventoryValue(const vector<product>& products) {
            double totalValue = 0;
            for (const auto& product : products) {
                totalValue += product.quantity * product.price;
            }
            cout << "\nTotal Inventory Value: " << totalValue << endl;
        }

};

int main()
{
    product product1("Ice Cream", 201, 50.0, 10, 100);
    product1.add(20);
    product1.purchase(2);
    product1.updatePrice(5);
    product1.displayValue();
    product1.displayDetails();

    product product2("Drinko", 202, 30.0, 15, 100);
    product product3("Biscuits", 203, 20.0, 25, 100);

    product2.displayValue();
    product2.displayDetails();


    product3.displayValue();
    product3.displayDetails();

    vector<product> products = {product1, product2, product3};
    product::displayTotalInventoryValue(products);

    return 0;
}
