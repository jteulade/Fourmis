#include "constantes.h"
#include "Graphique.h"

Graphique::Graphique()
{
    addRect(0,0,TAILLE_FENETRE ,TAILLE_FENETRE,QPen(Qt::blue, 4));
    QGraphicsView *vue = new QGraphicsView(this);
    vue->resize(TAILLE_FENETRE+TAILLE_CASE,TAILLE_FENETRE+TAILLE_CASE);
    vue->show();
}
void Graphique::dessinerRessource(QPoint courant,int nbCouleur)
{
    QColor couleur;
    if (nbCouleur==1)
        couleur=Qt::red;
    else if (nbCouleur==2)
        couleur=Qt::green;
    else
        couleur=Qt::blue;
    addLine(QLine(courant*TAILLE_CASE,courant*TAILLE_CASE),QPen(couleur, 5));
}
void Graphique::dessinerFrequence(QPoint courant,QColor c)
{
    addLine(QLine(courant*TAILLE_CASE,courant*TAILLE_CASE),QPen(c, 10));
}

void Graphique::dessinerDeparts(vector<QPoint> courants)
{
    vector<QPoint> ::iterator itCourant=courants.begin();
    for (itCourant=courants.begin();itCourant!=courants.end();itCourant++)
    {
        addLine(QLine((*itCourant)*TAILLE_CASE,(*itCourant)*TAILLE_CASE),QPen(Qt::darkMagenta, 10, Qt::SolidLine, Qt::RoundCap));
    }
}

void Graphique::dessinerLignes(vector<QPoint> courants,vector<QPoint> suivants)
{
    vector<QPoint> ::iterator itCourant=courants.begin(), itSuivant=suivants.begin();
    while (itCourant!=courants.end() && itSuivant!=suivants.end())
    {
        addLine(QLine((*itCourant)*TAILLE_CASE,(*itSuivant)*TAILLE_CASE));
        itCourant++;
        itSuivant++;
    }

}

void Graphique::dessinerMonde(Monde *m)
{
    for (int i=0;i<NB_CASES;i++)
    {
        for (int j=0;j<NB_CASES;j++)
        {
            dessinerFrequence(QPoint(i,j),m->getTerrain(i,j)->getCouleur());
            if (!m->getTerrain(i,j)->estVide())
            {
                dessinerRessource(QPoint(i,j),m->getTerrain(i,j)->getRessource());
            }


        }
    }
}
