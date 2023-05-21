# laboratornaya1
Написать программу для слежения за состоянием выбранного файла.

Ограничимся  двумя характеристиками:
1. Существует файл или нет;
2. Каков размер файла.

Программа будет выводить на консоль уведомление о произошедших изменениях в файле.
Существует несколько ситуаций для наблюдаемого файла

1. Файл существует , файл не  пустой - на экран выводится факт существования файла и его  размер.
2. Файл существует, файл был изменен - на экран выводится факт существования файла, сообщение о том что файл был изменен и его размер.  
3. Файл не существует - на экран выводится информация о том что файл не существует.

Решение:
Моя программа состоит из классов: ClassInf, хранящий информацию о файле (размер, имя, файкт существования), 
FileMonitor, хранящий объекты, за которыми будут выполняться наблюдения, и отслеживающий их изменения (файл создали, удалили или изменили его размер)
и класс fileprinter, который выводит информацию о произошедших измемениях с конкретным файлом.

![Image alt](https://github.com/katerrincha/laboratornaya1/blob/master/UML%20laboratornaya1.png)
