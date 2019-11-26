#include "guerrecivileclan.h"
#include "../destinLib/condition.h"

namespace EVT {
    NoeudProbable* GenererGuerreCivileDeClan(GenHistSkaven* genHist)
    {
        Condition* cond = new Condition(0.005, p_Relative);
        Evt* evt = genHist->AjouterEvt("GuerreCivileDeClan", "GuerreCivileDeClan");

        genHist->m_GenerateurEvt->AjouterEffetNarration("Une terrible rébellion s'est déclenché dans votre clan.");

        NoeudProbable* noeudLieuProbable = new NoeudProbable(evt, cond);
        return noeudLieuProbable;
    }
}

