#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QDialog>
#include <QMultiMap>

namespace Ui {
class scoreboard;
}

class scoreboard : public QDialog
{
    Q_OBJECT

public:
    explicit scoreboard(QWidget *parent = nullptr);
    ~scoreboard();

private:
    Ui::scoreboard *ui;
    QMultiMap<int,QString> players;
};

#endif // SCOREBOARD_H
