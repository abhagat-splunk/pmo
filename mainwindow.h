#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int amp,fre,time,nos;
private:
    Ui::MainWindow *ui;
private slots:\
    void create();
};

#endif // MAINWINDOW_H
