#include <iostream>
#include "Buffer_handler.h"
class DataBlock {

    char* buf; // Указатель на исходный буфер
    int offset; // Смещение от начала буфера
    int size; // Размер блока в байтах

public:
    // Конструктор из массива байт
    DataBlock(char* data, int offset, int size) : buf(data), offset(offset), size(size) {}
    // Конструктор из объекта DataBlock с добавлением смещения
    DataBlock(const DataBlock& other, int offset) : buf(other.buf), offset(other.offset + offset), size(other.size) {}

    // Чтение байта по индексу
    char getByte(int index) const {
        if (index < 0 || index >= size) {
            std::cerr << "Ошибка: Индекс за пределами блока\n";
            return 0;
        }
        return buf[offset + index];
    }

    // Запись байта по индексу
    void setByte(int index, char value) {
        if (index < 0 || index >= size) {
            std::cerr << "Ошибка: Индекс за пределами блока\n";
            return;
        }
        buf[offset + index] = value;
    }

    // Функция для чтения значения из блока
    short getdata(int start, int len) const {
        return extractdata(buf, start + offset * 8, len); // Вызов функции из части 1
    }

    // Функция для записи значения в блок
    void setdata(int start, int len, short value) {
        putdata(buf, start + offset * 8, len, value); // Вызов функции из части 1
    }
};

