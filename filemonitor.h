#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "classinf.h"
#include <QObject>
#include <QVector>

class FileMonitor
{
    Q_OBJECT

public:
    bool addfile(QString fName); // добавление нового файла
    bool delfile(QString fName); // удаление файла
    void updatef(); // обновление информации о файлах

signals:
    void fileexists(QString fName, f_size); // сигнал о том, что файл создан
    void filechanged(QString fName, f_size); // сигнал об измнении размера файла
    void filedeleted(QString fName); // сигнал о том, что файл был удалён
    void addtoMonitor(QString fName); // сигнал о добавлении файла
    void delfromMonitor(QString fName); // сигнал об удалении файла

private:
    QVector <StateFile> fileinfo;
    FileMonitor(); // конструктор

};

#endif // FILEMONITOR_H
