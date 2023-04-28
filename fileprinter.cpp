#include "fileprinter.h"
#include <iostream>
using namespace std;

fileprinter::fileprinter()
{    
}

void fileprinter::printexists(QString f_name, int f_size) // вывод при создании файла
{
    cout << "Создан файл: "<<  f_name.toStdString() << ", размер: " << f_size << endl;
}
void fileprinter::printdeleted(QString f_name) // вывод при удалении файла
{
    cout << "Удалён файл: "<<  f_name.toStdString() << endl;
}
void fileprinter::printchanged(QString f_name, int f_size) // вывод при изменении размера файла
{
    cout << "Изменён размер файла: "<<  f_name.toStdString() << ", новый размер: " << f_size << endl;
}

void fileprinter::printaddtoMonitor(QString f_name) // вывод при добавлении файла в монитор
{
    cout << "В мониторинг поступил файл: " << f_name.toStdString() << ", размер: " << f_size << endl;
}
void fileprinter::printdelfromMonitor(QString f_name) // вывод при удалении файла из монитора
{
    cout << "Из монитора удалён файл: " << f_name.toStdString() << endl;
}

