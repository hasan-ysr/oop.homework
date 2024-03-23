#include <iostream>

using namespace std;

class Population {
private:
    int populationSize;
    int births;
    int deaths;
public:
    Population(int size) : populationSize(size), births(0), deaths(0) {}

    void setBirths(int num) {
        births = num;
    }
    void setDeaths(int num) {
        deaths = num;
    }
    double birthRate()  {
        return static_cast<double>(births) / populationSize;
    }
    double deathRate()  {
        return static_cast<double>(deaths) / populationSize;
    }
};
int main() {
    int populationSize ,numBirths, numDeaths ;
    cout << "Please enter the number of your population:";
    cin >> populationSize;
    Population population(populationSize);

    cout << "Please enter the number of births in the population:";
    cin >> numBirths;
    population.setBirths(numBirths);

    cout << "Please enter the number of deaths in the population:";
    cin >> numDeaths;
    population.setDeaths(numDeaths);

    cout << "Birth rate : " << population.birthRate() << endl;
    cout << "Death rate : " << population.deathRate() << endl;

    return 0;
}
