#include "head.h"
#include <iostream>
#include <windows.h>
#include <locale.h>
#include "../Tree.h"
#include <limits>
#include <stdlib.h>

void clearRow(int row)
{
	DWORD dw;
	COORD here;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	here.X = 2;
	here.Y = row;
	LPCSTR str = "       ";
	WriteConsoleOutputCharacter(hStdOut, str, 8, here, &dw);
}

const char* space = "\t\t";
HWND console = nullptr;
POINT PosConsole = { 100,100 };
POINT sizeConsole = { 1200,600 };

void FontsSettings(int width, int height) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = width;
	cfi.dwFontSize.Y = height;
	cfi.FontFamily = FF_DONTCARE; 
	cfi.FontWeight = 600;
	//std::wcscpy(cfi.FaceName, L"Sony Sketch EF");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}


void loading()
{
	ProgressBar prog("", 0, 0);
	bool exit = true;
	while (exit)
	{	
		//cls();
		setCursorPosition(65, 16);
		setConsoleColour(0xA);
		std::wcout << "LOADING...";
		setCursorPosition(18, 18);
		prog.Show(0);
		Sleep(10);
		prog.ChangeValue(0);
		std::cout.flush();
		if (prog.value == 100.0F)
			exit = false;
	}

}


int menu(field* Array_field, int cout_Array_field)
{
	cls();

	//Exemple :)
	setConsoleColour(0xA);
	bool change = true;
	bool finish = false;
	int pos = 0;
	int max = 0;
	timer tmr1(100, true);

	while (!finish)
	{
		if (tmr1.timer_on())
		{
			if (change)
			{
				square(40, 5, 1, 0, 0);
				setCursorPosition(8, 0);
				size_t i = 0;
				
				std::cout << " GitHub @Yut-ka \r";
				std::cout << std::endl;
				int line_number = 8;

				for (field* ptr = Array_field; ptr <= &Array_field[cout_Array_field - 1]; ptr++) {
					setCursorPosition(2, line_number++);
					ptr->show(pos);
					++i;
				}
				max = i-1;
				change = false;
				
			}
	
			if (GetAsyncKeyState(VK_UP))
			{
				pos--;
				if (pos < 0)
					pos = max;
				change = true;

			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				++pos;
				if (pos > max)
					pos = 0;
				change = true; 
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				for (field* ptr = Array_field; ptr <= &Array_field[cout_Array_field - 1]; ptr++) {
					ptr->Press(pos);				
				}
				pos == max ? finish = true : finish = false;
				change = true;
				return pos;
			}
			setCursorPosition(2, 2);
			std::cout << "SAOD LAB5_1";
			setCursorPosition(2, 3);
			std::cout << "by Osipov Danil 4218";	
			setCursorPosition(2, 15);


			std::cout.flush();
		}
		Sleep(1);
	}
}


std::string text(textblock field)
{
	cls();

	//Exemple :)
	setConsoleColour(0xA);
	bool change = true;
	bool finish = false;
	int pos = 0;
	int max = 0;
	timer tmr1(100, true);
	

	while (!finish)
	{
		if (tmr1.timer_on())
		{
			
			std::string a;

			if (change)
			{
				square(40, 5, 1, 0, 0);
				setCursorPosition(8, 0);
				size_t i = 0;

				std::cout << " GitHub @Yut-ka \r" << std::endl;
				std::cout << std::endl;

				setCursorPosition(2, 2);
				std::cout << "SAOD LAB5_1" << std::endl;
				setCursorPosition(2, 3);
				std::cout << "by Osipov Danil 4218" << std::endl;

				setCursorPosition(2, 8);
				field.show(pos);
				setCursorPosition(2, 10);
				clearRow(10);
				getline(std::cin,a);
				std::cin.clear();
				std::cin.sync();
			}

			

			if (GetAsyncKeyState(VK_RETURN))
			{
				finish = true;
				return a;
			}

			
			
			std::cout.flush();
		}
		Sleep(0.5);
	}
}


std::string Get_el_console(std::string str) {
	textblock C = str;
	std::flush(std::cout);
	std::string A = text(C);
	return A;
}


int main()
{ 
	FontsSettings(0, 16);
	console = GetConsoleWindow();
	SetWindowPos(console, NULL, PosConsole.x, PosConsole.y, sizeConsole.x, sizeConsole.y, NULL);
	SetWindowLong(console, GWL_STYLE, WS_BORDER);
	ShowWindow(console, SW_SHOW);
	ExConsole();
	loading();		
				
	
	Tree_Item* a = new Tree_Item();

	while (1) {
		field A[5] = { "Create the current TREE", "line-by-line tree output based on Preorder_traversal", "line-by-line tree output based on Inorder_traversal", "line-by-line tree output based on Reverse_Inorder_traversal", "Exit" };
		bool back = 0;
		int choice = menu(A, 5);
		if (choice == 0) {	
			a = NULL;
			while (!back) {
				field D[2] = { "The TREE was successfully created", "Back"};
				int count = stoi(Get_el_console("Enter a size of TREE"));
				srand(time(NULL));
				AddNodes(a, count);
				if (menu(D, 2) == 1) back = 1;
			}
		}

		else if (choice == 1) {
			while (!back) {
				field GET[3] = {"Tree output based on Preorder_traversal:" , "Back", ""};
				std::string res = "\n";
				Preorder_traversal(res, a);
				GET[2].name = res;
				if (menu(GET, 3) == 1) {back = 1;}
			}
		}

		else if (choice == 2) {
			while (!back) {
				field GET[3] = { "Tree output based on Inorder_traversal:" , "Back", "" };
				std::string res = "\n";
				Inorder_traversal(res, a);
				GET[2].name = res;
				if (menu(GET, 3) == 1) { back = 1; }
			}
		}

		else if (choice == 3) {
			while (!back) {
				field GET[3] = { "Tree output based on Reverse_Inorder_traversal:" , "Back", "" };
				std::string res = "\n";
				Reverse_Inorder_traversal(res, a);
				GET[2].name = res;
				if (menu(GET, 3) == 1) { back = 1; }
			}
		}

		else if (choice == 4) {
			exit(0);
		}
	}
		
	
	return 0;
}

