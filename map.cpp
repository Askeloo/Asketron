#include "map.h"

Map :: Map()
{
    mappic.load(":/images/background.jpg");

}
//----------------------------------------------------------------
QRectF Map::boundingRect() const
{
    return QRect(0,0,600,480);
}
//----------------------------------------------------------------
void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,600,480,mappic);
}
