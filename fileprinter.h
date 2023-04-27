#ifndef FILEPRINTER_H
#define FILEPRINTER_H
#include <QObject>
#include <QString>

class fileprinter
{
public:
    fileprinter();

public slots:
    void printexists(QString f_name, int f_size); // вывод при создании файла
    void printdeleted(QString f_name); // вывод при удалении файла
    void printchanged(QString f_name, int f_size); // вывод при измнении файла
};

#endif // FILEPRINTER_H
