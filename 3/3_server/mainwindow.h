#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QAxObject>
#include <QtAlgorithms>
#include <QVector>
#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Server *server;
    QJsonObject StringToJson (QString a);
    QString JsonToString (QJsonObject *a);
    void opr(int k);
    QJsonObject check (QJsonObject );
    void slotSendRequest (bool);
    void slotOperationFinish (bool, QPair<QString, int>);
    void slotProcess (QPair<QString, int>, QJsonObject);
    QPair<QString, int> curAg;

private slots:
    QString sr_bal(int oc1, int oc2, int oc3, int oc4, int oc5);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void appendline (QJsonObject &, QPair<QString, int> &);
signals:
    void makeConnection (QPair<QString, int>);
    void sendMessage (QString, QPair<QString, int>);

private:
    Ui::MainWindow *ui;
    QAxObject *excel;
    QAxObject *workbooks;
    QAxObject *workbook;
    QAxObject *sheets;
    QAxObject *good;
};
#endif // MAINWINDOW_H
