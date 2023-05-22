#include <iostream>

#include "array.h"

#include <iostream>
#include <random>

using namespace std;

int main() {
    Array<double> a(10);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 100.0);


    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = dist(mt);

    cout << "Zawartosc a: " << endl;
    cout << a << endl;

    return 0;
}
