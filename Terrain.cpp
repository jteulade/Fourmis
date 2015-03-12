#include "Terrain.h"

Terrain::Terrain()
{
    ressource=0;
    tour=0;
    couleur=Qt::white;
}

QColor Terrain::getCouleur()
{
    return couleur;
}

int Terrain::getRessource()
{
    return ressource;
}

void Terrain::setRessource(int nRess)
{
    ressource=nRess;
}

bool Terrain::estVide()
{
    return (ressource==0);
}

void Terrain::augmenterCouleur()
{
    if (couleur.red()==0)
        return;
    if (tour==0)
        couleur.setRed(couleur.red()-1);
    else if (tour==1)
        couleur.setBlue(couleur.blue()-1);
    else
        couleur.setGreen(couleur.green()-1);
    tour=(tour+1)%3;
}
