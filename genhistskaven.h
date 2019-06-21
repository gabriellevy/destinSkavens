#ifndef GENHISTSKAVEN_H
#define GENHISTSKAVEN_H

#include "../destinLib/genhistoire.h"


class GenHistSkaven : public GenHistoire
{
private:
    void GenererEvtsAccueil();
    virtual void GenererFonctionsCallback();
    virtual void GenererPersos();

public:
    GenHistSkaven(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();
};

#endif // GENHISTSKAVEN_H
