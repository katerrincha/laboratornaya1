#ifndef CLASSINF_H
#define CLASSINF_H
#include <QString>
#include <QFileInfo>

class ClassInf
{
// работа с полями: факт существования, размер и имя файла
private:
    bool f_exist; // статус: true or false
    qint64 f_size;
    QString f_name;

public:
    ClassInf(); // констр-р по умолчанию
    ClassInf(const QString& fName); // конструктор с аргументом
    bool is_f_exist(); // определяем существование файла
    int get_f_size(); // определяем размер файла
    QString get_f_name(); // определяем имя файла
};

#endif // CLASSINF_H
