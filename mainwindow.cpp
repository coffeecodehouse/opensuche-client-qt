#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          this->size(),
                          qApp->desktop()->availableGeometry()
                      ));
}

bool MainWindow::event(QEvent *event) {
    if (event->type() == QEvent::ActivationChange)
        {
            if(QApplication::activeWindow() != this)
            {
                this->close();
            }
        }
    return QWidget::event(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}
