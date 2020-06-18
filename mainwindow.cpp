#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clients.h"
#include "COMMANDE.h"
#include "clients.h"
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QTextStream>
#include <QComboBox>
int n=0,nb=0;
QString ch="";
QString chaine="";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
MainWindow::afficherlescin();
ui->tabclients->setModel(tmpclients.afficher());
ui->tabCOMMANDE->setModel(tmpCOMMANDE.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    int CIN= ui->lineEdit_CIN->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    int tel= ui->lineEdit_tel->text().toInt();
    ui->lineEdit_nom->setInputMask("aaaaaaaaaaaaaaaa");
    ui->lineEdit_CIN->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_tel->setValidator( new QIntValidator(0, 99999999, this) );

  clients c(CIN,nom,tel);
  bool test=c.ajouter();
  if(test)
{ui->tabclients->setModel(tmpclients.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un clients"),
                  QObject::tr("clients ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}void MainWindow::on_pb_supprimer_clicked()
{
clients C;
       QItemSelectionModel *select = ui->tabclients->selectionModel();
       QModelIndexList list;
       if(select->hasSelection())
       list=select->selectedRows();
       for(int i=0; i< list.count(); i++)
       {
           C.supprimer(list[i].data().toInt());
       }
  ui->tabclients->setModel(C.afficher());

}


//void MainWindow::on_pb_supprimer_clicked()
//{
//int CIN = ui->lineEdit_CIN->text().toInt();
//bool test=tmpclients.supprimer(CIN);
//if(test)
//{ui->tabclients->setModel(tmpclients.afficher());//refresh
   // QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
           //     QObject::tr("clients supprimé.\n"
                           // "Click Cancel to exit."), QMessageBox::Cancel);

//}
//else
  //  QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
               // QObject::tr("Erreur !.\n"
                           // "Click Cancel to exit."), QMessageBox::Cancel);


//}

void MainWindow::on_pushButton_clicked()
{
    ui->tabclients->setModel(tmpclients.afficher());
}









       void MainWindow::on_pb_modifier_clicked()
       { if(ui->lineEdit_nom_3->text() == "" && ui->lineEdit_CIN_2->text() == "")
           {
              QMessageBox::about(this,"Empty values!","Please Enter Values to be Updated!");
           }
         int CIN = ui->lineEdit_CIN_2->text().toInt();
           QString nom= ui->lineEdit_nom_3->text();
           int tel= ui->lineEdit_tel_4->text().toInt();
        clients c(CIN,nom,tel);
        bool test=c.modifier(CIN);
         if(test)
       {

             ui->tabclients->setModel(tmpclients.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                       QObject::tr("clients modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
        else
             QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                       QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

       }

//void MainWindow::on_pb_modifier_clicked()
//{
 //   int CIN = ui->lineEdit_CIN_2->text().toInt();
   // QString nom= ui->lineEdit_nom_3->text();
   // int tel= ui->lineEdit_tel_4->text().toInt();
 // clients c(CIN,nom,tel);
//  bool test=c.modifier(CIN);
//  if(test)
//{

    //  ui->tabclients->setModel(tmpclients.afficher());//refresh
//QMessageBox::information(nullptr, QObject::tr("modifier un client"),
               //   QObject::tr("clients modifié.\n"
           //                   "Click Cancel to exit."), QMessageBox::Cancel);
//
//}
//  else
    //  QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
       //           QObject::tr("Erreur !.\n"
        //                      "Click Cancel to exit."), QMessageBox::Cancel);

//}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pb_ajouter_2_clicked()
{

    {
        int ID_COMMANDE = ui->lineEdit_cmd->text().toInt();
        int  CIN = ui->comboBox->currentText().toInt();

           int ID_ANIMAUX= ui->lineEdit_TYPE_2->text().toInt();
           int QUANTITE= ui->lineEdit_QUANTITE->text().toInt();
int PRIX_TOTAL= ui->lineEdit_QUANTITE_2->text().toInt();
     COMMANDE M (ID_COMMANDE,CIN,ID_ANIMAUX,QUANTITE,PRIX_TOTAL);
      bool test=M.ajouter();
      if(test)
    {ui->tabCOMMANDE->setModel(tmpCOMMANDE.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter une COMMANDE"),
                      QObject::tr("COMMANDE ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une COMMANDE"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }
}
void MainWindow::on_pb_supprimer_2_clicked()
{
COMMANDE M;
       QItemSelectionModel *select = ui->tabCOMMANDE->selectionModel();
       QModelIndexList list;
       if(select->hasSelection())
       list=select->selectedRows();
       for(int i=0; i< list.count(); i++)
       {
           M.supprimer(list[i].data().toInt());
       }
  ui->tabCOMMANDE->setModel(M.afficher());

}



void MainWindow::on_pb_modifier_2_clicked()
{int ID_CMD=0 ;
            int PRIX_TOTAL=0;
   int CIN = ui->lineEdit_CIN_6->text().toInt();
    int ID_ANIMAUX = ui->lineEdit_TYPE_2->text().toInt();
    int QUANTITE= ui->lineEdit_QUANTITE_2->text().toInt();
  COMMANDE M ( ID_CMD,CIN,ID_ANIMAUX,QUANTITE,PRIX_TOTAL );
  bool test=M.modifier(CIN);
  if(test)
{

     ui->tabCOMMANDE->setModel(tmpCOMMANDE.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                  QObject::tr("clients modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                 QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_triC_clicked()
{
     ui->tabCOMMANDE->setModel(tmpCOMMANDE.afficher_tri_c());

}

void MainWindow::on_pushButton_triD_clicked()
{
    ui->tabCOMMANDE->setModel(tmpCOMMANDE.afficher_tri_ID_DESC());
}



void MainWindow::on_radioButton_clicked()
{
     ui->tabclients->setModel(tmpclients.afficher_tri_ID());
}

void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->re->text().toInt();
    ui->tabclients->setModel(tmpclients.recherche(id));

}

void MainWindow::on_pdf_clicked()
{
    QString strStream ;
     QTextStream out (&strStream);

                            const int rowCount = ui->tabCOMMANDE->model()->rowCount();
                            const int columnCount = ui->tabCOMMANDE->model()->columnCount();
                            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - COMmANDE LIST<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> *** Promotions *** "+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tabCOMMANDE->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tabCOMMANDE->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tabCOMMANDE->isColumnHidden(column)) {
                                        QString data =ui->tabCOMMANDE->model()->data(ui->tabCOMMANDE->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table>\n"
                                "</body>\n"
                                "</html>\n";

                            QTextDocument *document = new QTextDocument();
                            document->setHtml(strStream);

                            QPrinter printer;

                            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                            if (dialog->exec() == QDialog::Accepted) {
                                document->print(&printer);
                            }

                            delete document;
}






void MainWindow::afficherlescin(){
    ui->comboBox->clear();
    QSqlQuery query;
                query.prepare("SELECT CIN FROM CLIENTS");
                if(query.exec()){
                    while(query.next()){
                        ui->comboBox->addItem(query.value(0).toString());


                    }
}

}




