#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
using namespace std;
#include <QMessageBox>
#include<QPixmap>
#include<QFile>
#include<QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/prapt.DESKTOP-OD4ASE9/OneDrive/Documents/PSW/Password/imgpsw.png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_save_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString sitename = ui->lineEdit_sitename->text();
    ui->statusbar->showMessage("Username and password is saved.",5000);
    //QMessageBox::information(this,"Save","Username and password is saved.");
    QFile file("C:/Users/prapt.DESKTOP-OD4ASE9/OneDrive/Documents/PSW/Password/Record_psd.txt");
    if(!file.open( QFile::append | QFile::Text)){
        QMessageBox::warning(this,"Title","File is not opened.");
    }
    QTextStream out(&file);
    QString text = ui->lineEdit_username->text();
    QString text1 = ui->lineEdit_password->text();
    QString text2 = ui->lineEdit_sitename->text();
    out <<"Username:\t"<< text<<endl;
    out <<"Password:\t"<< text1<<endl;
    out <<"Site Name:\t"<<text2<<endl;
    file.close();
}


