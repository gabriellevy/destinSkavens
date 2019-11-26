#include "universskaven.h"
#include "ui_univers.h"
#include "genhistskaven.h"
#include <QTime>

QString UniversSkaven::VIE_SKAVEN = "Vie Skaven";

UniversSkaven::UniversSkaven(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(54, 46, 43));


    m_GensHistoire[UniversSkaven::VIE_SKAVEN] = new GenHistSkaven();

    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
}

QString UniversSkaven::CARAC_CLAN = "Clan";
QString UniversSkaven::CARAC_PROF = "Profession";
QString UniversSkaven::CARAC_LIEU = "Lieu";
QString UniversSkaven::CARAC_FOURRURE = "Fourrure";
QString UniversSkaven::CARAC_TAILLE = "Taille";
QString UniversSkaven::CARAC_STATUT = "Statut";
QString UniversSkaven::CARAC_MALEPIERRE = "Malepierre";
QString UniversSkaven::CARAC_PEUR = "Peur";

Hist* UniversSkaven::ExecuterGenerateurHistoire()
{
    m_Histoire = new Hist("Vie de Skaven");
    //m_GenHistoire = new GenHistSkaven(m_Histoire);
    //m_GenHistoire->GenererHistoire();
    this->setWindowTitle(m_Histoire->m_Titre);

    return m_Histoire;
}

void UniversSkaven::GenererProfession(TypeProfession typeProfession)
{
    Profession* profession = new Profession(typeProfession);
    m_TousLesProfessions.push_back(profession);
}

void UniversSkaven::GenererLieu(TypeLieu typeLieu)
{
    Lieu* lieu = new Lieu(typeLieu);
    m_TousLesLieux.push_back(lieu);
}

void UniversSkaven::GenererClan(TypeClan typeClan, float puissance, QString description, QString chemin)
{
    Clan* clan = new Clan(typeClan, Clan::GetNomClan(typeClan), puissance, description, chemin);
    m_TousLesClans.push_back(clan);
}

void UniversSkaven::GenererTousLesLieux()
{
    int nb = static_cast<int>(TypeLieu::NombreTotal);
    for (int i = 0; i < nb ; ++i) {
        this->GenererLieu(static_cast<TypeLieu>(i));
    }
}

Profession* UniversSkaven::GetProfession(QString idProfession)
{
    for ( int i = 0 ; i < m_TousLesProfessions.length() ; ++i) {
        if ( m_TousLesProfessions[i]->m_Nom == idProfession)
            return m_TousLesProfessions[i];
    }
    QString msg = "Profession introuvable : " + idProfession ;
    Q_ASSERT_X(true, msg.toStdString().c_str(), "UniversSkaven::GetProfession");
    return nullptr;
}

Lieu* UniversSkaven::GetLieu(QString idLieu)
{
    for ( int i = 0 ; i < m_TousLesLieux.length() ; ++i) {
        if ( m_TousLesLieux[i]->m_Nom == idLieu)
            return m_TousLesLieux[i];
    }
    QString msg = "Lieu introuvable : " + idLieu ;
    Q_ASSERT_X(true, msg.toStdString().c_str(), "UniversSkaven::GetLieu");
    return nullptr;
}

Clan* UniversSkaven::GetClanViaBanniere(QString banniere)
{
    for ( int i = 0 ; i < m_TousLesClans.length() ; ++i) {
        if ( m_TousLesClans[i]->m_CheminBanniere == banniere)
            return m_TousLesClans[i];
    }
    QString msg = "Clan introuvable de cette bannière : " + banniere ;
    Q_ASSERT_X(true, msg.toStdString().c_str(), "UniversSkaven::GetClanViaBanniere");
    return nullptr;
}

Clan* UniversSkaven::GetClan(QString idClan)
{
    for ( int i = 0 ; i < m_TousLesClans.length() ; ++i) {
        if ( m_TousLesClans[i]->m_Nom == idClan)
            return m_TousLesClans[i];
    }
    QString msg = "Clan introuvable : " + idClan ;
    Q_ASSERT_X(true, msg.toStdString().c_str(), "UniversSkaven::GetClan");
    return nullptr;
}

