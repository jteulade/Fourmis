#ifndef AGENT_H
#define AGENT_H

#include "constantes.h"
#include <QtGui>
//COucou jules, la peche
class Agent
{
public:
  //aaa
    Agent();
    void setPosition(QPoint nPosition);
    void deplace(QPoint dep);
    QPoint getPosition();
    void setRessource(int nRessource);
    int getRessource();
    bool possedeRessource();

private:
    QPoint position;
    int ressourceTenue; //0 si pas de ressource tenue.
};
int tireAleatoire(int a);
QPoint tireCaseAleatoire();

#endif // AGENT_H
