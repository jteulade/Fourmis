#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <QtGui>
#include <Monde.h>

class Graphique : public QGraphicsScene
{
public:
    Graphique();
    void dessinerRessource(QPoint courant,int nbCouleur=1);
    void dessinerFrequence(QPoint courant,QColor c);
    void dessinerDeparts(vector<QPoint> courants);
    void dessinerLignes(vector<QPoint> courants,vector<QPoint> suivants);
    void dessinerMonde(Monde *m);
    void afficher();


};

#endif // GRAPHIQUE_H
