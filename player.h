#ifndef PLAYER_H
#define PLAYER_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "point.h"
#include <QVector>

class Player : public QGraphicsItem
{
public:
    Player(bool player, int start_x, int start_y, int start_dir);
    bool is_player;
    const int W = 60;
    const int H = 48;
    Point current;
    QVector<Point> trace;
    int x,y,dir;
    bool Game;

    QPointF *place;

    void tick();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    ~Player();
};

#endif // PLAYER_H
