#pragma once
//#ifndef INDEX_H
//#define INDEX_H

#include <iostream>      // ��� ������ �� ������� (std::cout)
#include <fstream>       // ��� ������ � ������� (std::ifstream)
#include <sstream>       // ��� ������ � �������� ����� (std::stringstream)
#include <stdexcept>     // ��� ��������� ���������� (std::runtime_error)
#include <string>        // ��� ������ �� �������� (std::string)
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
    static const int MAX_PAGES_ = 100;          // ������������ ���������� �������
    static const int MAX_LINES_ON_PAGE_ = 100; // ������������ ���������� ����� �� ��������
    string pages_[MAX_PAGES_];                   // ����������� ������ ��� �������� �������
    int pageCount_;                             // ������� ���������� �������
    string indexResult_;                        // ��� �������� ����������� ������

public:
    // ������� ����� � �������� ������� ���������� �������
    Index() : pageCount_(0) {}

    // ����� ��� �������� ������ �� �����
    void loadText(const string& fileName);

    // ����� ��� ������ ����� � ������ � �������� ������� �������
    void findWord(const string& word);

    // ����� ��� ������ ����������� ������
    void printResult() const;

    // ����������
    ~Index() {};
};

