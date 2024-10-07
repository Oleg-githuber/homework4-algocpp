#include "functions.h"

// ����� � ������� ������������� �������
void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "������������ ������: ";
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

// ���� ������ �����
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
			std::cout << "\n�� ����� ������������ ��������!\n";
		}
	}
}

// �������� ������������� ������� � ���������� ��������� ����������, ��������� �������������
DynamicArray createArray(int actual_size, int logical_size)
{
	DynamicArray dArray(actual_size, logical_size);
	std::string message1{ "������� arr[" };
	std::string message2{ "]: " };
	for (int i{}; i < logical_size; ++i)
	{
		std::string message = message1 + std::to_string(i) + message2;
		dArray.setElement(i, enterNumber(message));
	}
	return dArray;
}

// ���������� ��������� � ����� �������
void append_to_dynamic_array(DynamicArray& dArray)
{
	while (true)
	{
		int number{ enterNumber("\n������� ������� ��� ���������� (��� 0 ��� ������): ") };
		if (number != 0)
		{
			dArray.add(number);
		}
		else
		{
			std::cout << "�������!";
			print_dynamic_array(dArray.getArr(), dArray.getLogicalSize(), dArray.getActualSize());
			break;
		}
	}
}

// �������� ��������� ��������� �������
void remove_dynamic_array_head(DynamicArray& dArray)
{
	while (dArray.getLogicalSize() > 0)
	{
		std::cout << "\n������� ������ �������? (��/���):  ";
		std::string answer{};
		std::cin >> answer;
		if (answer == YES)
		{
			dArray.removeHead();
		}
		else if (answer == NO)
		{
			std::cout << "�������! ";
			print_dynamic_array(dArray.getArr(), dArray.getLogicalSize(), dArray.getActualSize());
			return;
		}
		else
		{
			std::cout << "\n�� ����� ������������ �����\n";
		}
	}
	std::cout << "\n���������� ������� ������ �������, ��� ��� ������ ������. �� ��������!";
}