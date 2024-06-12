#include "DataBlock.h"

int main() {
	// Тестовый буфер
	char buffer[10] = { 0 };

	// Запись значений
	putdata(buffer, 0, 11, -5); // -5 (11 бит)
	putdata(buffer, 11, 6, 12); // 12 (6 бит)

	// Чтение значений
	short val1 = extractdata(buffer, 0, 11);
	short val2 = extractdata(buffer, 11, 6);

	// Вывод результатов
	std::cout << "val1: " << val1 << std::endl; // Вывод: -5
	std::cout << "val2: " << val2 << std::endl; // Вывод: 12

	// Тестовый буфер
	char data[20] = { 0 };

	// Создание блока данных
	DataBlock block(data, 0, 10);

	// Запись значения в блок
	block.setdata(0, 11, -5); // Запись -5 в 11 бит с 0-го бита

	// Создание нового блока, смещенного на 10 байт
	DataBlock sub_block(block, 10);

	// Чтение значения из блока
	short val = block.getdata(0, 11); // Чтение значения с 0-го бита
	std::cout << "val: " << val << std::endl; // Вывод: -5

	return 0;
}