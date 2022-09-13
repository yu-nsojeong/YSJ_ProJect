#ifndef MONSTER_H
#define MONSTER_H


#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>



class Monster
{
public:
    Monster();


    ///////monster 1
    QGraphicsEllipseItem * m1_body;
    QGraphicsEllipseItem * m1_whiteeye;
    QGraphicsEllipseItem * m1_blackeye;

    QGraphicsEllipseItem * m2_body;
    QGraphicsEllipseItem * m2_whiteeye;
    QGraphicsEllipseItem * m2_blackeye;

    int m1_x;
    int m2_x;
    bool m1_toggle;
    bool m2_toggle;
    bool attack;





    void draw_monster1(QGraphicsScene*s);
    void draw_monster2(QGraphicsScene*s);


    void move_monster1();
    void move_monster2();


};

#endif // MONSTER_H
