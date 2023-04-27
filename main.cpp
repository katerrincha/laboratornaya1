#include <QCoreApplication>
#include <iostream>
#include <classinf.h>
#include <filemonitor.h>
#include <fileprinter.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "Russian");
    //FileMonitor& mon; // создаем объект класса

    mon.addfile("C:/Qt/projects/laboratornaya1/f1.txt"); // добавляем файл
    //mon.delfile("C:/Qt/projects/laboratornaya1/f1.txt"); // удаляем файл


    return a.exec();
}
