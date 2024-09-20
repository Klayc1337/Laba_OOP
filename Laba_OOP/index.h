#pragma once
//#ifndef INDEX_H
//#define INDEX_H

#include <iostream>      // Для вывода на консоль (std::cout)
#include <fstream>       // Для работы с файлами (std::ifstream)
#include <sstream>       // Для работы с потоками строк (std::stringstream)
#include <stdexcept>     // Для обработки исключений (std::runtime_error)
#include <string>        // Для работы со строками (std::string)
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;
using std::runtime_error;
using std::to_string;
using std::exception;

class Index {
public:
    static const int MAX_PAGES_ = 100;          // Максимальное количество страниц
    static const int MAX_LINES_ON_PAGE_ = 100; // Максимальное количество строк на страницу
    string pages_[MAX_PAGES_];                   // Статический массив для хранения страниц
    int pageCount_;                             // Текущее количество страниц
    string indexResult_;                        // Для хранения результатов поиска

public:
    // Создает класс и обнуляет текущие количество страниц
    Index() : pageCount_(0) {}

    // Метод для загрузки текста из файла
    void loadText(const string& fileName);

    // Метод для поиска слова в тексте и фиксации номеров страниц
    void findWord(const string& word);

    // Метод для вывода результатов поиска
    void printResult() const;

    // Деструктор
    ~Index() {};
};

