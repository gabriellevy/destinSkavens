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
};

#endif // GENHISTSKAVEN_H
