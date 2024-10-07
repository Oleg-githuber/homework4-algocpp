#include "DynamicArray.h"

DynamicArray::DynamicArray(int actual_size, int logical_size) : actualSize{actual_size}, logicalSize{logical_size}, arr{ new int[actualSize] }
{}

int DynamicArray::getActualSize()
{
	return actualSize;
}

int DynamicArray::getLogicalSize()
{
	return logicalSize;
}

// Изменение элемента по индексу
void  DynamicArray::setElement(int index, int number)
{
	if (index < logicalSize)
	{
		arr[index] = number;
	}
}

int* DynamicArray::getArr()
{
	return arr;
}

// Добавление элемента в конец массива
void DynamicArray::add(int number)
{
	if (logicalSize < actualSize)
	{
		arr[logicalSize++] = number;
	}
	else
	{
		actualSize *= 2;
		int* newArr{ new int[actualSize] };
		copyArr(newArr);
		delete[] arr;
		arr = newArr;
		add(number);
	}
}

// Копирование элементов при создании нового массива
void DynamicArray::copyArr(int* newArray) {
	for (int i{}; i < logicalSize; ++i)
	{
		newArray[i] = arr[i];
	}
}

// Удаление начального элемента массива
void  DynamicArray::removeHead()
{
	if (logicalSize > 0)
	{
		for (int i{}; i < logicalSize - 1; ++i)
		{
			arr[i] = arr[i + 1];
		}
		--logicalSize;
		if (logicalSize <= (actualSize / 3))
		{
			actualSize = logicalSize;
			int* newArr{ new int[actualSize] };
			copyArr(newArr);
			delete[] arr;
			arr = newArr;
		}
	}
}

DynamicArray::~DynamicArray()
{
	delete[] arr;
}