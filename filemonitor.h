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
    FileMonitor();
    FileMonitor& operator= (FileMonitor const&);
    FileMonitor(FileMonitor const&);

public:
    bool addfile(QString fName); // добавление нового файла в рассмотрение
    void updatef(); // обновление информации о файлах
    bool deletefile(QString fName);
    static FileMonitor& Instance();

signals: // сигналы о том, что файл создан/изменен/удален
    void fileexists(QString fName, qint64 f_size);
    void filechanged(QString fName, qint64 f_size);
    void filedeleted(QString fName);
};

#endif // FILEMONITOR_H
