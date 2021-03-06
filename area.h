#ifndef AREA_H
#define AREA_H
/*!
\file
\brief Заголовочный файл с описанием классов, относящихся к областям, на которых будет искаться минимум функции.
*/
#include <vector>
#pragma once
/*!
    \brief Родительский виртуальный класс областей.
    Область представляет собой декартово произведение нескольких отрезков.
*/
class area {
public:
    //! Целочисленная переменная.
    /*! Xранит размерность области. */
    int k;
    //! Массив пар вещественных значений.
    /*! Хранит координаты интервалов, задающих область. */
    std::vector<std::pair<double, double>> coord;
    //! Конструктор.
    /*! Записывает число координат в соответствующее поле.
     *\param dim Число координат.
     */
    area(int dim);
    virtual ~area(){}
};

/*!
    \brief Дочерний класс области.
    Представляет собой зафиксированную область, представляющую собой декартово произведение отрезков [-10,10] по каждой координате.
    Унаследован от ранее созданного класса area.
*/
class area_easy:public area {
public:
    //! Конструктор.
    /*! Создает массив пар (-10,10), записывает в соответствующее поле.
     *\param dim Число координат.
     */
    area_easy(int);
    ~area_easy(){}
};

/*!
    \brief Дочерний класс области.
    Область задается пользователем.
    Унаследован от ранее созданного класса area.
*/
class area_hard:public area{
public:
    //! Конструктор.
    /*! Копирует массив пар координат отрезков соответствующее поле.
     *\param x  Вектор координат.
     */
    area_hard(const std::vector<std::pair<double, double>> &x);
    ~area_hard(){}

};
#endif // AREA_H
