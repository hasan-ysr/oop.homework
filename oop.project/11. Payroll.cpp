#include <iostream>
using namespace std;

class payrate {
private:
    double hourlyPay;
    double hoursWork;

public:
    void setHourlyPayRate(double rate) {
        hourlyPay = rate;
    }

    void setHoursWorked(double hours) {
        if (hours <= 60) {
            hoursWork = hours;
        } else {
            hoursWork = 60;
        }
    }

    double TotalPay() {
        return hourlyPay * hoursWork;
    }
};

int main() {
    const int NUM_EMPLOYEES = 7;
    payrate employees[NUM_EMPLOYEES];
    double hours, payRate;

    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "Enter the number of hours worked  " << i + 1 << ": ";
        cin >> hours;
        employees[i].setHoursWorked(hours);
    }

    cout << "\n Enter the employee's hourly rate :" << endl;
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "Employee " << i + 1 << ": ";
        cin >> payRate;
        employees[i].setHourlyPayRate(payRate);
    }

    cout << "\nGross pay for each employee:" << endl;
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "Employee :" << i + 1  << employees[i].TotalPay() << " $" <<endl;
    }

    return 0;
}
