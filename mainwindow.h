#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include "scoreboard.h"
#include "farm.h"
#include "exthread.h"
#include "Aviculture.h"
#include "Sheepcote.h"
#include "Dairyfarm.h"
#include "wheatland.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr,int shenaseP=1);
    ~MainWindow();


public :
    void showLevel();

    void showXp();


    void showCoin();




private slots:
    void on_pushButton_clicked();

    void on_silo_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_garner_clicked();

    void on_alfalfaLand_clicked();

    void on_WheatLand_clicked();

    void on_Aviculture_clicked();

    void on_Dairyfarm_clicked();

    void on_Sheepcote_clicked();

private:
    Ui::MainWindow *ui;
    Farm myfarm;
    Aviculture *Avi;
    Sheepcote *Sh;
    Dairyfarm *Da;
    Exthread Ex;
    scoreboard *sc;
    wheatland *wh;


};
#endif // MAINWINDOW_H
