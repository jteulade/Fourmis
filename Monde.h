#ifndef MONDE_H
#define MONDE_H

#include "Agent.h"
#include "constantes.h"
#include "Terrain.h"

#include <vector>

class Monde
{
public:
    Monde(int nbAgent =1,int nbRessources=650);
    ~Monde();

    Terrain* getTerrain(QPoint courant);
    Terrain* getTerrain(int i, int j);
    void setTerrain(QPoint courant,Terrain *t);


    vector<QPoint> getPositions();
    void dispositionRessources(int nbRessources);
    bool appartientTerrain (QPoint courant);
    void marcheAleatoire(Agent *a);
    int capteurRessource(QPoint courant,int numeroRessource);
    bool priseRessource(Agent *a);
    bool poseRessource(Agent *a);
    void action();
private:
    vector<Agent*> listAgent;
    Terrain* carte[NB_CASES][NB_CASES];
    QPoint casesAttr[4][20]; //0->case attractive pour la prise, 1,2 et 3 attractive pour le dépot des ressources 1, 2 et 3
    int indice[4];

};;


#endif // MONDE_H
