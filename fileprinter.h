#ifndef FILEPRINTER_H
#define FILEPRINTER_H
#include <QObject>
#include <QString>

class fileprinter: public QObject
{
public:
    fileprinter();

public slots:
    void printexists(QString f_name, qint64 f_size); // вывод при создании файла
    void printdeleted(QString f_name); // вывод при удалении файла
    void printchanged(QString f_name, qint64 f_size); // вывод при измнении файла
    void printaddtoMonitor(QString f_name); // вывод при добавлении файла в монитор
    void printdelfromMonitor(QString f_name); // вывод при удалении файла из монитора

};

#endif // FILEPRINTER_H
