#include <iostream>

// ������� ��� ������ �������� �� ������
short extractdata(char* buf, int start, int len) {
    // �������� ������������ �����
    if (start < 0 || len <= 0 || start + len > 8 * sizeof(buf)) {
        std::cerr << "������: ������������ �������� �����\n";
        return 0;
    }

    // ���������� �������� � ������ � �������� � �����
    int byte_offset = start / 8;
    int bit_offset = start % 8;

    // �������� ����� ��� ��������� ������ �����
    unsigned char mask = (1 << len) - 1;
    mask <<= bit_offset;

    // ������ ������ �� ������
    short value = (buf[byte_offset] & mask) >> bit_offset;

    // ��������� �����
    if (bit_offset + len > 8) {
        value |= (buf[byte_offset + 1] & (mask >> (8 - bit_offset))) << (len - (8 - bit_offset));
    }
    if (value & (1 << (len - 1))) {
        value |= ~((1 << len) - 1);
    }

    return value;
}

// ������� ��� ������ �������� � �����
void putdata(char* buf, int start, int len, short value) {
    // �������� ������������ �����
    if (start < 0 || len <= 0 || start + len > 8 * sizeof(buf)) {
        std::cerr << "������: ������������ �������� �����\n";
        return;
    }

    // ���������� �������� � ������ � �������� � �����
    int byte_offset = start / 8;
    int bit_offset = start % 8;

    // �������� ����� ��� ��������� ������ �����
    unsigned char mask = (1 << len) - 1;
    mask <<= bit_offset;

    // ������ �������� � �����
    buf[byte_offset] &= ~mask; // ����� ��� � ������
    buf[byte_offset] |= (value << bit_offset) & mask; // ������ ������ ��������

    // ��������� �����
    if (bit_offset + len > 8) {
        buf[byte_offset + 1] &= ~(mask >> (8 - bit_offset)); // ����� ��� � ������
        buf[byte_offset + 1] |= (value >> (8 - bit_offset)) & (mask >> (8 - bit_offset)); // ������ ������ ��������
    }
}

