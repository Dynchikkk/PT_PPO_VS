#include "loadtime.h"
#include <iostream>
#include <stdexcept>

int OpenDocument(const char* filename) {
    try {
        std::cout << "Opening document: " << filename << std::endl;
        if (!filename) {
            throw std::runtime_error("Filename is null!");
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return -1; // ���������� ��� ������
    }
    return 0; // �������� ����������
}

int CloseDocument() {
    try {
        std::cout << "Closing document." << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return -1; // ���������� ��� ������
    }
    return 0; // �������� ����������
}

int GenerateException() {
    try {
        throw std::runtime_error("Generated exception in Load-time DLL");
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return -1; // ���������� ��� ������
    }
    return 0; // �������� ����������
}
