#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class coins {
private:
    string coinflip;

public:
    coins() {
        toss();
    }

    void toss() {
        if (rand() % 2 == 0) {
            coinflip = "heads";
        } else {
            coinflip = "tails";
        }
    }

    string getcoinflip() const {
        return coinflip;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    coins quarter, dime, nickel;
    double totalBalance = 0.0;

    while (totalBalance < 1.0) {
        quarter.toss();
        dime.toss();
        nickel.toss();

        if (quarter.getcoinflip() == "heads") {
            totalBalance += 0.25;
        }
        if (dime.getcoinflip() == "heads") {
            totalBalance += 0.10;
        }
        if (nickel.getcoinflip() == "heads") {
            totalBalance += 0.05;
        }

        cout << "Your total: " << totalBalance << "$"<< endl;
    }

    if (totalBalance == 1.0) {
        cout << "You win the game." << endl;
    } else {
        cout << "I win the game. HAHAHA!" << endl;
    }

    return 0;
}
