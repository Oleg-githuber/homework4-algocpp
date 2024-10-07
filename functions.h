#pragma once

#include <iostream>
#include <string>
#include "DynamicArray.h"

// ��������� ��� ������� ������������
#define YES "��"
#define NO "���"

void print_dynamic_array(int* arr, int logical_size, int actual_size);	// ����� � ������� ������������� �������

int enterNumber(std::string message);	// ���� ������ �����

DynamicArray createArray(int actual_size, int logical_size);	// �������� ���������� �������

void append_to_dynamic_array(DynamicArray& dArray);	// ���������� �������� � ����� �������

void remove_dynamic_array_head(DynamicArray& dArray);	// �������� ���������� �������� �������