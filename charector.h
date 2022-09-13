#ifndef CHARECTOR_H
#define CHARECTOR_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "widget.h"


class Charector
{
public:

    QGraphicsEllipseItem * redcircle;
    QGraphicsEllipseItem * eyewhite;
    QGraphicsEllipseItem * eyeblack;
    QGraphicsRectItem * greenRect;

    QGraphicsRectItem * bim;

    QGraphicsEllipseItem * foot1;
    QGraphicsEllipseItem * foot2;




    bool jumptoggle;
    bool uptoggle;
    bool footmovetoggle;
    bool bimtoggle;
    bool attack;
    Charector();

    int coco_x, coco_y;
    int bim_x,bim_y;
    bool slidecheck;

    void Draw(QGraphicsScene * s);///캐릭터 그려줌
    void Drawfoot(QGraphicsScene*s);
    void Move(int y);
    void Draw_shoot(QGraphicsScene*s);
    void Move_shoot(int y);

    void lie();
    void rise();
    void FootMove();

};




#endif // CHARECTOR_H
