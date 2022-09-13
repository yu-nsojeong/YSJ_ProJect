#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsItem>



//#include <QSize>
#include <QString>

//#include <QGraphicsScene>
#include <QTransform>


#include <QPixmap>

//#include <QGraphicsView>

#include <QApplication>
//#include <QKeyEvent>

//#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QTimer>
//#include <QDir>
//#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void myfunction();
    void myscreen();


    void on_pushButton_2_clicked();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_4_attack_clicked();

    void on_pushButton_5_restart_clicked();

private:
    Ui::Widget *ui;

    QGraphicsScene * scene;

    QTimer * timer;//타이머
};
#endif // WIDGET_H
