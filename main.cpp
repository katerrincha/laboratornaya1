#include <QCoreApplication>
#include <iostream>
#include <classinf.h>
#include <filemonitor.h>
#include <fileprinter.h>
#include <thread>
#include <chrono>
#include <QString>
#include <QTextStream>
QTextStream cout(stdout);
QTextStream cin(stdin);

//using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //setlocale(LC_ALL, "Russian");
    QString str, str1, str2, str3;
    FileMonitor& F = FileMonitor::Instance();
    fileprinter P;
    int n;

    //F.addfile("C:\filesQt\f1.txt");
    //F.addfile("C:\\filesQt\\f2.txt");

    QObject::connect(&F, &FileMonitor::fileexists, &P, &fileprinter::printexists); // организуем сигнально-слотовое соединение
    QObject::connect(&F, &FileMonitor::filechanged, &P, &fileprinter::printchanged);
    QObject::connect(&F, &FileMonitor::filedeleted, &P, &fileprinter::printdeleted);

    cout << "enter the file name to add:" << endl;
    cin >> str1 >> str2 >> str3;
    F.addfile(str1); // добавляем файлы для проверки
    F.addfile(str2);
    F.addfile(str3);
    cout << "do operations with files and set 1 to watch changes or 2 to delete file from the monitor: " << endl;

    while(true) // цикл для запуска проверки
    {
        cin >> n;
        if (n == 2)
        {
            cout << "enter the file name to delete: " << endl;
            cin >> str;
            F.deletefile(str);
            cout << "file: " << str << " deleted from the monitor" << endl;
        }
        else
        {
            F.updatef();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    return a.exec();
}
