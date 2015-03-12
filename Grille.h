#ifndef GRILLE_H
#define GRILLE_H

#include "constantes.h"
#include "Graphique.h"
#include <QtGui>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
class Grille
{
public:
    Grille(int nbRessources=650);

    int getCase(QPoint courant);
    void setCase(QPoint courant,int n);
    void init(int nbRessources);
    bool appartientGrille (QPoint courant);
    QPoint marcheAleatoire(QPoint courant);
    int capteurRessource(QPoint courant,int numeroRessource);
    void dessiner(Graphique *scene);
private:
    int carte[NB_CASES][NB_CASES];
};
    int tireAleatoire(int a);

#endif // GRILLE_H
