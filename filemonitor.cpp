#include "filemonitor.h"

FileMonitor::FileMonitor(QString fName)
{

}

bool FileMonitor::addfile(QString fName) // добавление нового файла
{
    StateFile file1(fName);
    if (fileinfo.contains(file1)) // проверяем, есть ли уже этот файл
    {
        return false;
    }
    else
    {
        fileinfo.append(file1); // если файла нет - добавляем его
        emit addtoMonitor(file1); // подаётся сигнал о добавлении файла
        return true;
    }
}

bool FileMonitor::delfile(QString fName) // удаление файла
{
    StateFile file2(fName);
    if (fileinfo.contains(file2)) // проверяем, есть ли уже этот файл
    {
        fileinfo.removeOne(file2); // удаляем файл
        emit delfromMonitor(file2); // подаётся сигнал об удалении файла
        return true;
    }
    else
        return false;
}
