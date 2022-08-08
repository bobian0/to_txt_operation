#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//-----------------------------------------------------------------读取.txt文件（1）----------------------------------------------------------
//一次性打印出文件中所有内容
    QString displayString;
    QFile file("path");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "can't open file~" << endl;
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        qDebug() << str;
        displayString.append(str);
    }
    ui->textEidt->clear();
    ui->textEidt->setPlainText(displayString);

//-----------------------------------------------------------------读取.txt文件（2）----------------------------------------------------------

//    QString displayString;
//    QFile file("path");

//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug() << "can't open file~" << endl;
//        return;
//    }

//    QTextStream in(&file);
//    QString line = in.readLine();

//    while(!line.isNull())
//    {
//        //process_line(line);
//        line = in.readLine();
//        displayString.append(line);
//        qDebug() << line << endl;
//    }
//    ui->textEidt->clear();
//    ui->textEidt->setPlainText(displayString);

//-----------------------------------------------------------------读取.txt文件（3）----------------------------------------------------------
//    QString displayString;
//    QFile file("path");
//    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
//    {
//        qDebug() << "can't open file~" << endl;
//    }
//    QTextStream stream(&file);
//    QString line_in;
//    //将当前读取文件指针移动到文件末尾
//    stream.seek(file.size());
//    int count = 0;
//    while (count < 10)
//    {
//        //写入
//        stream << QObject::trUtf8("新建行:") << ++count << "/n";
//    }
//    //将当前读取文件指针移动到文件开始
//    stream.seek(0);
//    while (!stream.atEnd())
//    {
//        line_in = stream.readLine();
//        displayString.append(line_in);
//        qDebug() << line_in;
//    }
//    ui->textEidt->clear();
//    ui->textEidt->setPlainText(displayString);

//---------------------------------------------------------------写入.txt文件--------------------------------------------------------------
//    QFile file("path");
//    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
//    {
//        qDebug() << "open file~";
//        return;
//    }
//    int y = 1;

//    QTextStream txtOutput(&file);
//    QString s1(QString::number(y));
//    //quint32 n1(123456789);

//    //第一行
////    txtOutput << QString::fromStdString("1 2 3 4 5 6") << endl;
//    txtOutput << s1 << endl;

//    //file.close();
}



MainWindow::~MainWindow()
{
    delete ui;
}

