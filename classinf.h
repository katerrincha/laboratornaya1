#ifndef CLASSINF_H
#define CLASSINF_H

#include <QString>
#include <QFileInfo>

class ClassInf
{
    bool f_exist; // статус: true or false
    int f_size;
    QString f_name;

public:
    ClassInf(); // констр-р по умолчанию
    ClassInf(const QString& fName);
    bool is_f_exist(); // определяем существование
    int get_f_size(); // определяем размер файла
    QString get_f_name(); // определяем имя файла
};

#endif // CLASSINF_H
