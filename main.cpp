#include <QApplication>


#include "constantes.h"
#include "Graphique.h"
#include "Monde.h"


void parcoursAleatoire(Graphique *scene)
{
    Monde m(10);
    vector<QPoint> courants;
    /*Graphique *sceneInit=  new Graphique;
    sceneInit->dessinerMonde(&m);*/

    for (int i=0;i<50000;i++)
    {

        //courants=m.getPositions();
        //cout<<endl<<i<<") ";
        m.action();
        //scene->dessinerLignes(courants,m.getPositions());
    }
    scene->dessinerMonde(&m);
    //scene->dessinerDeparts(m.getPositions());

}

void distributionRessources(Graphique *scene)
{
    Monde *m = new Monde;
    scene->dessinerMonde(m);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    srand(time(NULL));
     Graphique *scene=  new Graphique;
    parcoursAleatoire(scene);
    //distributionRessources(scene);
    return app.exec();
    
}

