#include "index.h"

// ����� �������� ������ �� ����� � ��������� �� ��������
void Index::loadText(const string& fileName) {
    ifstream file(fileName);

    // ��������� ������ �������� �����
    if (!file.is_open()) 
        throw runtime_error("������ �������� �����!");
    

    string line;
    stringstream pageContent;  // ��� ���������� ����� ��������
    int lineCounter = 0;

    while (getline(file, line)) {
        // �������� ������������� ���������� ������� 
        if (pageCount_ >= MAX_PAGES_) {
            throw runtime_error("��������� ����� �� ���������� ������� 100");
        }

        pageContent << line << "\n";  // ��������� ������ � ������� ��������
        lineCounter++;

        // ��������� ������ ���� � ����� ������ 5 �����
        if (lineCounter - 1 < 5 and line.empty()) {
            throw runtime_error("� ����� ������ ���� �� ����� 5 �����!");
        }

        // ��������� ������ ���� � ����� ��� ����� �������� ������ 100 �����
        if (lineCounter > MAX_LINES_ON_PAGE_) {
            throw runtime_error("��������� ����� �� ���������� ����� �� �������� (100)" );
        }

        // ������� ��� �������� ����� ��������: ���� ��������� ������������ ���������� �����, ���� ��������� ������ ������
        if (line.empty()) {
            pages_[pageCount_] = pageContent.str();  // ��������� ����������� ��������
            pageCount_++;  // ����������� ���������� �������
            pageContent.str("");  // ������� ��� ��������� ��������
            pageContent.clear();  // ���������� ����� ������
            lineCounter = 0;  // ���������� ������� �����
        }
    }

    // ��������� ��������� ��������, ���� ��� ����������
    if (lineCounter > 0 and pageCount_ < MAX_PAGES_) {
        pages_[pageCount_] = pageContent.str();
        pageCount_++;
    }

    // ��������� ������ ���� � ����� ������ 5 �������
    if (pageCount_ < 5) {
        throw runtime_error("� ����� ������ ���� �� ����� 5 �������!");
    }

    // �������� �����
    file.close();
}

// ����� ������ ����� � �������� ������� �������
void Index::findWord(const string& word) {
    indexResult_.clear();  // ������� ���������� ����������
    for (int i = 0; i < pageCount_; ++i) {
        if (pages_[i].find(word) != string::npos) {
            indexResult_ += to_string(i + 1) + " ";  // ��������� ����� �������� � ���������
        }
    }

    if (indexResult_.empty()) {
        indexResult_ = "����� �� �������!";
    }
}

void Index::printResult() const {
    cout << "����� ������� �� ���������: " << indexResult_ << endl;
}

// ����� �������� ������ �� ����� � ��������� �� ��������
//void Index::loadText(const string& fileName) {
//    ifstream file(fileName);
//
//    if (!file.is_open()) {
//        throw runtime_error("������ �������� �����!");
//    }
//
//    string line;
//    stringstream pageContent;  // ��� ���������� ����� ��������
//    int lineCounter = 0;
//
//    while (getline(file, line)) {
//        if (pageCount_ >= MAX_PAGES_) {
//            cout << "��������� ����� �� ���������� ������� (" << MAX_PAGES_ << ")" << endl;
//            break;
//        }
//
//        pageContent << line << "\n";  // ��������� ������ � ������� ��������
//        lineCounter++;
//
//        // ������� ��� �������� ����� ��������: ���� ��������� ������������ ���������� �����, ���� ��������� ������ ������
//        if (lineCounter >= MAX_LINES_PER_PAGE || line.empty()) {
//            pages_[pageCount_] = pageContent.str();  // ��������� ����������� ��������
//            pageCount_++;  // ����������� ���������� �������
//            pageContent.str("");  // ������� ��� ��������� ��������
//            pageContent.clear();  // ���������� ����� ������
//            lineCounter = 0;  // ���������� ������� �����
//        }
//    }
//
//    // ��������� ��������� ��������, ���� ��� ����������
//    if (lineCounter > 0 && pageCount_ < MAX_PAGES_) {
//        pages_[pageCount_] = pageContent.str();
//        pageCount_++;
//    }
//
//    // �������� �����
//    file.close();
//}