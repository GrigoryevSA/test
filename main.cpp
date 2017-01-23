﻿#define _CRT_SECURE_NO_WARNINGS
#include "class_logger.h"
#include "class_print_console.h"
#include "class_print_document.h"
#include <iostream>

using namespace std;

int main()
{
	Logger* ptr[2];

	PrintConsole pc;
	PrintDocument pd;
	
	ptr[0] = &pc;
	ptr[1] = &pd;

	ptr[0]->fun_print_text();

	pd.set_name();
	pd.get_name();

	ptr[1]->fun_print_text();

}