#include "index.h"

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        string text, phindWord;
        cout << "Введите имя файла.txt(файл будет считываться только до 100 страниц и до 100 строк): ";
        cin >> text;
        cout << "Введите слово которое надо найти: ";
        cin >> phindWord;
        cout << endl;

        Index index;
        index.loadText(text);
        index.findWord(phindWord);  // Поиск слова
        index.printResult();  // Показать найденные страницы
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}







/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Index {
public:
    vector<string> pages;  // Массив страниц
    string pageNumbers;         // Номера страниц, где найдено слово

public:
    Index(const string& filename);  // Конструктор для загрузки текста из файла
    void searchWord(const string& word);  // Поиск слова
    string getPageNumbers() const;  // Получить номера страниц
};

// Реализация методов

// Конструктор: загружает текст из файла и разделяет его на страницы
Index::Index(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не удалось открыть файл!" << endl;
        return;
    }

    string line;
    string page;
    while (getline(file, line)) {
        if (line == "---PAGE---") {
            // Добавляем текущую страницу в массив страниц
            pages.push_back(page);
            page.clear();  // Очищаем для новой страницы
        }
        else {
            page += line + "\n";
        }
    }
    // Добавляем последнюю страницу, если осталась
    if (!page.empty()) {
        pages.push_back(page);
    }
    file.close();
}

// Метод поиска слова на страницах
void Index::searchWord(const string& word) {
    pageNumbers.clear();  // Очищаем строку с номерами страниц перед новым поиском

    for (size_t i = 0; i < pages.size(); ++i) {
        if (pages[i].find(word) != string::npos) {
            pageNumbers += to_string(i + 1) + " ";  // Нумерация страниц начинается с 1
        }
    }

    if (pageNumbers.empty()) {
        pageNumbers = "Слово не найдено!";
    }
}

// Метод получения номеров страниц, где найдено слово
string Index::getPageNumbers() const {
    return pageNumbers;
}

// Пример использования
int main() {
    Index index("j.txt");

    string word;
    cout << "Введите слово для поиска: ";
    cin >> word;

    index.searchWord(word);
    cout << "Слово найдено на страницах: " << index.getPageNumbers() << endl;
    

    return 0;
}
*/