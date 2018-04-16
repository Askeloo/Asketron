#include "player.h"

QVector<Point> Player::getTrace() const
{
    return trace;
}

void Player::insertToEndTrace(Point value_to_add)
{
    trace.insert(trace.end(), value_to_add);
}

Point& Player::atTrace(const size_t &i)
{
    return trace[i];
}

Point Player::getCurrent() const
{
    return current;
}

void Player::setCurrent(const int &x, const int &y)
{
    current.setMP(x,y);
}

int Player::getX() const
{
    return x;
}

int Player::getY() const
{
    return y;
}

int Player::getDir() const
{
    return dir;
}

void Player::setDir(int value)
{
    dir = value;
}

Player :: Player(bool player, int start_x, int start_y, int start_dir)
{
    x = start_x;
    y = start_y;
    dir = start_dir;
    current.mp_x = x;
    current.mp_y = y;
    Game = 1;
    is_player = player;
    place = new QPointF;
}
//----------------------------------------------------------------
void Player :: tick()
{
    if(dir == 0) y+=1;
    if(dir == 1) x-=1;
    if(dir == 2) x+=1;
    if(dir == 3) y-=1;

    if(x >= W) x = 0;
    if(x < 0) x = W - 1;
    if(y >= H) y = 0;
    if(y < 0) y = H - 1;
}
//----------------------------------------------------------------
QRectF Player::boundingRect() const
{
    return QRect(x, y, 2, 2);
}
//----------------------------------------------------------------
void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i = 0; i<trace.size(); ++i)
    {
        place->setX(10*trace[i].mp_x + 5);
        place->setY(10*trace[i].mp_y + 5);
        if(!is_player)
        {
            painter->setBrush(QBrush(QColor(0, 255, 0, 255)));
        }
        else
        {
            painter->setBrush(QBrush(QColor(255, 0, 0, 255)));
        }
        painter->drawEllipse(*place, 5,5);

    }
}
//----------------------------------------------------------------
Player:: ~Player()
{
    delete place;
}
