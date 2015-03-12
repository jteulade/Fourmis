#include "Agent.h"

Agent::Agent()
{
    //position=QPoint(15,15);
    position=tireCaseAleatoire();
    ressourceTenue=0;
}


void Agent::setPosition(QPoint nPosition)
{
    position=nPosition;
}
void Agent::deplace(QPoint dep)
{
    position+=dep;
}

QPoint Agent::getPosition()
{
    return position;
}
void Agent::setRessource(int nRessource)
{
    ressourceTenue=nRessource;
}

int Agent::getRessource()
{
    return ressourceTenue;
}

bool Agent::possedeRessource()
{
    return (ressourceTenue!=0);
}

int tireAleatoire(int a)
{
    return rand()%a;
}
QPoint tireCaseAleatoire()
{
    return QPoint(tireAleatoire(NB_CASES-1)+1,tireAleatoire(NB_CASES-1)+1);
}


