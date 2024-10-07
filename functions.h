#pragma once

#include <iostream>
#include <string>
#include "DynamicArray.h"

// Константы для ответов пользователя
#define YES "да"
#define NO "нет"

void print_dynamic_array(int* arr, int logical_size, int actual_size);	// Вывод в консоль динамического массива

int enterNumber(std::string message);	// Ввод целого числа

DynamicArray createArray(int actual_size, int logical_size);	// Создание начального массива

void append_to_dynamic_array(DynamicArray& dArray);	// Добавление элемента в конец массива

void remove_dynamic_array_head(DynamicArray& dArray);	// Удаление начального элемента массива