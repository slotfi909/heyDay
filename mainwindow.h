#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include "scoreboard.h"
#include "wheatland.h"
#include "person.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    person *me;
    MainWindow(QWidget *parent = nullptr, int shenaseP = 1);
    ~MainWindow();
public slots:

    void setLevel(int);
    void showLevel();
    int getLevel(){return level;};

    void setXp(int);
    void showXp();
    int getXp(){return xp;};

    void setPassedDay(int);
    void showPassedDay();
    int getPassedDay(){return passedDays;};

    void setCoin(int);
    void showCoin();
    int getCoin(){return coin;};

    void upDateXp(int);

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
    //person me;
    int level;
    int xp;
    int coin;
    int passedDays;
    int userId;
};
#endif // MAINWINDOW_H
