#include "unordered_set"
#include "unordered_map"
#include "fstream"
#include "sstream"
#include "string"
#include "iostream"
#include "random"
#include "vector"
#include "map"

#include "rule.h"

using namespace std;

#ifndef PLAN_RECOGNITION_2_PLANLIBRARY_H
#define PLAN_RECOGNITION_2_PLANLIBRARY_H

class planLibrary {
public:
    planLibrary() = default;
    // nbGoal, plSize, nbChildren, constraintPercentage, depth, noise
    planLibrary(int, int, int, float, int, float);
    explicit planLibrary(const string&);
    ~planLibrary() = default;

    bool isTerminal(int);
    rule getRule(int i);
    int randGoal();

    string to_string();

private:
    unordered_set<int> terminals;
    unordered_set<int> non_terminals;
    unordered_set<int> goals;
    unordered_map<int, rule> rules;
    map<int, map<int, float>> noise;
};

#endif //PLAN_RECOGNITION_2_PLANLIBRARY_H
