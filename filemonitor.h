#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "classinf.h"

class FileMonitor
{
public:
    FileMonitor();
    ~FileMonitor(); // дестр-р
    void AddFile(); // добавление файла
    void DelFile(); // удаление файла

};

#endif // FILEMONITOR_H
