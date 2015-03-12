#include "constantes.h"
#include "Grille.h"
#include "Graphique.h"

Grille::Grille(int nbRessources)
{   
    for (int i=0;i<NB_CASES;i++)
    {
        for (int j=0;j<NB_CASES;j++)
        {
            carte[i][j]=0;
        }
    }
    init(nbRessources);
}

int Grille::getCase(QPoint courant)
{
    return carte[courant.x()][courant.y()];
}
void Grille::setCase(QPoint courant,int n)
{
    carte[courant.x()][courant.y()]=n;
}

void Grille::init(int nbRessources)
{
    int nbMyst1;
    int nbMyst2;
    int ressource=1;
    int cpt=0;
    while (nbRessources>=0)
    {
        nbMyst1=tireAleatoire(NB_CASES-1)+1;
        nbMyst2=tireAleatoire(NB_CASES-1)+1;
        if (carte[nbMyst1][nbMyst2]==0)
        {
            carte[nbMyst1][nbMyst2]=ressource;
            ressource=ressource%3+1;
            nbRessources--;
        }
        cpt++;
    }
    cout<<cpt<<endl;
}

bool Grille::appartientGrille (QPoint courant)
{
    return (courant.x()>0 && courant.y()>0 && courant.x()<NB_CASES && courant.y()<NB_CASES);
}

QPoint Grille::marcheAleatoire(QPoint courant)
{
    int nbMyst1=tireAleatoire(3)-1;
    int nbMyst2=tireAleatoire(3)-1;
    if (nbMyst1==0 && nbMyst2==0)
        return marcheAleatoire(courant);
    else if (appartientGrille(courant+QPoint(nbMyst1,nbMyst2)))
        return courant+QPoint(nbMyst1,nbMyst2);
    else
        return marcheAleatoire(courant);
}

int Grille::capteurRessource(QPoint courant,int numeroRessource)
{
    int res=0;
    for (int i=-1;i<=1;i++)
    {
        for (int j=-1;j<=1;j++)
        {
            if ((i!=0 || j!=0) && (getCase(courant+QPoint(i,j))==numeroRessource))
            {
                res++;
            }
        }
    }
    //cout<<"position: "<<courant.x()<<","<<courant.y()<<"   ressource: "<<numeroRessource<<"   nbre: "<<res<<endl;
    return res; 
}

void Grille::dessiner(Graphique *scene)
{
    for (int i=0;i<NB_CASES;i++)
    {
        for (int j=0;j<NB_CASES;j++)
        {
            if (carte[i][j]!=0)
            {
                scene->dessinerPoint(QPoint(i,j),carte[i][j]);
            }
        }
    }
}

int tireAleatoire(int a)
{
    return rand()%a;
}
