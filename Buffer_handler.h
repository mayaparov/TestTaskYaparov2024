#include <iostream>

// Функция для чтения значения из буфера
short extractdata(char* buf, int start, int len) {
    // Проверка корректности ввода
    if (start < 0 || len <= 0 || start + len > 8 * sizeof(buf)) {
        std::cerr << "Ошибка: Некорректный диапазон битов\n";
        return 0;
    }

    // Вычисление смещения в байтах и смещения в битах
    int byte_offset = start / 8;
    int bit_offset = start % 8;

    // Создание маски для выделения нужных битов
    unsigned char mask = (1 << len) - 1;
    mask <<= bit_offset;

    // Чтение данных из буфера
    short value = (buf[byte_offset] & mask) >> bit_offset;

    // Обработка знака
    if (bit_offset + len > 8) {
        value |= (buf[byte_offset + 1] & (mask >> (8 - bit_offset))) << (len - (8 - bit_offset));
    }
    if (value & (1 << (len - 1))) {
        value |= ~((1 << len) - 1);
    }

    return value;
}

// Функция для записи значения в буфер
void putdata(char* buf, int start, int len, short value) {
    // Проверка корректности ввода
    if (start < 0 || len <= 0 || start + len > 8 * sizeof(buf)) {
        std::cerr << "Ошибка: Некорректный диапазон битов\n";
        return;
    }

    // Вычисление смещения в байтах и смещения в битах
    int byte_offset = start / 8;
    int bit_offset = start % 8;

    // Создание маски для выделения нужных битов
    unsigned char mask = (1 << len) - 1;
    mask <<= bit_offset;

    // Запись значения в буфер
    buf[byte_offset] &= ~mask; // Сброс бит в буфере
    buf[byte_offset] |= (value << bit_offset) & mask; // Запись нового значения

    // Обработка знака
    if (bit_offset + len > 8) {
        buf[byte_offset + 1] &= ~(mask >> (8 - bit_offset)); // Сброс бит в буфере
        buf[byte_offset + 1] |= (value >> (8 - bit_offset)) & (mask >> (8 - bit_offset)); // Запись нового значения
    }
}

