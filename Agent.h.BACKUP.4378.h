#ifndef AGENT_H
#define AGENT_H
//héhé hoho
#include "constantes.h"
#include <QtGui>
<<<<<<< HEAD
//ahah ou suis je qui suis je??
=======
//COucou jules, la peche
>>>>>>> experimental
class Agent
{
public:
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