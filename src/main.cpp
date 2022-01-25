#include "iostream"

#include "headers/planLibrary.h"

using namespace std;

int main() {
    auto* pl = new planLibrary("../planLibrary/pl1.csv");
    cout << pl->to_string() << endl;
    return 0;
}
