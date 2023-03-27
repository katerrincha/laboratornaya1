#ifndef CLASSINF_H
#define CLASSINF_H

#include <QString>
#include <QFileInfo>

class ClassInf
{
    bool f_exist; //true or false
    int f_size;
    QString f_name;

public:
    ClassInf(); //констр-р по умолчанию
    ClassInf( );

    bool is_f_exist();
    int get_f_size();
    QString get_f_name();
};

#endif // CLASSINF_H
