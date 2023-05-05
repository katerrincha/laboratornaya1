#include "fileprinter.h"
#include <iostream>
#include <QTextStream>
#include <QTextCodec>
using namespace std;

fileprinter::fileprinter()
{    

}

void fileprinter::printexists(QString f_name, qint64 f_size) // вывод при создании файла
{
    cout << "created file: "<<  f_name.toStdString() << ", size: " << f_size << endl;
}
void fileprinter::printdeleted(QString f_name) // вывод при удалении файла
{
    cout << "deleted file: "<<  f_name.toStdString() << endl;
}
void fileprinter::printchanged(QString f_name, qint64 f_size) // вывод при изменении размера файла
{
    cout << "changed size of file: "<<  f_name.toStdString() << ", new size: " << f_size << endl;
}

