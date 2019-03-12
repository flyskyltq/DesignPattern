#include "Observer.h"

void ObserverA::update(Subject* sub) {
    std::cout << "ObserverA Update:" << sub->getStates().c_str() << std::endl;
}

void ObserverB::update(Subject* sub) {
    std::cout << "ObserverB Update:" << sub->getStates().c_str() << std::endl;
}