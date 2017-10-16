#include "textdrawing.h"

Textdrawing::Textdrawing()
{
    w=350;
    h=150;
    x=600/2-w/2;
    y=480/2-h/2;
    playing = false;
    game_over = false;
    player1_win = false;
}
//----------------------------------------------------------------
QRectF Textdrawing::boundingRect() const
{
    return QRect(x, y, w, h);
}
//----------------------------------------------------------------
void Textdrawing::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::blue);
    painter->setPen(pen);

    QFont font=painter->font() ;
    font.setPointSize ( 20 );
    painter->setFont(font);

    if(!playing)
    {
        if(game_over)
        {
            font.setPointSize ( 40 );
            painter->setFont(font);
            painter->drawText( x+40,y+20, "GAME OVER" );

            if(player1_win)
            {
                font.setPointSize ( 18 );
                painter->setFont(font);
                painter->setPen(QPen(QColor(0, 255, 0, 255)));
                painter->drawText( x+100,y+80, "PLAYER 1 WINS" );
            }
            else
            {
                font.setPointSize ( 18 );
                painter->setFont(font);
                painter->setPen(QPen(QColor(255, 0, 0, 255)));
                painter->drawText( x+100,y+80, "PLAYER 2 WINS" );

            }
            painter->setPen(pen);
            painter->drawText(x,y+110, "PRESS SPACE TO PLAY NEW GAME" );

        }
        else
        {
            painter->drawText( boundingRect(),Qt::AlignCenter, "PLAYER 1 (W_A_S_D)\n"
                                                               "PLAYER 2 (I_J_K_L)\n"
                                                               "PRESS SPACE TO START" );
        }
    }
}
