#include "functions.h"

// Вывод в консоль динамического массива
void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "Динамический массив: ";
	for (int i{}; i < actual_size; ++i)
	{
		if (i < logical_size)
		{
			std::cout << arr[i];
		}
		else
		{
			std::cout << '_';
		}
		std::cout << ' ';
	}
}

// Ввод целого числа
int enterNumber(std::string message)
{
	int number{};
	while (true)
	{
		std::cout << message;
		if (std::cin >> number)
		{
			return number;
		}
		else
		{
			std::cout << std::flush;
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\nВы ввели некорректное значение!\n";
		}
	}
}

// Создание динамического массива с изначально заданными элементами, введёнными пользователем
DynamicArray createArray(int actual_size, int logical_size)
{
	DynamicArray dArray(actual_size, logical_size);
	std::string message1{ "Введите arr[" };
	std::string message2{ "]: " };
	for (int i{}; i < logical_size; ++i)
	{
		std::string message = message1 + std::to_string(i) + message2;
		dArray.setElement(i, enterNumber(message));
	}
	return dArray;
}

// Добавление элементов в конец массива
void append_to_dynamic_array(DynamicArray& dArray)
{
	while (true)
	{
		int number{ enterNumber("\nВведите элемент для добавления (или 0 для выхода): ") };
		if (number != 0)
		{
			dArray.add(number);
		}
		else
		{
			std::cout << "Спасибо!";
			print_dynamic_array(dArray.getArr(), dArray.getLogicalSize(), dArray.getActualSize());
			break;
		}
	}
}

// Удаление начальных элементов массива
void remove_dynamic_array_head(DynamicArray& dArray)
{
	while (dArray.getLogicalSize() > 0)
	{
		std::cout << "\nУдалить первый элемент? (да/нет):  ";
		std::string answer{};
		std::cin >> answer;
		if (answer == YES)
		{
			dArray.removeHead();
		}
		else if (answer == NO)
		{
			std::cout << "Спасибо! ";
			print_dynamic_array(dArray.getArr(), dArray.getLogicalSize(), dArray.getActualSize());
			return;
		}
		else
		{
			std::cout << "\nВы ввели некорректный ответ\n";
		}
	}
	std::cout << "\nНевозможно удалить первый элемент, так как массив пустой. До свидания!";
}