// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"

int main()
{
	// Русская локализация
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Ввод данных для создания массива
	int actualSize{ enterNumber("Введите фактический размер массива: ") };
	int logicalSize{};
	while (true)
	{
		logicalSize = enterNumber("Введите логический размер массива: ");
		if (logicalSize > actualSize)
		{
			std::cout << "\nОшибка! Логический размер массива не может превышать фактический!\n";
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		break;
	}
	// Создание массива
	DynamicArray dynamicArray{ createArray(actualSize, logicalSize) };
	// Вывод массива на экран
	print_dynamic_array(dynamicArray.getArr(), logicalSize, actualSize);
	// Добавление новых элементов в конец
	append_to_dynamic_array(dynamicArray);
	// Удаление начальных элементов
	remove_dynamic_array_head(dynamicArray);

	return EXIT_SUCCESS;
}

