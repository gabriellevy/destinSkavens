#ifndef PROFESSION_H
#define PROFESSION_H

#include <QString>

#include "../destinLib/condition.h"

enum class TypeProfession : char {
    Cultivateur_de_champignons = 0,
    Batisseur_de_taudis,
    Mineur,
    Gardien_de_nourissons,
    Recolteur_de_nourriture_des_marais,
    Docker,
    Servant_de_machine_Skyre,
    Garde_d_esclave,
    Entreteneur_de_galerie,
    Espion_chez_les_autres_clans_skavens,
    Espion_dans_le_monde_de_la_surface,
    Preparateur_de_drogues,
    Ingenieur,
    Observateur_et_chasseur_de_malepierre,
    Raffineur_de_malepierre,
    Coureur_d_egouts,
    Assassin,
    Vermine_de_choc,
    Guerrier_des_clans,
    Moine_de_la_peste,
    Pretre_de_la_peste,
    Maitre_corrupteur,
    Chef_de_meute,
    Technomage,
    Prophete_gris,
    NombreTotal // garder ça à la fin
};

class Profession
{
public:
    // constructeur générant une profession aléatoire
    Profession(TypeProfession typeProfession);

    TypeProfession m_TypeProfession;
    QString m_Nom;
    QString m_Description;
    int m_StatutSocial;

    // condition à respecter pour pouvoir avoir cette profession
    QList<Condition*> m_Conditions = {};

    /**
     * @brief condition calculant le pourcentage de chances d'avoir ce métier directement à la majorité
     */
    Condition* m_PoidsProba = nullptr;

    static QString GetNomProfession(TypeProfession typeProfession);
};

#endif // PROFESSION_H
