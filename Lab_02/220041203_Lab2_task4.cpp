
#include<iostream>
#include<string>

using namespace std;

struct Car
{
    string brand;
    string model;
    int year;
    string fueltype;
    double mile;
};

void display(const Car& c)
{
    cout<<"Brand: "<<c.brand<<endl;
    cout<<"Model: "<<c.model<<endl;
    cout<<"Year: "<<c.year<<endl;
    cout<<"Fuel Type: "<<c.fueltype<<endl;
    cout<<"Mileage: "<<c.mile<<"km/l"<<endl;
}

bool efficient( const Car& c, double last=15.0)
{
    return c.mile>last;
}

double fuelConsumption(const Car& c, double distance)
{
    return distance/c.mile;
}

double cost(const Car& c, double distance, double price)
{
    if (c.fueltype=="Electric")
    {
        cout<<"This car is electric, efficiency measured in km/charge.";
        return 0.0;
    }
    double cons = fuelConsumption(c, distance);
    return cons*price;
}


int main()
{
    int n=0;

    double distance=100.0;
    double price;
    cout<<"Enter the number of cars (at least 3): ";
    cin>>n;
    if(n<3){
        cout<<"You must enter at least 3 cars.";
        return 1;
    }

    Car* cars= new Car[n];

    for(int i=0; i<n ;i++)
    {
        cout<<"Enter details for car: "<< i+1 <<":"<<endl;
        cout<<"Brand : ";
        cin>> cars[i].brand;
        cout<<"Model : ";
        cin>>cars[i].model;
        cout<<"Year : ";
        cin>>cars[i].year;
        cout<<"Fuel Type : ";
        cin>>cars[i].fueltype;
        cout<<"Mileage (km/l) : ";
        cin>>cars[i].mile;
    }

    cout<<"Enter the fuel price per liter: ";
    cin>>price;

    for(int i=0; i<n; i++)
    {
        display(cars[i]);
        cout<<"Fuel efficient: ";
        if (efficient(cars[i]))
            cout << "This Car is Fuel Efficient" << endl;
        else
            cout << "This Car is Not Fuel Efficient" << endl;

        if(cars[i].fueltype!="Electric")
        {
            double fcost= cost(cars[i],distance,price);
            cout<< "Estimated Fuel cost for" << distance<< "km: $"<<fcost<<endl;
        }
        else cost(cars[i],distance,price);

        cout<<"------------------------"<<endl;

    }
     delete[] cars;

    return 0;

}
