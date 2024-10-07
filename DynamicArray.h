#pragma once
class DynamicArray
{
private:
	int logicalSize;	// ���������� ������ ������� (���������� ����������� ���������)
	int actualSize;		// ���������� ������ ������� (���������� ��������� ���������)
	int* arr;		// ������

	void copyArr(int* newArray);	// ����������� ��������� ��� �������� ������ �������

public:
	
	DynamicArray(int actual_size, int locgial_size);

	int getLogicalSize();
	int getActualSize();
	void setElement(int index, int number);
	int* getArr();

	void add(int number);	// ���������� � ����� �������
	void removeHead();	// �������� �������� � �������� 0

	~DynamicArray();
};

