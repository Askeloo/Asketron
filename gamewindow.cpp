#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QMessageBox>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0,0,602,482);
    ui->graphicsView->setSceneRect(scene->sceneRect());

    tron_map = new Map;
    scene->addItem(tron_map);

    draw_text=new Textdrawing;
    scene->addItem(draw_text);
    draw_text->setZValue(7);

    scene->update();
}
//----------------------------------------------------------------
void GameWindow::start_Game()
{
    draw_text->playing = true;
    p1 = new Player(0,10,10,0);
    scene->addItem(p1);
    p2 = new Player(1,50,38,3);
    scene->addItem(p2);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    this->show();
    scene->update();
    this->update();

    timer->start(100);
}
//----------------------------------------------------------------
void GameWindow::end_Game()
{
    scene->removeItem(p1);
    scene->removeItem(p2);
    draw_text->playing = false;
    draw_text->game_over = true;
    scene->update();
}
//----------------------------------------------------------------
void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Space:
            if(!draw_text->playing)
            {
                start_Game();
            }
            break;

        case Qt::Key_W:
            if(p1->dir != 0) p1->dir=3;
            break;

        case Qt::Key_A:
            if(p1->dir != 2) p1->dir=1;
            break;

        case Qt::Key_D:
            if(p1->dir != 1) p1->dir=2;
            break;

        case Qt::Key_S:
            if(p1->dir != 3) p1->dir=0;
            break;


        case Qt::Key_J:
            if(p2->dir != 2) p2->dir=1;
            break;

        case Qt::Key_L:
            if(p2->dir != 1) p2->dir=2;
            break;

        case Qt::Key_K:
            if(p2->dir != 3) p2->dir=0;
            break;

        case Qt::Key_I:
            if(p2->dir != 0) p2->dir=3;
            break;

        default:
            break;
    }
}
//----------------------------------------------------------------
void GameWindow::updater()
{
    checklost();
    player_move();
    scene->update();
}
//----------------------------------------------------------------
void GameWindow::checklost()
{
    for(int i = 0; i<p1->trace.size() ; ++i)
    {
        if (i != 0)
        {
            if( (p1->current.mp_x == p1->trace[i-1].mp_x && p1->current.mp_y == p1->trace[i-1].mp_y) ||
                (p1->current.mp_x == p2->trace[i-1].mp_x && p1->current.mp_y == p2->trace[i-1].mp_y) )
            {
                draw_text->player1_win = false;
                timer->stop();
                end_Game();
                break;

            }
            if( (p2->current.mp_x == p2->trace[i-1].mp_x && p2->current.mp_y == p2->trace[i-1].mp_y) ||
                (p2->current.mp_x == p1->trace[i-1].mp_x && p2->current.mp_y == p1->trace[i-1].mp_y) )
            {
                draw_text->player1_win = true;
                timer->stop();
                end_Game();
                break;
            }
        }
    }
}
//----------------------------------------------------------------
void GameWindow::player_move()
{
    p1->tick();
    p1->current.mp_x = p1->x;
    p1->current.mp_y = p1->y;
    p1->trace.insert(p1->trace.end(), p1->current);

    p2->tick();
    p2->current.mp_x = p2->x;
    p2->current.mp_y = p2->y;
    p2->trace.insert(p2->trace.end(), p2->current);
}
//----------------------------------------------------------------
GameWindow::~GameWindow()
{
    delete timer;
    delete p2;
    delete p1;
    delete draw_text;
    delete tron_map;
    delete scene;
    delete ui;
}
