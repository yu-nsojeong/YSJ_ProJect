#include "monster.h"

Monster::Monster()
{
    m1_x = 600;
    m2_x = 0;

    m1_toggle = false;
    m2_toggle = false;
    attack = false;
}




void Monster:: draw_monster1(QGraphicsScene*s){





    m1_body= s-> addEllipse(300-15,40-40,100,50);
    m1_body ->setPen(Qt::NoPen);
    m1_body ->setFlag(QGraphicsItem::ItemIsSelectable);
    //m1_body ->setBrush(QBrush(Qt::red));
    m1_body ->setBrush(Qt::NoBrush);
    m1_body ->setTransformOriginPoint(0,0);

    m1_whiteeye = s-> addEllipse(300,40-40,50,50);
    m1_whiteeye ->setPen(Qt::NoPen);
    m1_whiteeye ->setFlag(QGraphicsItem::ItemIsSelectable);
    //m1_whiteeye ->setBrush(QBrush(Qt::white));
    m1_whiteeye ->setBrush(Qt::NoBrush);
    m1_whiteeye ->setTransformOriginPoint(0,0);

    m1_blackeye = s-> addEllipse(300,40-40,40,40);
    m1_blackeye ->setPen(Qt::NoPen);
    m1_blackeye ->setFlag(QGraphicsItem::ItemIsSelectable);
    //m1_blackeye ->setBrush(QBrush(Qt::black));
    m1_blackeye ->setBrush(Qt::NoBrush);
    m1_blackeye ->setTransformOriginPoint(0,0);








}

void Monster:: move_monster1() {

    //Charector::coco_x = x;

    if(m1_x <= 0){
        m1_body -> moveBy(600,0);
        m1_whiteeye -> moveBy(600,0);
        m1_blackeye -> moveBy(600,0);
        m1_x = 600;
        m1_toggle = false;

        m1_body ->setBrush(Qt::NoBrush);
        m1_whiteeye ->setBrush(Qt::NoBrush);
        m1_blackeye ->setBrush(Qt::NoBrush);


    }
    else if(attack){


        m1_body -> moveBy(600-m1_x,0);
        m1_whiteeye -> moveBy(600-m1_x,0);
        m1_blackeye -> moveBy(600-m1_x,0);


        m1_x = 600;
        m1_toggle = false;
        attack = false;

        m1_body ->setBrush(Qt::NoBrush);
        m1_whiteeye ->setBrush(Qt::NoBrush);
        m1_blackeye ->setBrush(Qt::NoBrush);


    }
    else{
        m1_body ->setBrush(QBrush(Qt::red));
        m1_whiteeye ->setBrush(QBrush(Qt::white));
        m1_blackeye ->setBrush(QBrush(Qt::black));



        m1_body -> moveBy(-20,0);
        m1_whiteeye -> moveBy(-20,0);
        m1_blackeye -> moveBy(-20,0);
        qDebug()<<m1_toggle;

        m1_x-=20;
    }

    qDebug()<<'x : '<< m1_x;

}

