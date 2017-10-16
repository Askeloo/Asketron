#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTimer>
#include "map.h"
#include "player.h"
#include "textdrawing.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    Map *tron_map;
    Player *p1;
    Player *p2;
    QGraphicsScene *scene;
    QTimer *timer;
    Textdrawing *draw_text;

    void start_Game();
    void player_move();
    void checklost();
    void end_Game();
    void keyPressEvent(QKeyEvent *event);
    ~GameWindow();

public slots:
    void updater();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
