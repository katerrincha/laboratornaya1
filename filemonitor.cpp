#include "filemonitor.h"

FileMonitor::FileMonitor(QString fName)
{

}

bool FileMonitor::addfile(QString fName) // добавление нового файла
{
    StateFile file1(fName);

    if (fileinfo.contains(file1)) // проверяем, есть ли уже этот файл
        return false;
    else
    {
        fileinfo.append(file1); // если файла нет - добавляем его
        emit addtoMonitor(file1); // сигнал о добавлении
        return true;
    }
}

bool FileMonitor::delfile(QString fName) // удаление файла
{
    StateFile file2(fName);

    if (!fileinfo.contains(file2)) // проверяем, есть ли этот файл
        return false;
    else // если есть:
    {
        fileinfo.removeOne(file2); // удаляем файл
        emit delfromMonitor(file2); // сигнал об удалении
        return true;
    }
}

void FileMonitor::updatef() // обновление информации о файлах
{
    int i;
    for (i = 0; i < fileinfo.count(); i++)
    {
        StateFile newfile(fileinfo[i].get_f_name());
        if (newfile.is_f_exist() != fileinfo[i].is_f_exist()) // проверяем, создан ли файл
        {
            fileinfo[i] = newfile; // обновляем информацию
            emit fileexists(newfile.get_f_name(), newfile.get_f_size()); // подаётся сигнал о создании файла
        }
        else if () // иначе: удалён ли файл
        {
            fileinfo[i] = newfile;
            emit filedeleted(newfile.get_f_name()); // подаётся сигнал об удалении файла
        }
        else if (newfile.get_f_size() != fileinfo[i].get_f_size()) // иначе: изменился ли файл
        {
           fileinfo[i] = newfile;
           emit filechanged(newfile.get_f_name(), newfile.get_f_size()); // подаётся сигнал об изменении файла
        }
    }
}


