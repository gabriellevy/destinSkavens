#include "arme.h"
#include "../destinLib/condition.h"
#include "profession.h"
#include "universskaven.h"

namespace EVT {
    NoeudProbable* RecompenseArmeSkyre(GenHistSkaven* genHist)
    {
        Condition* cond = new Condition(0.0, p_Relative);
        QList<Condition*> conditionStatut = {
            new Condition(UniversSkaven::CARAC_STATUT, "250", Comparateur::c_Superieur)
        };
        cond->AjouterModifProba(0.01, conditionStatut);
        QList<Condition*> conditionClan = {
            new Condition(UniversSkaven::CARAC_STATUT, "250", Comparateur::c_Superieur),
            new Condition(UniversSkaven::CARAC_CLAN, Clan::GetNomClan(TypeClan::Skyre), Comparateur::c_Egal)
        };
        cond->AjouterModifProba(0.01, conditionClan);

        Evt* evt = genHist->AjouterEvt("Duel d'acceptation");

        genHist->m_GenerateurEvt->AjouterEffetNarration(
                    "Pour vous faire honneur et vous rendre plus redoutable encore le clan vous offre une arme de haute technologie skaven. Puisse-t'elle anéantir vos ennemis.");

        NoeudProbable* noeudLieuProbable = new NoeudProbable(evt, cond);
        return noeudLieuProbable;
    }
}

Arme::Arme(TypeArme typeArme):m_TypeArme(typeArme)
{
    this->m_Nom = Arme::GetNomArme(m_TypeArme);
}

QString Arme::GetNomArme(TypeArme typeArme)
{
    switch (typeArme) {
    case TypeArme::Attrapechoses : return "Attrape-choses";
    case TypeArme::Globe_Vent_Toxique : return "Globe de Vent Toxique";
    case TypeArme::Malelame : return "Malelame";
    case TypeArme::Pistolet_Malepierre : return "Pistolet à Malepierre";

    }
    return "";
}
