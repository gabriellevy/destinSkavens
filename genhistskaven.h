#ifndef GENHISTSKAVEN_H
#define GENHISTSKAVEN_H

#include "../destinLib/genhistoire.h"

class UniversSkaven;

class GenHistSkaven : public GenHistoire
{
private:
    void GenererEvtsAccueil();
    void GenererSelectionneurRegulier();
    virtual void GenererFonctionsCallback();
    virtual void GenererPersos();

public:
    GenHistSkaven(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();

    UniversSkaven* GetUniversSkaven();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
    /**
     * @brief fonction de sélection de clan : tous els clans ont le même pourcentage de chance d'être sélectionné
     */
    Effet* GenererEffetSelectionClan();
    Effet* GenererEffetSelectionLieu();
    Effet* GenererEffetSelectionFourrure();

    Effet* GenererEffetSelectionMetier();

    // événements de narration (vie courante)
    NoeudProbable* GenererSacrificeAuRatCornu();
    NoeudProbable* GenererGuerreCivileDeClan();
    NoeudProbable* DuelAcceptation();
};

#endif // GENHISTSKAVEN_H
