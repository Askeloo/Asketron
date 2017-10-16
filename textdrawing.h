#ifndef TEXTDRAWING_H
#define TEXTDRAWING_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Textdrawing: public QGraphicsItem
{
public:
    Textdrawing();
    int x,y,w,h;
    bool game_over, playing, player1_win;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // TEXTDRAWING_H
