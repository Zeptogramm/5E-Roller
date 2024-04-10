#include <iostream>
#include <random> 
#include <ctime>  

using namespace std;

void roll(int mod, mt19937& rng)
{
    uniform_int_distribution<int> d20_distribution(1, 20);
    int d20 = d20_distribution(rng);

    if (d20 == 20)
    {
        cout << "NATURAL 20" << endl;
    }
    else if (d20 == 1)
    {
        cout << "Critical Failure: 1" << endl;
    }
    else
    {
        d20 += mod;
        cout << d20 << endl;
    }
}

int main()
{
    mt19937 rng(random_device{}()); // Mersenne Twister random number engine
    int minionNum;
    int rmod;
    int count = 0;

    cout << "How many minions are attacking?" << endl;
    while (!(cin >> minionNum) || minionNum <= 0)
    {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "What is their roll to hit modifier?" << endl;
    while (!(cin >> rmod))
    {
        cout << "Must be a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl;

    while (count < minionNum)
    {
        roll(rmod, rng);
        count++;
    }
    return 0;
}
