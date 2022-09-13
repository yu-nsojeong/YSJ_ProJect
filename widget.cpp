#include "widget.h"
#include "ui_widget.h"
#include "charector.h"
#include "monster.h"
#include "tree.h"
#include <QGraphicsScene>
#include <cstdlib>//난수생성 헤더파일

//#include "ui_widget.h"
//#include <QWidget>

#include<QPixmap>


Charector a;
Monster m;
Tree t;

int score;
int heart = 3;
void jumpmotion(void);
bool restart = true;
int coco = 1;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //ui->grap;

    QGraphicsRectItem* b_g_bottom = scene->addRect(-320,40,700,75,QPen(Qt::darkGreen));
    b_g_bottom ->setBrush(QBrush(Qt::darkGreen));



    QPixmap bg("C:\\cpp\\20220905\\YSJ_ProJect\\image\\bg.png");
    ui ->label_2->setPixmap(bg.scaled(711,191,Qt::KeepAspectRatio));



    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(myfunction()));
    connect(timer, SIGNAL(timeout()),this, SLOT(myscreen()));
    timer->start(50);

    a.Draw(scene);
    a.Drawfoot(scene);
    m.draw_monster1(scene);
    t.Draw_tree(scene);
    a.Draw_shoot(scene);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    a.jumptoggle = true;

}

void Widget::myfunction(){


    /////////jump
    jumpmotion();

    if(m.m1_toggle){
        m.move_monster1();
    }

    if( t.tree_toggle){
        t.move_tree();
    }
    if( a.bimtoggle){
        a.Move_shoot(-a.bim_y);
    }

    a.FootMove();

    /////목숨 차감
    if(m.m1_x == a.coco_x){

        if(a.coco_y<70){

            if(heart>0)heart--;

        }
    }
    if(t.tree_x == a.coco_x){

        if(!a.slidecheck){

            if(heart>0)heart--;

        }
    }


    /////////슈팅
    if(((a.bim_x+40 == m.m1_x)||(a.bim_x+30 == m.m1_x)||(a.bim_x+20 == m.m1_x)||(a.bim_x+10 == m.m1_x)||(a.bim_x == m.m1_x))&&a.bimtoggle ){


        if(a.bim_y<30){
            m.attack = true;
            qDebug() << "scuccess" << m.attack;
        }

    }
    if(((a.bim_x+40 == t.tree_x)||(a.bim_x+30 ==t.tree_x)||(a.bim_x+20 == t.tree_x)||(a.bim_x+10 == t.tree_x)||(a.bim_x == t.tree_x))&&a.bimtoggle ){

        if(a.bim_y>30){
            t.attack_tree = true;
            qDebug() << "scuccesst" << t.attack_tree;
        }

    }


    /////스코어 목숨 ui
    ui->score->setText(QString::number(score));
    ui->heart_score->setText(QString::number(heart));


    ///////////몬스터 장애물 생성
    srand(time(NULL));
    if((1==rand()%4)&&(m.m1_toggle == false)){


        //qDebug()<<"ok";
        m.m1_toggle = true;

    }

    if((2==rand()%4)&&(t.tree_toggle == false)){
        t.tree_toggle = true;
    }


score+=10;


}



void Widget::myscreen(){


    if(heart == 3){

        if(coco == 1){

            QPixmap coco1("C:\\cpp\\20220905\\YSJ_ProJect\\image\\coco1.png");
             ui ->label_bg->setPixmap(coco1.scaled(150,150,Qt::KeepAspectRatio));

            coco =2;
        }
        else if(coco == 2){
            QPixmap coco2("C:\\cpp\\20220905\\YSJ_ProJect\\image\\coco2.png");
            ui ->label_bg->setPixmap(coco2.scaled(150,150,Qt::KeepAspectRatio));
            coco = 1;
        }

    }
    else if(heart == 2){

        if(coco == 1){

            QPixmap coco1("C:\\cpp\\20220905\\YSJ_ProJect\\image\\coco2_1.png");
             ui ->label_bg->setPixmap(coco1.scaled(150,150,Qt::KeepAspectRatio));

            coco =2;
        }
        else if(coco == 2){
            QPixmap coco2("C:\\cpp\\20220905\\YSJ_ProJect\\image\\coco2_2.png");
            ui ->label_bg->setPixmap(coco2.scaled(150,150,Qt::KeepAspectRatio));
            coco = 1;
        }

    }
    else if(heart == 1){

        if(coco == 1){

            QPixmap coco1("C:\\cpp\\20220905\\YSJ_ProJect\\image\\coco3_1.png");
             ui ->label_bg->setPixmap(coco1.scaled(150,150,Qt::KeepAspectRatio));

            coco =2;
        }
        else if(coco == 2){
            QPixmap coco2("C:\\cpp\\20220905\\YSJ_ProJect\\image\\coco3_2.png");
            ui ->label_bg->setPixmap(coco2.scaled(150,150,Qt::KeepAspectRatio));
            coco = 1;
        }

    }
    else if(heart<=0){
        scene->clear();

        timer->start(10000);
        ui->death_menue->setText("Coco is dead.");

            QPixmap cocodeath("C:\\cpp\\20220905\\YSJ_ProJect\\image\\coco4.png");
             ui ->label_bg->setPixmap(cocodeath.scaled(150,150,Qt::KeepAspectRatio));

    }


    if(score>5000){

        scene->clear();
        timer->start(10000);
        ui->death_menue->setText("Coco arrived.");

        QPixmap cocoarrive("C:\\cpp\\20220905\\YSJ_ProJect\\image\\coco5.png");
         ui ->label_bg->setPixmap(cocoarrive.scaled(150,150,Qt::KeepAspectRatio));

        QPixmap bg("C:\\cpp\\20220905\\YSJ_ProJect\\image\\bg_a.png");

        ui ->label_2->setPixmap(bg.scaled(711,191,Qt::KeepAspectRatio));
    }
}



void jumpmotion(void){

    if(a.jumptoggle){


        if(a.uptoggle){
            if(a.coco_y >= 150 ){
                a.Move(0);
                a.uptoggle = false;
            }

            else if(a.coco_y >= 140){
                a.Move(-10);

                 a.coco_y+=10;

            }
            else if(a.coco_y >= 20){
                 a.Move(-20);
                  a.coco_y+=20;
            }
            else if(a.coco_y>=0) {
                 a.Move(-10);
                  a.coco_y+=10;
            }
        }
        else{

            if(a.coco_y >= 150 ){
                a.Move(10);
                a.coco_y-=10;

            }

            else if(a.coco_y >= 140){
                a.Move(10);

                 a.coco_y-=10;

            }
            else if(a.coco_y >= 20){
                 a.Move(20);
                 a.coco_y-=20;
            }
            else if(a.coco_y > 0){
                 a.Move(10);
                 a.coco_y-=10;
            }
            else if(a.coco_y == 0) {
                 a.Move(0);
                 a.jumptoggle = false;
                 a.uptoggle = true;
            }
        }
    }


}

void Widget::on_pushButton_2_clicked()
{
    m.m1_toggle = true;
    t.tree_toggle = true;
}


void Widget::on_pushButton_3_pressed()
{

    a.lie();

}


void Widget::on_pushButton_3_released()
{
    a.rise();
}


void Widget::on_pushButton_4_attack_clicked()
{

    if(!a.bimtoggle){
        a.bim_y = a.coco_y;
    }

    a.bimtoggle = true;

}


void Widget::on_pushButton_5_restart_clicked()
{
    heart = 3;
    restart = false;
}

