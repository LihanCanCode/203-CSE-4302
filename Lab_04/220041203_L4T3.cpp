
#include <iostream>
#include <string>
#include<math.h>

using namespace std;

class Employee {
private:
    string EmpName;
    int ID;
    float BaseSalary;
    int JoiningYear;

    float calculateTotalSalary() const {
        int currentYear = 2024;
        int yearsOfService = currentYear - JoiningYear;
        float updatedBaseSalary = BaseSalary * pow(1.03, yearsOfService);
        float totalSalary = updatedBaseSalary + (0.50 * updatedBaseSalary);
        return totalSalary;
    }

    float calculateBonus(const string& status) const {
        int currentYear = 2024;
        float updatedBaseSalary = BaseSalary * pow(1.03, currentYear - JoiningYear);
        if (status == "Low")
            return 0.05 * updatedBaseSalary;
        else if (status == "Moderate")
            return 0.10 * updatedBaseSalary;
        else if (status == "High")
            return 0.15 * updatedBaseSalary;
        return 0.0;
    }

    string getStatus() const {
        int currentYear = 2024;
        int age = currentYear - JoiningYear;
        float totalSalary = calculateTotalSalary();

        if (age <= 25) {
            if (totalSalary <= 20000) {
                return "Low";
            } else {
                return "Moderate";
            }
        } else {
            if (totalSalary <= 21000) {
                return "Low";
            } else if (totalSalary <= 60000) {
                return "Moderate";
            } else {
                return "High";
            }
        }
    }

public:
    void FeedInfo(const string& name, int id, float salary, int year) {
        EmpName = name;
        ID = id;
        BaseSalary = salary;
        JoiningYear = year;
    }

    void ShowInfo() const {
        cout << "Employee Name: " << EmpName << endl;
        cout << "Employee ID: " << ID << endl;
        cout << "Base Salary: " << BaseSalary << endl;
        cout << "Joining Year: " << JoiningYear << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
        cout << "Status: " << getStatus() << endl;
        cout << "Bonus: " << calculateBonus(getStatus()) << endl;
    }
};

int main() {
    Employee emp;
    emp.FeedInfo("Tahsan Ferdous Lihan", 220041203, 18500, 1996);
    emp.ShowInfo();
    return 0;
}
