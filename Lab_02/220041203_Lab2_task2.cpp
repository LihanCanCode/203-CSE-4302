
#include<iostream>

using namespace std;

enum etype {laborer, secretary,manager, accountant, executive, researcher};

int main()
{
    char ch;
    etype employee;

    cout<<"Enter employee type (first letter only): \n";

    cin>>ch;
    switch (ch)
    {
        case 'l':
             employee=laborer;
             break;
        case 's':
            employee=secretary;
             break;
        case 'm':
            employee=manager;
            break;
        case 'a':
            employee=accountant;
             break;
        case 'e':
             employee=executive;
             break;
        case 'r':
             employee=researcher;
             break;
        default:
            cout<<"Invalid input"<<endl;

    }

        cout<<"Employee type is ";

        switch(employee)
        {
            case laborer: cout<<"laborer"; break;
            case secretary: cout<<"secretary"; break;
            case manager: cout<<"manager"; break;
            case accountant: cout<<"accountant"; break;
            case executive: cout<<"executive"; break;
            case researcher: cout<<"researcher"; break;
        }
        cout<<"."<<endl;

        return 0;
}



