#include "duelacceptation.h"
#include "../destinLib/condition.h"
#include "profession.h"
#include "universskaven.h"

namespace EVT {
    NoeudProbable* DuelAcceptation(GenHistSkaven* genHist)
    {
        Condition* cond = new Condition(0.0, p_Relative);
        QList<Condition*> conditionVermine = {
            new Condition(UniversSkaven::CARAC_PROF, Profession::GetNomProfession(TypeProfession::Vermine_de_choc), Comparateur::c_Egal)
        };
        cond->AjouterModifProba(0.1, conditionVermine);
        QList<Condition*> conditionGuerrier = {
            new Condition(UniversSkaven::CARAC_PROF, Profession::GetNomProfession(TypeProfession::Guerrier_des_clans), Comparateur::c_Egal)
        };
        cond->AjouterModifProba(0.1, conditionGuerrier);
        Evt* evt = genHist->AjouterEvt("Duel d'acceptation");

        genHist->m_GenerateurEvt->AjouterEffetNarration("Un de vos frères d'armes vous juge trop faible pour mériter de servir dans son unité. Il vous déclare en duel pour vous forcer à prouver votre force et votre courage");

        NoeudProbable* noeudLieuProbable = new NoeudProbable(evt, cond);
        return noeudLieuProbable;
    }
}



