#include "vector"
#include "string"

using namespace std;

#ifndef PLAN_RECOGNITION_2_RULE_H
#define PLAN_RECOGNITION_2_RULE_H

class rule {
public:
    rule() = default;
    rule(vector<int>, vector<pair<int, int>>);
    ~rule() = default;

    vector<int> getChildren();

    string to_string() const;

private:
    vector<int> children;
    vector<pair<int, int>> constraints;
};

#endif //PLAN_RECOGNITION_2_RULE_H
