#include "classinf.h"
#include <QString>
#include <QFileInfo>

ClassInf::ClassInf(const QString& fName)
{
    f_name = fName;
    QFileInfo file (f_name); // создаем объект и определяем его параметры:
    f_size = file.size(); // определяем размер
    f_exist = file.exists(); // определяем, существует или нет
}

// геттеры:

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


