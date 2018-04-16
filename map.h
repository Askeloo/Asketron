#ifndef MAP_H
#define MAP_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Map: public QGraphicsItem
{
private:
    QPixmap mappic;

public:
    Map();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // MAP_H
