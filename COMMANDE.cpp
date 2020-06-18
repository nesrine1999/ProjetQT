#include "COMMANDE.h"
#include <QDebug>
#include "connexion.h"
#include <QDate>
#include <QComboBox>
COMMANDE::COMMANDE()
{ID_CMD=0;

           CIN=0;
             ID_ANIMAUX=0;
             QUANTITE=0;
             PRIX_TOTAL=0;

}
COMMANDE::COMMANDE(int ID_CMD,int CIN,int ID_ANIMAUX,int QUANTITE,int PRIX_TOTAL)
{this->ID_CMD=ID_CMD;
  this->CIN=CIN;
  this->ID_ANIMAUX=ID_ANIMAUX;
  this->QUANTITE=QUANTITE;
    this->PRIX_TOTAL=PRIX_TOTAL;

}

int COMMANDE::get_ID_CMD(){return ID_CMD;}
int COMMANDE::get_CIN(){return  CIN;}
int COMMANDE::get_ID_ANIMAUX(){return  ID_ANIMAUX;}
int COMMANDE::get_QUANTITE(){return  QUANTITE;}
int COMMANDE::get_PRIX_TOTAL(){return  PRIX_TOTAL;}

bool COMMANDE::ajouter()
{
QSqlQuery query;
int res= ID_CMD;
query.prepare("INSERT INTO COMMANDE ( ID_CMD, CIN, ID_ANIMAUX, QUANTITE, PRIX_TOTAL,DATE_CMD)VALUES( :ID_CMD, :CIN, :ID_ANIMAUX, :QUANTITE, :PRIX_TOTAL,SYSDATE)");
query.bindValue(":ID_CMD", res);
query.bindValue(":CIN", CIN);
query.bindValue(":ID_ANIMAUX",  ID_ANIMAUX);
query.bindValue(":QUANTITE",  QUANTITE);
query.bindValue(":PRIX_TOTAL",  PRIX_TOTAL);
//query.bindValue(": DATE_CMD",  DATE_CMD);

return    query.exec();
}

QSqlQueryModel * COMMANDE::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CMD"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_ANIMAUX"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_CMD"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

bool COMMANDE::supprimer(int ID_CMD)
{
QSqlQuery query;
int res= ID_CMD;
query.prepare("Delete from COMMANDE where ID_CMD = :ID_CMD ");
query.bindValue(":ID_CMD", res);
return    query.exec();
}

bool COMMANDE::modifier(int CIN)
{
QSqlQuery query;
int res=CIN;
query.prepare("Update COMMANDE set ID_ANIMAUX=:ID_ANIMAUX,QUANTITE =:QUANTITE, PRIX_TOTAL=:PRIX_TOTAL where CIN = :ID_CMD ");
query.bindValue(":ID_CMD", res);
query.bindValue(":CIN", CIN);
query.bindValue(":ID_ANIMAUX",  ID_ANIMAUX);
query.bindValue(":QUANTITE",  QUANTITE);
query.bindValue(":PRIX_TOTAL",  PRIX_TOTAL);


return    query.exec();
}

QSqlQueryModel * COMMANDE:: afficher_tri_ID_DESC()
{
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM COMMANDE order by PRIX_TOTAL desc");
       q->exec();
       model->setQuery(*q);
       return model;
}
QSqlQueryModel * COMMANDE:: afficher_tri_c()
{
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM COMMANDE order by PRIX_TOTAL ASC");
       q->exec();
       model->setQuery(*q);
       return model;
}

QSqlQueryModel* COMMANDE::afficher_BY_CIN()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select CIN from CLIENTS ");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));


        return model;
}


