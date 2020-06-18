#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clients.h"
#include <QMainWindow>
#include "COMMANDE.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();
     void on_pb_modifier_clicked();

     void on_pushButton_2_clicked();

     void on_pb_ajouter_2_clicked();

     void on_pb_supprimer_2_clicked();

     void on_pb_modifier_2_clicked();

     void on_pushButton_triC_clicked();

     void on_pushButton_triD_clicked();

     void on_pushButton_3_clicked();

     void on_radioButton_clicked();

     void on_pdf_clicked();



     void on_comboBox_activated(const QString &arg1);

     void on_tabCOMMANDE_activated(const QModelIndex &index);
     void afficherlescin();

private:
    Ui::MainWindow *ui;
    clients tmpclients;
    COMMANDE tmpCOMMANDE;
};

#endif // MAINWINDOW_H
