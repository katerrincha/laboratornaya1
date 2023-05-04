#include "filemonitor.h"

FileMonitor::FileMonitor()
{
}

bool FileMonitor::addfile(QString fName) // добавление нового файла
{
    ClassInf file1(fName);

    if (fileinfo.contains(file1)) // проверяем, есть ли уже этот файл
        return false;
    else
    {
        fileinfo.append(file1); // если файла нет - добавляем его
        return true;
    }
}

void FileMonitor::updatef() // обновление информации о файлах
{
    int i;
    for (i = 0; i < fileinfo.count(); i++)
    {
        ClassInf newfile(fileinfo[i].get_f_name());
        if ((newfile.is_f_exist() != fileinfo[i].is_f_exist()) && (newfile.is_f_exist())) // проверяем, создан ли файл
        {
            fileinfo[i] = newfile; // обновляем информацию
            emit fileexists(newfile.get_f_name(), newfile.get_f_size()); // подаётся сигнал о создании файла
        }
        else if ((newfile.is_f_exist() != fileinfo[i].is_f_exist()) && (!newfile.is_f_exist())) // иначе: удалён ли файл
        {
            fileinfo[i] = newfile;
            emit filedeleted(newfile.get_f_name()); // подаётся сигнал об удалении файла
        }
        else if ((newfile.get_f_size() != fileinfo[i].get_f_size()) && (newfile.is_f_exist())) // иначе: изменился ли файл
        {
           fileinfo[i] = newfile;
           emit filechanged(newfile.get_f_name(), newfile.get_f_size()); // подаётся сигнал об изменении файла
        }
    }
}








