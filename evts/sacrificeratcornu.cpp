#include "sacrificeratcornu.h"
#include "../destinLib/condition.h"

namespace EVT {
    NoeudProbable* GenererSacrificeAuRatCornu(GenHistSkaven* genHist)
    {
        Condition* cond = new Condition(0.05, p_Relative);
        Evt* evt = genHist->AjouterEvt("Sacrifice au rat cornu", "Sacrifice au rat cornu");

        genHist->m_GenerateurEvt->AjouterEffetNarration("C'est jour de fête dans tout le terrier ! Un grand sacrifice au rat cornu, votre dieu suprême, va être réalisé.");

        NoeudProbable* noeudLieuProbable = new NoeudProbable(evt, cond);
        return noeudLieuProbable;
    }
}
