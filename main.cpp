#include <QCoreApplication>
#include <iostream>
#include <classinf.h>
#include "filemonitor.h"
#include "fileprinter.h"
#include <thread>
#include <chrono>
#include <QLocale>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "Russian");
    FileMonitor F; // создаем объекты классов
    fileprinter P;

    F.addfile("C:\\filesQt\\f1.txt"); // добавляем файл

    QObject::connect(&F, &FileMonitor::fileexists, &P, &fileprinter::printexists); // организуем сигнально-слотовое соединение
    QObject::connect(&F, &FileMonitor::filechanged, &P, &fileprinter::printchanged);
    QObject::connect(&F, &FileMonitor::filedeleted, &P, &fileprinter::printdeleted);

    while(true)
    {
        F.updatef();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return a.exec();
}
