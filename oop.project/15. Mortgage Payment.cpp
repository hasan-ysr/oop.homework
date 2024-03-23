#include <iostream>
#include <cmath>

using namespace std;

class Mortgage {
private:
    double Debt;
    double rate;
    int years;

public:
    Mortgage(double a = 0.0, double b = 0.0, int c = 0) : Debt(a), rate(b), years(c) {}

    void setDebt(double l) {
        Debt = l;
    }

    void setRate(double r) {
        rate = r;
    }

    void setYears(int y) {
        years = y;
    }

    double monthlypayment() const {
        double monthlyrate = rate / 12 / 100;
        int n = years * 12;
        double payment = (Debt * monthlyrate) / (1 - pow(1 + monthlyrate, -n));
        return payment;
    }

    double totalpay() const {
        return monthlypayment() * years * 12;
    }
};

int main() {
    double Debtamount, interestrate;
    int borrowyears;

    cout << "How much your debt : ";
    cin >> Debtamount;

    cout << "How much is the annual interest rate : ";
    cin >> interestrate;

    cout << "How many years you borrowed the money for : ";
    cin >> borrowyears;

    Mortgage mortgage(Debtamount, interestrate, borrowyears);

    cout << "\nMonthly payment : " << mortgage.monthlypayment() << " $" << endl;
    cout << "total amount to pay : " << mortgage.totalpay() << " $" << endl;

    return 0;
}
