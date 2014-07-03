#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <math.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(create()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create()
{
fre = ui->lineEdit->text().toInt();
amp = ui->lineEdit_2->text().toInt();
time = ui->lineEdit_3->text().toInt();
nos= ui->lineEdit_4->text().toInt();
QImage image(791,321,QImage::Format_ARGB32);
QRgb value = qRgb(0,0,255);

for(int we =0; we<771;we++)
{
image.setPixel(we,321/2,value);
}

for(int we =0; we<321;we++)
{
image.setPixel(771/2,we,value);
}

//for(int x=0; x<time; x++)
//{
//    float y;
//    y = amp*(sin(2*3.14*fre)/time);
//    image.setPixel(x,30+y+amp,value);
//}

for(int i=0;i<time;i++)
{
    float y=(amp*(sin((2*3.14*i)*fre)));
    float fin = y+321/2;
    image.setPixel((771/2)+i,y+321/2,value);
    if (fin>321/2)
    {
    for(int j = 0;j<nos;j++)
    {
    for(int qw=321/2;qw<fin;qw++)\
    {
        image.setPixel(772/2+i,qw,value);
    }
    }
    }
}

ui->drawlabel->clear();
ui->drawlabel->setPixmap(QPixmap::fromImage(image));
ui->drawlabel->show();
}
