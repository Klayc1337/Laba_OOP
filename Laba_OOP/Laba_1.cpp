#include "index.h"

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        string text, phindWord;
        cout << "������� ��� �����.txt(���� ����� ����������� ������ �� 100 ������� � �� 100 �����): ";
        cin >> text;
        cout << "������� ����� ������� ���� �����: ";
        cin >> phindWord;
        cout << endl;

        Index index;
        index.loadText(text);
        index.findWord(phindWord);  // ����� �����
        index.printResult();  // �������� ��������� ��������
    }
    catch (const exception& e) {
        cout << "������: " << e.what() << endl;
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
    vector<string> pages;  // ������ �������
    string pageNumbers;         // ������ �������, ��� ������� �����

public:
    Index(const string& filename);  // ����������� ��� �������� ������ �� �����
    void searchWord(const string& word);  // ����� �����
    string getPageNumbers() const;  // �������� ������ �������
};

// ���������� �������

// �����������: ��������� ����� �� ����� � ��������� ��� �� ��������
Index::Index(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "�� ������� ������� ����!" << endl;
        return;
    }

    string line;
    string page;
    while (getline(file, line)) {
        if (line == "---PAGE---") {
            // ��������� ������� �������� � ������ �������
            pages.push_back(page);
            page.clear();  // ������� ��� ����� ��������
        }
        else {
            page += line + "\n";
        }
    }
    // ��������� ��������� ��������, ���� ��������
    if (!page.empty()) {
        pages.push_back(page);
    }
    file.close();
}

// ����� ������ ����� �� ���������
void Index::searchWord(const string& word) {
    pageNumbers.clear();  // ������� ������ � �������� ������� ����� ����� �������

    for (size_t i = 0; i < pages.size(); ++i) {
        if (pages[i].find(word) != string::npos) {
            pageNumbers += to_string(i + 1) + " ";  // ��������� ������� ���������� � 1
        }
    }

    if (pageNumbers.empty()) {
        pageNumbers = "����� �� �������!";
    }
}

// ����� ��������� ������� �������, ��� ������� �����
string Index::getPageNumbers() const {
    return pageNumbers;
}

// ������ �������������
int main() {
    Index index("j.txt");

    string word;
    cout << "������� ����� ��� ������: ";
    cin >> word;

    index.searchWord(word);
    cout << "����� ������� �� ���������: " << index.getPageNumbers() << endl;
    

    return 0;
}
*/