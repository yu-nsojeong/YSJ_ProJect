#include "tree.h"

Tree::Tree()
{

    tree_toggle = false;
    tree_x = 600;
    attack_tree = false;


}




void Tree :: Draw_tree(QGraphicsScene*s){

    tree1= s-> addRect(300-15,-200,50,180);
    tree1 ->setPen(Qt::NoPen);
    tree1 ->setFlag(QGraphicsItem::ItemIsSelectable);
    //tree1 ->setBrush(QBrush(Qt::green));
    tree1 ->setBrush(Qt::NoBrush);
    tree1 ->setTransformOriginPoint(0,0);

}
void Tree :: move_tree(){

    if(tree_x <= 0){
        tree1 -> moveBy(600,0);

        tree_x = 600;
        tree_toggle = false;

        tree1 ->setBrush(Qt::NoBrush);


    }
    else if(attack_tree){


        tree1 -> moveBy(600-tree_x,0);


        tree_x = 600;
        tree_toggle = false;
        attack_tree = false;

        tree1 ->setBrush(Qt::NoBrush);

        qDebug()<<"okokokok";



    }
    else{
        tree1 ->setBrush(QBrush(Qt::darkGreen));
        tree1 -> moveBy(-20,0);

        qDebug()<<tree_toggle;

        tree_x-=20;
    }

    qDebug()<<"t x : "<< tree_x;






}
