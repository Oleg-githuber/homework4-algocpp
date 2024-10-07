#pragma once
class DynamicArray
{
private:
	int logicalSize;	// Логический размер массива (количество заполненных элементов)
	int actualSize;		// Актуальный размер массива (количество созданных элементов)
	int* arr;		// Массив

	void copyArr(int* newArray);	// Копирование элементов при создании нового массива

public:
	
	DynamicArray(int actual_size, int locgial_size);

	int getLogicalSize();
	int getActualSize();
	void setElement(int index, int number);
	int* getArr();

	void add(int number);	// Добавление в конец массива
	void removeHead();	// Удаление элемента с индексом 0

	~DynamicArray();
};

