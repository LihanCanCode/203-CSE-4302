#include<iostream>

using namespace std;

class Temparature {
    private:
        int currentTemperature;
        int incrementStep;

    public:
        Temparature():currentTemperature(17),incrementStep(1) {}

        void setIncrementStep(int step) {
            incrementStep=step;
        }

        int getTemparature() const {
            return currentTemperature;
        }

        void increment() {
            currentTemperature+=incrementStep;
        }

        void resetTemparature() {
            currentTemperature=0;
        }

};
int main()
{
    Temparature temp;
    temp.setIncrementStep(10);
    //temp.increment();
    cout<<"Current Temparature: "<<temp.getTemparature() <<endl;
    temp.increment();
    cout<<"Current Temparature(After Increment): "<<temp.getTemparature() <<endl;
    temp.resetTemparature();
    cout<<"Current Temparature(After Reset): "<<temp.getTemparature() <<endl;

}
