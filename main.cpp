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
    FileMonitor F; // создаем объекты классов
    fileprinter P;

    F.addfile("C:/Qt/projects/laboratornaya1/f1.txt"); // добавляем файл
    //F.delfile("C:/Qt/projects/laboratornaya1/f1.txt"); // удаляем файл

    QObject::connect(&F, &FileMonitor::fileexists, &P, &fileprinter::printexists); // организуем сигнально-слотовое соединение
    QObject::connect(&F, &FileMonitor::filechanged, &P, &fileprinter::printchanged);
    QObject::connect(&F, &FileMonitor::filedeleted, &P, &fileprinter::printdeleted);

    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return a.exec();
}
