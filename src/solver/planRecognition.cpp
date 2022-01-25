#include "../headers/planRecognition.h"

// planParticles
planParticle::planParticle(planLibrary* _pl, int _symbol):pl(_pl),symbol(_symbol),status(false) {
    rule r = this->pl->getRule(this->symbol);

    for (auto& child : r.getChildren())
        this->children.emplace_back(this->pl, child);
}

void planParticle::generateNextObs() {
    // TODO generate next obs
}

// planRecognition
planRecognition::planRecognition(planLibrary* _pl, int nbParticles):pl(_pl) {
    for (int i = 0; i < nbParticles; ++i)
        this->particles.emplace_back(planParticle(this->pl, this->pl->randGoal()));

    for (auto& particle : this->particles)
        particle.generateNextObs();
}

void planRecognition::addObs(int obs) {
    this->prevObs.push_back(obs);

    // TODO update
}
