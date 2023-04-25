#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "classinf.h"
#include <QObject>
#include <QVector>

class FileMonitor
{
private:
    Q_OBJECT
    QVector <StateFile> fileinfo;

public:
    FileMonitor(); // конструктор
    //~FileMonitor(); // деструктор
    bool addfile(QString fName); // добавление нового файла
    bool delfile(QString fName); // удаление файла
    void updatefiles(); // обновление информации о файлах

signals:
    void fileexists(QString fName, f_size); // сигнал о том, что файл создан
    void filechanged(QString fName, f_size); // сигнал об измнении размера файла
    void filedeleted(QString fName); // сигнал о том, что файл был удалён
    void addtoMonitor(QString fName); // сигнал о добавлении файла
    void delfromMonitor(QString fName); // сигнал об удалении файла
};

#endif // FILEMONITOR_H
