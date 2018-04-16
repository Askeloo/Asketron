#ifndef PLAYER_H
#define PLAYER_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "point.h"
#include <QVector>

class Player : public QGraphicsItem
{
private:
    bool is_player;
    const int W = 60;
    const int H = 48;
    int x,y,dir;
    bool Game;

    Point current;
    QVector<Point> trace;
    QPointF *place;

public:
    Player(bool player, int start_x, int start_y, int start_dir);

    void tick();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    ~Player();
    QVector<Point> getTrace() const;
    void insertToEndTrace(Point value_to_add);
    Point& atTrace(const size_t &i);
    Point getCurrent() const;
    void setCurrent(const int &x, const int &y);
    int getX() const;
    int getY() const;
    int getDir() const;
    void setDir(int value);
};

#endif // PLAYER_H
