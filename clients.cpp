#include "clients.h"
#include <QDebug>
#include "connexion.h"

clients::clients()
{
cin=0;
nom="";
tel=0;
}
clients::clients(int CIN,QString nom,int tel)
{
  this->cin=CIN;
  this->nom=nom;
  this->tel=tel;
}
QString clients::get_nom(){return  nom;}
int clients::get_tel(){return tel;}
int clients::get_CIN(){return  cin;}

bool clients::ajouter()
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("INSERT INTO clients (cin, nom, tel)VALUES(:cin, :nom, :tel)");
query.bindValue(":cin", res);
query.bindValue(":nom", nom);
query.bindValue(":tel",  tel);

return    query.exec();
}

QSqlQueryModel * clients::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from clients");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("tel"));
    return model;
}

bool clients::supprimer(int CIN)
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from clients where CIN = :CIN ");
query.bindValue(":CIN", res);
return    query.exec();
}

bool clients::modifier(int CIN)
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Update clients set CIN = :CIN , NOM = :nom , TEL = :tel where CIN = :CIN ");
query.bindValue(":CIN", res);
query.bindValue(":nom", nom);
query.bindValue(":tel", tel);
return    query.exec();
}
QSqlQueryModel * clients:: afficher_tri_ID()
 {
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM clients order by nom");
       q->exec();
       model->setQuery(*q);
       return model;
 }

QSqlQueryModel *clients::recherche(int idd){

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res= QString::number(idd);
    model->setQuery("select * from clients where CIN like '%"+res+"%'" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("tel"));

    return model;
    }
QSqlQueryModel*clients::afficher_BY_CIN()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select CIN from CLIENTS ");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));


        return model;
}
