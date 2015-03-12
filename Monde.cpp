#include "Monde.h"
#include <math.h>

Monde::Monde(int nbAgent, int nbRessources)
{
    indice[0]=0;
    indice[1]=0;
    indice[2]=0;
    indice[3]=0;
    for (int i=0;i<NB_CASES;i++)
    {
        for (int j=0;j<NB_CASES;j++)
        {
            carte[i][j]=new Terrain;
        }
    }
    dispositionRessources(nbRessources);
    for (int i=0;i<nbAgent;i++)
        listAgent.push_back(new Agent);

}

Monde::~Monde()
{
    for (int i=0;i<NB_CASES;i++)
    {
        for (int j=0;j<NB_CASES;j++)
        {
            delete(carte[i][j]);
        }
    }
    vector<Agent*> ::iterator it;
    for (it=listAgent.begin();it!=listAgent.end();it++)
        delete(*it);
}

Terrain* Monde::getTerrain(QPoint courant)
{
    return carte[courant.x()][courant.y()];
}
Terrain* Monde::getTerrain(int i, int j)
{
    return carte[i][j];
}
void Monde::setTerrain(QPoint courant,Terrain *t)
{
    carte[courant.x()][courant.y()]=t;
}


vector<QPoint> Monde::getPositions()
{
    vector<QPoint> res;
    vector<Agent*> ::iterator it;
    for (it=listAgent.begin();it!=listAgent.end();it++)
        res.push_back((*it)->getPosition());
    return res;

}

void Monde::dispositionRessources(int nbRessources)
{
    int nbMyst1;
    int nbMyst2;
    int ressource=1;
    int cpt=0;
    while (nbRessources>0)
    {
        nbMyst1=tireAleatoire(NB_CASES-1)+1;
        nbMyst2=tireAleatoire(NB_CASES-1)+1;
        if (carte[nbMyst1][nbMyst2]->estVide())
        {
            carte[nbMyst1][nbMyst2]->setRessource(ressource);
            ressource=ressource%3+1;
            nbRessources--;
        }
        cpt++;
    }
}

bool Monde::appartientTerrain (QPoint courant)
{
    return (courant.x()>0 && courant.y()>0 && courant.x()<NB_CASES && courant.y()<NB_CASES);
}
void Monde::marcheAleatoire(Agent *a)
{
    double distEucl;
    double m=10;
    double proba[3][3];
    double sommeMu=0;
    double mu;
    QPoint caseAttr;

    QPoint voisin;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            voisin=a->getPosition()+QPoint(i-1,j-1);
            if (!(i==1 && j==1) && appartientTerrain(voisin))
            {
                proba[i][j]=1/.8;
                sommeMu+=1/.8;
                for (int k=0;k<40;k++)
                {
                    caseAttr=casesAttr[a->getRessource()][k];
                    distEucl=sqrt(pow(caseAttr.x()-voisin.x(),2) + pow(caseAttr.y()-voisin.y(),2));
                    //cout<<distEucl<<endl;
                    mu=fmax(0,m*(1-distEucl/20));
                    //cout<<mu<< " ; ";
                    proba[i][j]+= mu;
                    sommeMu+=mu;
                }
            }
            else
                proba[i][j]=0;
            //cout<<voisin.x()<<","<<voisin.y()<<"->"<<proba[i][j]<<endl;
        }
    }

    double nbMyst=(double) rand()/RAND_MAX;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            proba[i][j]/=sommeMu;
            //cout<<proba[i][j]<<" ; ";
            nbMyst-=proba[i][j];
            if (nbMyst<0)
            {
                a->deplace(QPoint(i-1,j-1));
                return;
            }
        }
    }
}

int Monde::capteurRessource(QPoint courant,int numeroRessource)
{
    int res=0;
    for (int i=-1;i<=1;i++)
    {
        for (int j=-1;j<=1;j++)
        { 

            if ((i!=0 || j!=0) && appartientTerrain(courant+QPoint(i,j)) && (getTerrain(courant+QPoint(i,j))->getRessource()==numeroRessource))
            {
                res++;
            }
        }
    }
    //cout<<"position: "<<courant.x()<<","<<courant.y()<<"   ressource: "<<numeroRessource<<"   nbre: "<<res<<endl;
    return res;
}
bool Monde::priseRessource(Agent *a)
{
    int ressource=getTerrain(a->getPosition())->getRessource();
    double proba=1-((double)capteurRessource(a->getPosition(),ressource))/8;
    double nbMyst=(double) rand()/RAND_MAX;
    //cout<<"je voudrais prendre la ressource mais proba="<<proba<<" et nbMyst="<<nbMyst<<endl;
    if (nbMyst<=proba)
    {
        //cout<<"je prend la ressource "<<ressource<<endl;
        getTerrain(a->getPosition())->setRessource(0);
        a->setRessource(ressource);
        casesAttr[0][indice[0]]=a->getPosition();
        indice[0]=(indice[0]+1)%20;
        return true;
    }
    return false;
}
bool Monde::poseRessource(Agent *a)
{
    int ressource = a->getRessource();
    double proba=((double)capteurRessource(a->getPosition(),ressource))/8;
    double nbMyst=(double) rand()/RAND_MAX;

    //cout<<"je voudrais poser la ressource mais proba="<<proba<<" et nbMyst="<<nbMyst<<endl;
    if (nbMyst<=proba)
    {
        //cout<<"je pose la ressource "<<ressourceTenue<<endl;
        getTerrain(a->getPosition())->setRessource(ressource);
        casesAttr[ressource][indice[ressource]]=a->getPosition();
        indice[ressource] = (indice[ressource]+1)%20;
        a->setRessource(0);       
        return true;
    }
    return false;
}

void Monde::action()
{
    bool b=false;
    ///cout<<"taille des liste = "<<casesAttr[0].size()<<" "<<casesAttr[1].size()<<" "<<casesAttr[2].size()<<" "<<casesAttr[3].size()<<" "<<endl;
    for (vector<Agent*>::iterator it=listAgent.begin();it!=listAgent.end();it++)
    {
        getTerrain((*it)->getPosition())->augmenterCouleur();

        if ((!(*it)->possedeRessource()) && !(getTerrain((*it)->getPosition())->estVide()))
        {
            b=priseRessource(*it);
        }
        else if ((*it)->possedeRessource() && getTerrain((*it)->getPosition())->estVide())
        {
            b=poseRessource(*it);
        }
        if (!b)
            marcheAleatoire(*it);
    }


}
