#include "DataBlock.h"

int main() {
	// �������� �����
	char buffer[10] = { 0 };

	// ������ ��������
	putdata(buffer, 0, 11, -5); // -5 (11 ���)
	putdata(buffer, 11, 6, 12); // 12 (6 ���)

	// ������ ��������
	short val1 = extractdata(buffer, 0, 11);
	short val2 = extractdata(buffer, 11, 6);

	// ����� �����������
	std::cout << "val1: " << val1 << std::endl; // �����: -5
	std::cout << "val2: " << val2 << std::endl; // �����: 12

	// �������� �����
	char data[20] = { 0 };

	// �������� ����� ������
	DataBlock block(data, 0, 10);

	// ������ �������� � ����
	block.setdata(0, 11, -5); // ������ -5 � 11 ��� � 0-�� ����

	// �������� ������ �����, ���������� �� 10 ����
	DataBlock sub_block(block, 10);

	// ������ �������� �� �����
	short val = block.getdata(0, 11); // ������ �������� � 0-�� ����
	std::cout << "val: " << val << std::endl; // �����: -5

	return 0;
}