void UniversSkaven::GenererToutesLesProfessions()
{
    this->GenererProfession(TypeProfession::Cultivateur_de_champignons);
    this->GenererProfession(TypeProfession::Batisseur_de_taudis);
    this->GenererProfession(TypeProfession::Mineur);
    this->GenererProfession(TypeProfession::Gardien_de_nourissons);
    this->GenererProfession(TypeProfession::Recolteur_de_nourriture_des_marais);
    this->GenererProfession(TypeProfession::Docker);
    this->GenererProfession(TypeProfession::Servant_de_machine_Skyre);
    this->GenererProfession(TypeProfession::Garde_d_esclave);
    this->GenererProfession(TypeProfession::Entreteneur_de_galerie);
    this->GenererProfession(TypeProfession::Espion_chez_les_autres_clans_skavens);
    this->GenererProfession(TypeProfession::Espion_dans_le_monde_de_la_surface);
    this->GenererProfession(TypeProfession::Preparateur_de_drogues);
    this->GenererProfession(TypeProfession::Ingenieur);
    this->GenererProfession(TypeProfession::Observateur_et_chasseur_de_malepierre);
    this->GenererProfession(TypeProfession::Raffineur_de_malepierre);
    this->GenererProfession(TypeProfession::Coureur_d_egouts);
    this->GenererProfession(TypeProfession::Assassin);
    this->GenererProfession(TypeProfession::Vermine_de_choc);
    this->GenererProfession(TypeProfession::Guerrier_des_clans);
    this->GenererProfession(TypeProfession::Moine_de_la_peste);
    this->GenererProfession(TypeProfession::Pretre_de_la_peste);
    this->GenererProfession(TypeProfession::Maitre_corrupteur);
    this->GenererProfession(TypeProfession::Chef_de_meute);
    this->GenererProfession(TypeProfession::Technomage);
    this->GenererProfession(TypeProfession::Prophete_gris);
}

