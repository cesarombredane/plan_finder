#include "vector"

#include "planLibrary.h"

using namespace std;

#ifndef PLAN_RECOGNITION_2_PLANRECOGNITION_H
#define PLAN_RECOGNITION_2_PLANRECOGNITION_H

class planParticle {
public:
    explicit planParticle(planLibrary*, int);
    ~planParticle() = default;

    void generateNextObs();

private:
    planLibrary* pl;
    vector<planParticle> children;
    int symbol;
    bool status;
    vector<int> nextObs;
};

class planRecognition {
public:
    planRecognition(planLibrary*, int);
    ~planRecognition() = default;

    void addObs(int);

private:
    planLibrary* pl;
    vector<int> prevObs;
    vector<planParticle>particles;
};

#endif //PLAN_RECOGNITION_2_PLANRECOGNITION_H
