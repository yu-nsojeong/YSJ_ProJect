#include "charector.h"

Charector::Charector()
{
    coco_x = 0;
    coco_y = 0;
    jumptoggle = false;
    uptoggle = true;
    footmovetoggle = true;


    slidecheck = false;



    bim_x = 0;
    bim_y = 0;


}


void Charector:: Draw(QGraphicsScene * s){


    redcircle = s-> addEllipse(0-300,-50,100,50);
    redcircle ->setPen(QPen(Qt::white));
    redcircle ->setFlag(QGraphicsItem::ItemIsSelectable);
    redcircle ->setBrush(QBrush(Qt::blue));
    redcircle ->setTransformOriginPoint(25-300+35,30);

    eyewhite = s-> addEllipse(30-300,-50,50,50);
    eyewhite ->setPen(Qt::NoPen);
    eyewhite ->setFlag(QGraphicsItem::ItemIsSelectable);
    eyewhite ->setBrush(QBrush(Qt::white));
    eyewhite ->setTransformOriginPoint(25-300+35,30);

    eyeblack = s-> addEllipse(40-300,-45,40,40);
    eyeblack ->setPen(Qt::NoPen);
    eyeblack ->setFlag(QGraphicsItem::ItemIsSelectable);
    eyeblack ->setBrush(QBrush(Qt::black));
    eyeblack ->setTransformOriginPoint(25-300+35,30);

    greenRect = s->addRect(25-300,0,50,30,QPen(Qt::green));
    greenRect->setPen(Qt::NoPen);
    greenRect->setFlag(QGraphicsItem::ItemIsSelectable);
    greenRect->setBrush(QBrush(Qt::green));
    greenRect->setTransformOriginPoint(25-300+35,30);



}

void Charector:: Drawfoot(QGraphicsScene*s){

    foot1 = s->addEllipse(25-300,0+30,20,10,QPen(Qt::blue));
    foot1->setPen(QPen(Qt::white));
    foot1 ->setFlag(QGraphicsItem::ItemIsSelectable);
    foot1 ->setBrush(QBrush(Qt::blue));
    foot1 ->setTransformOriginPoint(25-300+35,30);

    foot2 = s->addEllipse(60-300,0+30+3,20,10,QPen(Qt::blue));
    foot2->setPen(QPen(Qt::white));
    foot2 ->setFlag(QGraphicsItem::ItemIsSelectable);
    foot2 ->setBrush(QBrush(Qt::darkBlue));
    foot2 ->setTransformOriginPoint(25-300+35,30);


}

void Charector:: FootMove(){

    if(footmovetoggle){

        foot1 -> moveBy(0,3);
        foot2 -> moveBy(0,-3);
        footmovetoggle = false;
    }
    else{



        foot1 -> moveBy(0,-3);
        foot2 -> moveBy(0,3);
        footmovetoggle = true;
    }

}






void Charector:: Move(int y) {

    //Charector::coco_x = x;

    greenRect -> moveBy(0,y);
    redcircle -> moveBy(0,y);
    eyeblack -> moveBy(0,y);
    eyewhite -> moveBy(0,y);
    foot1-> moveBy(0,y);
    foot2 -> moveBy(0,y);

}

void Charector:: rise(){


    slidecheck = false;

    greenRect->show();
    redcircle->show();
    eyeblack->show();
    eyewhite->show();
    foot1->show();
    foot2->show();



    greenRect -> setRotation(0);
    redcircle -> setRotation(0);
    eyeblack -> setRotation(0);
    eyewhite -> setRotation(0);
    foot1-> setRotation(0);
    foot2 -> setRotation(0);

}
void Charector:: lie (){

    slidecheck = true;

    greenRect->show();
    redcircle->show();
    eyeblack->show();
    eyewhite->show();
    foot1->show();
    foot2->show();



    greenRect -> setRotation(-90);
    redcircle -> setRotation(-90);
    eyeblack -> setRotation(-90);
    eyewhite -> setRotation(-90);
    foot1-> setRotation(-90);
    foot2 -> setRotation(-90);

}


void Charector:: Draw_shoot(QGraphicsScene*s){

    bim = s->addRect(25-300,10,30,5,QPen(Qt::green));
    bim->setPen(Qt::NoPen);
    bim->setFlag(QGraphicsItem::ItemIsSelectable);
    bim ->setBrush(Qt::NoBrush);
    bim->setTransformOriginPoint(25-300+35,30);


}

void Charector:: Move_shoot(int y){

    if(bim_x==0){
        bim -> moveBy(0,y);
    }


    if(bim_x >= 600){
        bim -> moveBy(-600,-y);

        bim_x = 0;
        bim_y = 0;
        bimtoggle = false;

        bim ->setBrush(Qt::NoBrush);


    }
    else{
        bim ->setBrush(QBrush(Qt::green));
        bim -> moveBy(+40,0);

        qDebug()<<bimtoggle;

        bim_x+=40;
    }



}


