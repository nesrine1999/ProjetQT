#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
//#include <QDate>
class COMMANDE
{public:
    COMMANDE();
    COMMANDE(int,int,int,int,int);
    int get_ID_CMD();
   int  get_CIN();
    int get_ID_ANIMAUX();
    int get_QUANTITE();
    int get_PRIX_TOTAL();
    //QDate get_DATE_CMD();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier (int);
     QSqlQueryModel * afficher_tri_c();
     QSqlQueryModel * afficher_tri_ID_DESC();
      QSqlQueryModel* afficher_BY_CIN();
      QSqlQueryModel *  afficher_combobox();

private:
    int ID_CMD,ID_ANIMAUX,QUANTITE,PRIX_TOTAL;
int CIN;
};



#endif // COMMANDE_H
