#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "classinf.h"
#include <QObject>
#include <QVector>

class FileMonitor: public QObject
{
private:
    Q_OBJECT
    QVector <ClassInf> fileinfo; // контейнер

public:
    FileMonitor();
    bool addfile(QString fName); // добавление нового файла
    bool delfile(QString fName); // удаление файла

signals: // сигналы:
    void fileexists(QString fName, qint64 f_size); // сигнал о том, что файл создан
    void filechanged(QString fName, qint64 f_size); // сигнал об измнении размера файла
    void filedeleted(QString fName); // сигнал о том, что файл был удалён
    void addtoMonitor(QString fName); // сигнал о добавлении файла в монитор
    void delfromMonitor(QString fName); // сигнал об удалении файла

public slots:
    void updatef(); // обновление информации о файлах
};

#endif // FILEMONITOR_H
