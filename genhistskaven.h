#ifndef GENHISTSKAVEN_H
#define GENHISTSKAVEN_H

#include "../destinLib/genhistoire.h"

class UniversSkaven;

class GenHistSkaven : public GenHistoire
{
private:
    void GenererEvtsAccueil();
    virtual void GenererFonctionsCallback();
    virtual void GenererPersos();

public:
    GenHistSkaven(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();

    UniversSkaven* GetUniversSkaven();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
    Effet* GenererEffetSelectionMetier();
};

#endif // GENHISTSKAVEN_H
