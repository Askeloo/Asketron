#ifndef TEXTDRAWING_H
#define TEXTDRAWING_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Textdrawing: public QGraphicsItem
{
private:
    int x,y,w,h;
    bool game_over, playing, player1_win;


public:
    Textdrawing();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setGame_over(bool value);
    void setPlaying(bool value);
    void setPlayer1_win(bool value);
    bool getPlaying() const;
};

#endif // TEXTDRAWING_H
