#include <iostream>
#include "Buffer_handler.h"
class DataBlock {

    char* buf; // ��������� �� �������� �����
    int offset; // �������� �� ������ ������
    int size; // ������ ����� � ������

public:
    // ����������� �� ������� ����
    DataBlock(char* data, int offset, int size) : buf(data), offset(offset), size(size) {}
    // ����������� �� ������� DataBlock � ����������� ��������
    DataBlock(const DataBlock& other, int offset) : buf(other.buf), offset(other.offset + offset), size(other.size) {}

    // ������ ����� �� �������
    char getByte(int index) const {
        if (index < 0 || index >= size) {
            std::cerr << "������: ������ �� ��������� �����\n";
            return 0;
        }
        return buf[offset + index];
    }

    // ������ ����� �� �������
    void setByte(int index, char value) {
        if (index < 0 || index >= size) {
            std::cerr << "������: ������ �� ��������� �����\n";
            return;
        }
        buf[offset + index] = value;
    }

    // ������� ��� ������ �������� �� �����
    short getdata(int start, int len) const {
        return extractdata(buf, start + offset * 8, len); // ����� ������� �� ����� 1
    }

    // ������� ��� ������ �������� � ����
    void setdata(int start, int len, short value) {
        putdata(buf, start + offset * 8, len, value); // ����� ������� �� ����� 1
    }
};