void UniversSkaven::GenererTousLesClans()
{
    this->GenererClan(TypeClan::Rictus,
                      400.0f,
                      "Le clan est dirigé par le seigneur Kratch Griffe de Damnation. La proximité de tribus de Gobelins de la Nuit fournit au Clan Rictus une source d’esclaves quasi inépuisable, assurant la richesse du clan. Le Clan Rictus possède également une forte proportion de Vermines de Choc. La marque distinctive du Clan Rictus est tracée en rouge vif (la plupart du temps avec du sang d’esclave, la teinte est donc variable).",
                      ":/images/clans/Rictus.jpg");
    this->GenererClan(TypeClan::Mors,
                      800.0f,
                      "Les Skavens du Clan Mors sont considérés comme des arrivistes par les Clans Majeurs. Grâce à ses récentes victoires et à sa prodigieuse expansion, le clan rivalise avec les Clans Eshin, Pestilens, Moulder et même Skryre en matière de pouvoir et d’influence. Le clan est dirigé par le seigneur Ronj Creuse-les-Terriers.",
                      ":/images/clans/Mors.jpg");
    this->GenererClan(TypeClan::Skab,
                      450.0f,
                      "Considérés comme certains des meilleurs guerriers de la société Skaven, les hommes-rats du Clan Skab louent souvent leurs services aux autres Clans. Plus important encore, le Clan Skab a tendance à produire plus de Skavens noirs que les autres maisons et ses rangs comptent un nombre incroyable de Vermines de Choc. Ces guerriers expérimentés sont souvent vendus aux autres Clans pour faire office de gardes du corps des Chefs.",
                      ":/images/clans/Skab.png");
    this->GenererClan(TypeClan::Pestilens,
                      900.0f,
                      "Ravagés par la maladie, contagieux, les Skavens du Clan Pestilens sont des adorateurs dévots du Rat Cornu. Bien qu’ils reconnaissent les autres attributs du dieu, ils se focalisent sur son pouvoir de créer, de contrôler et de répandre des épidémies. Il s'agit d'un dans 4 clans majeurs et d'une arme précieuse pour les skavens tant pour leur fanatisme que pour leur capacité à créer et utiliser des maladies.",
                      ":/images/clans/Pestilens.png");
    this->GenererClan(TypeClan::Septik,
                      200.0f,
                      "Le Clan Septik jura fidélité au Clan Pestilens au cours de la Première Guerre Civile. Ce sont les adeptes les plus fanatiques de la Confrérie de la Peste, des zélotes enragés dans la ferveur rivalise avec celle de leurs maîtres du Clan Pestilens. Son seigneur actuel est le fanatique Eskarre le Croûteux.",
                      ":/images/clans/Septik.jpg");
    this->GenererClan(TypeClan::Skrat,
                      200.0f,
                      "",
                      ":/images/clans/Skrat.jpg");
    this->GenererClan(TypeClan::Gratzz,
                      200.0f,
                      "",
                      ":/images/clans/Gratzz.jpg");
    this->GenererClan(TypeClan::Morbidus,
                      200.0f,
                      "",
                      ":/images/clans/Morbidus.png");
    this->GenererClan(TypeClan::Scorbut,
                      200.0f,
                      "Les Skavens du Clan Scorbut sont une bande de naufrageurs galeux et nombre d’entre eux portent les stigmates de leurs profession (borgnes, manchots, etc.) Le Clan Scorbut contrôle la plus grande Flotte des Clans, au mouillage dans l’anse souterraine du Port de l’Échine.",
                      ":/images/clans/Scorbut.jpg");
    this->GenererClan(TypeClan::Krizzor,
                      200.0f,
                      "",
                      ":/images/clans/Krizzor.jpg");
    this->GenererClan(TypeClan::Liskit,
                      200.0f,
                      "",
                      ":/images/clans/Liskit.jpg");
    this->GenererClan(TypeClan::Festus,
                      200.0f,
                      "",
                      ":/images/clans/Festus.jpg");
    this->GenererClan(TypeClan::Raklur,
                      200.0f,
                      "",
                      ":/images/clans/Raklur.jpg");
    this->GenererClan(TypeClan::Eshin,
                      900.0f,
                      "Le Clan Eshin est renommé pour sa discrétion et sa ruse, pour ses nombreuses armes inhabituelles et exotiques, et pour sa capacité à tuer rapidement et efficacement.",
                      ":/images/clans/Eshin.png");
    this->GenererClan(TypeClan::Moulder,
                      900.0f,
                      "Le Clan Moulder a fait de Malefosse, loin au nord de Praag, son foyer et son repaire. La proximité des Désolations du Chaos combinée aux importantes réserves de Malepierre, ont fait de cette métropole grouillant de Skavens un réceptacle pour les énergies corruptrice du Chaos, et c’est le potentiel extraordinaire de ce matériau qu’exploitent les Maîtres Corrupteurs au cours d’effroyables expériences à mi-chemin en l’intervention chirurgicale démente et la Magie. Le résultat est une production en série d'abomnations redoutables qui rendent non seulement le clan très puissant militairement mais aussi très riches car ses créatures s'achètent à prix d'or.",
                      ":/images/clans/Moulder.jpg");
    this->GenererClan(TypeClan::Skyre,
                      1000.0f,
                      "Sans nul doute, le Clan Skryre est le plus riche et le plus puissant de tous les Clans Majeurs. Sa force repose autant sur les artifices que sur la sorcellerie. L’essentiel de sa technologie est tourné vers la guerre, mêlant en égale mesure Magie et Malepierre pour créer des armes qui n’ont pas leur pareil dans le Vieux Monde. Ses membres, aussi appelés Technomages, sont les inventeurs de machines infernales et destructrices. Beaucoup sont de véritables sorciers capables de manipuler les Vents de Magie et de les emprisonner dans des créations mécaniques.",
                      ":/images/clans/Skyre.png");
    this->GenererClan(TypeClan::Mordkin,
                      150.0f,
                      "Le Clan Mordkin faisait partie des Clans Guerriers qui combattirent les légions de Morts-Vivants de Nagash. Inspirés par la vue terrifiante des morts en marche, et désireux d’intimider leurs rivaux, les Skavens du Clan Mordkin se mirent à se parer des os de leurs ennemis.",
                      ":/images/clans/Mordkin.png");
    this->GenererClan(TypeClan::Grutnik,
                      350.0f,
                      "L’immense pouvoir du Clan Grutnik provient des formidables gisements de Malepierre se trouvant sous son repaire dans les montagnes. Le Clan Grutnik dispose de tant de Malepierre qu’elle est incorporée aux alliages des armes et des armures des guerriers du clan. Certains font étalage de leur richesse en se parant de pépites brutes, sous forme de colifichets, de talismans, voire en remplacement d’un dent ou même d’un œil.",
                      ":/images/clans/Grutnik.png");
    this->GenererClan(TypeClan::Volkn,
                      100.0f,
                      "Le Clan Volkn demeure dans les terriers de la forteresse taillés au cœur de la Montagne de Feu. Tous les membres du clan sont marqués à leur naissance et ses combattants se teignent le pelage d’un rouge soutenu. Les guerriers du Clan Volkn brandissent des lames d’obsidienne noire, qu’ils extraient des profondeurs de leurs tanières volcaniques.",
                      ":/images/clans/Volkn.jpg");
    this->GenererClan(TypeClan::Treecherik,
                      100.0f,
                      "Les Skavens du Clan Treecherik sont des vassaux du Clan Eshin. Ce sont des meurtriers perfides, indignes de confiance - même en comparaison des standards douteux des Skavens.",
                      ":/images/clans/Treecherik.jpg");
    this->GenererClan(TypeClan::Skaar,
                      180.0f,
                      "Le Clan Skaar est renommé pour ses opérations d’extraction minière extensives. Doués pour dénicher les filons de Malepierre, ses membres travaillent souvent en étroite collaboration avec les Clans Skryre et Moulder.",
                      ":/images/clans/Skaar.jpg");
    this->GenererClan(TypeClan::Scruten,
                      100.0f,
                      "Le Clan Scruten (ou Skruten) est particulièrement paranoïaque et dévot. Bien que les Skavens soient tous d’une nature suspicieuse, le Clan Scruten semble particulièrement touché par ce trait de caractère. Il a tendance à vivre en autarcie, c’est pourquoi il ne fait qu’un usage très limité des inventions du Clan Skryre, n’engage que rarement des agents du Clan Eshin (ils s’en méﬁent beaucoup trop) et ne prête aucun crédit aux décoctions empoisonnées du Clan Pestilens.",
                      ":/images/clans/Scruten.jpg");
    this->GenererClan(TypeClan::Skaul,
                      400.0f,
                      "Personne ne sait exactement comment le Clan Skaul a pu garder une place au Conseil des Treize aussi longtemps. Sa population est presque entièrement composée d’hédonistes et de toxicomanes qui persistent à user des narcotiques fabriqués à partir de Malepierre plus que de raison. Leur succès tient peut-être au fait que plusieurs Prophètes Gris sont nés de géniteurs du Clan Skaul lors des cinq dernières décennies. Certains pensent qu’il existe un lien entre l’utilisation de drogue et le nombre croissant de Prophètes Gris qui naissent dans le Clan.",
                      ":/images/clans/Skaul.jpg");
    this->GenererClan(TypeClan::Flem,
                      100.0f,
                      "Souvent confondus avec ceux du Clan Pestilens, les Skavens du Clan Flem se sont profondément investis dans les arts de la peste. Ils différent de leurs rivaux supérieurs dans la mesure où ils ne font pas preuve du même fanatisme religieux que les Moines de la Peste, mais rares sont les autres Skavens qui prennent la peine de le remarquer ou même de différencier les deux Clans.",
                      ":/images/clans/Flem.jpg");
    this->GenererClan(TypeClan::Sleekit,
                      100.0f,
                      "Bien des passages de l’Empire Souterrain sont reliés par des rivières ou des mers plongées dans l’obscurité. Si la plupart des Skavens évitent ces régions à cause des sinistres créatures qu’elles sont censées abriter, le Clan Sleekit les recherche comme s’il s’agissait de denrées rares. On dit que les rats-mariniers du Clan Sleekit, marins et navigateurs expérimentés, ont exploré le monde d’en dessous jusqu’à ses limites et connaissent de terribles secrets concernant les autres choses qui rôdent dans ce monde privé de soleil. ",
                      ":/images/clans/Sleekit.jpg");
}

Clan* UniversSkaven::ChoisirClan()
{
    return m_TousLesClans[rand() % m_TousLesClans.length()];
}

Profession* UniversSkaven::ChoisirProfession()
{
    return m_TousLesProfessions[rand() % m_TousLesProfessions.length()];
}

QString UniversSkaven::GenererNomSkaven()
{
    QStringList noms = {
        "Thramute", "Ekritch", "Queek", "Throt", "Morlocke", "Churft", "Skitice", "Kritislik", "Morskittar",
        "Yuatek", "Sneek", "Skrittar", "Kritislik", "Paskrit", "Throt", "Izak", "Griskit" , "Ghoritch", "Scarskrex",
        "Skrit", "Ikit", "Snikkit", "Skabbicus", "Snarlock", "tran bristlespire", "strut stonebone", "qhronq nightcrusher",
        "stulk bristlechest", "crilk darkweaver", "ven cravenborn", "viknut featherwalker", "steqzik blackfinger", "toshuekch clawmaul"
        "uonqroch"
    };
    return noms[rand() % noms.length()];
}
