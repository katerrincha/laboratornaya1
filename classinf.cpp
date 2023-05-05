#include "classinf.h"
#include <QString>
#include <QFileInfo>

ClassInf::ClassInf()
{

}
ClassInf::ClassInf(const QString& fName)
{
    f_name = fName;
    QFileInfo file (f_name); // инициализируем информацию, определяем параметры файла:
    f_size = file.size(); // определяем размер
    f_exist = file.exists(); // определяем, существует или нет
}

bool ClassInf::operator==(ClassInf f)const
{
    if (f.f_name != f_name)
        return false;
    else
        return true;
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


