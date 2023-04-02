#include "classinf.h"
#include <QString>
#include <QFileInfo>

ClassInf::ClassInf(const QString& fName)
{
    f_name = fName;
    QFileInfo file (f_name); // создаем объект и определяем его параметры
    f_size = file.exists();
    f_exist = file.exists();
}

bool ClassInf::is_f_exist() // определяем существование
{
    return f_exist;
}
int ClassInf::get_f_size() // определяем размер файла
{
    return f_size;
}
QString ClassInf::get_f_name() // определяем имя файла
{
    return f_name;
}
