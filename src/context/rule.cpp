#include "../headers/rule.h"

rule::rule(vector<int> _children, vector<pair<int, int>> _constraints):children(move(_children)),constraints(move(_constraints)) {}

vector<int> rule::getChildren() {
    return this->children;
}

string rule::to_string() const {
    string str;

    str += "{children=";
    for (int child : this->children)
        str += ::to_string(child) + ",";
    str += "constraint=";
    for (pair<int, int> constraint : this->constraints)
        str += "[" + ::to_string(constraint.first) + "," + ::to_string(constraint.second) + "]";
    str += "}";

    return str;
}
