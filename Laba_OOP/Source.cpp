#include "index.h"

// Метод загрузки текста из файла и разбиения на страницы
void Index::loadText(const string& fileName) {
    ifstream file(fileName);

    // Обработка ошибки открытия файла
    if (!file.is_open()) 
        throw runtime_error("Ошибка открытия файла!");
    

    string line;
    stringstream pageContent;  // Для накопления строк страницы
    int lineCounter = 0;

    while (getline(file, line)) {
        // Проверка максимального количества страниц 
        if (pageCount_ >= MAX_PAGES_) {
            throw runtime_error("Достигнут лимит по количеству страниц 100");
        }

        pageContent << line << "\n";  // Добавляем строку в текущую страницу
        lineCounter++;

        // Обработка ошибки если в файле меньше 5 строк
        if (lineCounter - 1 < 5 and line.empty()) {
            throw runtime_error("В файле должно быть не менее 5 строк!");
        }

        // Обработка ошибки если в файле нат одной странице больше 100 строк
        if (lineCounter > MAX_LINES_ON_PAGE_) {
            throw runtime_error("Достигнут лимит по количеству строк на странице (100)" );
        }

        // Условие для создания новой страницы: либо превышено максимальное количество строк, либо встречена пустая строка
        if (line.empty()) {
            pages_[pageCount_] = pageContent.str();  // Сохраняем накопленную страницу
            pageCount_++;  // Увеличиваем количество страниц
            pageContent.str("");  // Очищаем для следующей страницы
            pageContent.clear();  // Сбрасываем флаги потока
            lineCounter = 0;  // Сбрасываем счетчик строк
        }
    }

    // Сохраняем последнюю страницу, если она существует
    if (lineCounter > 0 and pageCount_ < MAX_PAGES_) {
        pages_[pageCount_] = pageContent.str();
        pageCount_++;
    }

    // Обработка ошибки если в файле меньше 5 страниц
    if (pageCount_ < 5) {
        throw runtime_error("В файле должно быть не менее 5 страниц!");
    }

    // Закрытие файла
    file.close();
}

// Метод поиска слова и фиксации номеров страниц
void Index::findWord(const string& word) {
    indexResult_.clear();  // Очищаем предыдущие результаты
    for (int i = 0; i < pageCount_; ++i) {
        if (pages_[i].find(word) != string::npos) {
            indexResult_ += to_string(i + 1) + " ";  // Добавляем номер страницы в результат
        }
    }

    if (indexResult_.empty()) {
        indexResult_ = "Слово не найдено!";
    }
}

void Index::printResult() const {
    cout << "Слово найдено на страницах: " << indexResult_ << endl;
}

// Метод загрузки текста из файла и разбиения на страницы
//void Index::loadText(const string& fileName) {
//    ifstream file(fileName);
//
//    if (!file.is_open()) {
//        throw runtime_error("Ошибка открытия файла!");
//    }
//
//    string line;
//    stringstream pageContent;  // Для накопления строк страницы
//    int lineCounter = 0;
//
//    while (getline(file, line)) {
//        if (pageCount_ >= MAX_PAGES_) {
//            cout << "Достигнут лимит по количеству страниц (" << MAX_PAGES_ << ")" << endl;
//            break;
//        }
//
//        pageContent << line << "\n";  // Добавляем строку в текущую страницу
//        lineCounter++;
//
//        // Условие для создания новой страницы: либо превышено максимальное количество строк, либо встречена пустая строка
//        if (lineCounter >= MAX_LINES_PER_PAGE || line.empty()) {
//            pages_[pageCount_] = pageContent.str();  // Сохраняем накопленную страницу
//            pageCount_++;  // Увеличиваем количество страниц
//            pageContent.str("");  // Очищаем для следующей страницы
//            pageContent.clear();  // Сбрасываем флаги потока
//            lineCounter = 0;  // Сбрасываем счетчик строк
//        }
//    }
//
//    // Сохраняем последнюю страницу, если она существует
//    if (lineCounter > 0 && pageCount_ < MAX_PAGES_) {
//        pages_[pageCount_] = pageContent.str();
//        pageCount_++;
//    }
//
//    // Закрытие файла
//    file.close();
//}