#ifndef TREE_H
#define TREE_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>


class Tree
{
public:
    Tree();


    bool tree_toggle;

    QGraphicsRectItem * tree1;

    int tree_x,tree_y;
    bool attack_tree;

    void Draw_tree(QGraphicsScene*s);
    void move_tree();



};

#endif // TREE_H
