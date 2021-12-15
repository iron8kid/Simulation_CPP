#include <iostream>
#include "VisiteurDeplacement.h"

void VisiteurDeplacement::visitGregaire(const Gregaire *c, Bestiole *b)
{
    std::cout << "Visiting Gregaire" << std::endl;
    b->setOrientation(c->meanOrientation(b->getMilieu(),*b));
}

void VisiteurDeplacement::visitPeureuse(const Peureuse *c, Bestiole *b)
{
    std::cout << "Visiting Peureuse " << std::endl;
    if (b->getEscape() && !(c->checkNeighbours(b->getMilieu(), *b)))
    {
        b->setEscape(false);
        b->accelerate(false);
    }
    else if(c->checkNeighbours(b->getMilieu(), *b) && !(b->getEscape()))
    {
        b->setOrientation(-b->getOrientation());
        b->setEscape(true);
        b->accelerate(true);
    }


}


void VisiteurDeplacement::visitKamikaze(const Kamikaze *c, Bestiole *b)
{
    std::cout << "Visiting " << std::endl;
}

void VisiteurDeplacement::visitPrevoyante(const Prevoyante *c, Bestiole *b)
{
    std::cout << "Visiting " << std::endl;
}