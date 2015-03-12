#ifndef TERRAIN_H
#define TERRAIN_H
#include "constantes.h"
#include <QtGui>
class Terrain
{
public:
    Terrain();
    QColor getCouleur();
    int getRessource();
    void setRessource(int nRess);
    bool estVide();
    void augmenterCouleur();
private:
    QColor couleur;
    int ressource;
    int tour;  //n'a pas sa place ici
    
};

#endif // TERRAIN_H
