#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "classinf.h"
#include <QObject>
#include <QVector>

class FileMonitor: public QObject
{
    Q_OBJECT
private:
    QVector <ClassInf> fileinfo; // контейнер

public:
    bool addfile(QString fName); // добавление нового файла в рассмотрение
    void updatef(); // обновление информации о файлах
    FileMonitor();

signals: // сигналы:
    void fileexists(QString fName, qint64 f_size); // сигнал о том, что файл создан
    void filechanged(QString fName, qint64 f_size); // сигнал об измнении размера файла
    void filedeleted(QString fName); // сигнал о том, что файл был удалён

};

#endif // FILEMONITOR_H
