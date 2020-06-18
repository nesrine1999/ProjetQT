#ifndef clients_H
#define clients_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class clients
{public:
    clients();
    clients(int,QString,int);
    QString get_nom();
    int get_CIN();
    int get_tel();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier (int);
      QSqlQueryModel * afficher_tri_ID();
      QSqlQueryModel * recherche(int);
        QSqlQueryModel* afficher_BY_CIN();
private:
    QString nom;
    int cin,tel;
};

#endif // clients_H
