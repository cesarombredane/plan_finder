#include "../headers/planLibrary.h"

planLibrary::planLibrary(int nbGoal, int plSize, int nbChildren, float constraintPercentage, int depth, float noise) {
    // TODO generate standard pl
}

planLibrary::planLibrary(const string& path) {
    ifstream ifs(path);
    string buffer_line;
    string buffer_token;


    getline(ifs, buffer_line);
    istringstream strTerminal(buffer_line);
    while (getline(strTerminal, buffer_token, ',')) this->terminals.insert(stoi(buffer_token));

    getline(ifs, buffer_line);
    istringstream str_non_terminal(buffer_line);
    while (getline(str_non_terminal, buffer_token, ',')) this->non_terminals.insert(stoi(buffer_token));

    this->rules[-1] = rule();
    while (getline(ifs, buffer_line)) {
        istringstream str_rule(buffer_line);

        getline(str_rule, buffer_token, ',');
        int primitive = stoi(buffer_token);

        vector<int> children;
        while (getline(str_rule, buffer_token, ',')) {
            if (buffer_token == "/") break;
            children.push_back(stoi(buffer_token));
        }

        int first = -1;
        vector<pair<int, int>> constraints;
        while (getline(str_rule, buffer_token, ',')) {
            if (first == -1) first = stoi(buffer_token);
            else {
                constraints.emplace_back(first, stoi(buffer_token));
                first = -1;
            }
        }

        this->rules[primitive] = rule(children, constraints);
    }

    ifs.close();
}

bool planLibrary::isTerminal(int symbol) {
    return this->terminals.count(symbol) > 0;
}

rule planLibrary::getRule(int primitive) {
    if (this->rules.count(primitive) > 0)
        return this->rules[primitive];
    return this->rules[-1];
}

int planLibrary::randGoal() {
    // TODO get random elem from goals
    return 1;
}

string planLibrary::to_string() {
    string str;

    str += "terminals=";
    for (int terminal : this->terminals)
        str += ::to_string(terminal) + ",";
    str += "\nnon_terminals=";
    for (int terminal : this->non_terminals)
        str += ::to_string(terminal) + ",";
    str += "\nrules=\n";
    for (const pair<const int, rule>& r : this->rules)
        str += ::to_string(r.first) + ":" + r.second.to_string() + "\n";

    return str;
}
