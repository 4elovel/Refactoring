#include <iostream>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#elif __linux
#include <termios.h>
#endif
using namespace std;
void menu() {
	cout << "Натисніть 1 для заміни цифр пробілами\n";
	cout << "Натисніть 2 для заміни розділових знаків пробілами\n";
	cout << "Натисніть 3 для заміни англійських букв пробілами\n";
	cout << "Натисніть 4 для заміни українських букв пробілами\n";
}
void menu_end() {
	cout << "Для закінчення введення даних натисніть клавішу esc\n";
}
int main()
// спільний розділ для обох систем
{
	string Укр = "йцукенгшщзхждлорпавфячсмитьбюЙЦУКЕНГШЩЗХЖДЛОРПАВФЯЧСМИТЬБЮґҐІіЄєЇї";
	string Eng = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
	string Num = "0123456789";
	string Symb = "`~!@#$%^&*()_+}{|\":<>?/.,\\';][=-№";
	int    choice = 0;
	char   qt;   // при потребі цю змінну можна ініціалізувати пробілом
	string text;
	bool menu_run = true;

#ifdef __linux

	struct termios Old, New;
	while (menu_run)
	{
		menu();
		cin >> choice;
		switch (choice) {
		case 1:
			system("clear");
			menu_end();
			tcgetattr(0, &Old);
			New = Old;
			New.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &New);
			qt = getchar();
			while ((qt = getchar()) != 27) {
				for (int i = 0; i < Num.length(); i++) {
					if (qt == Num[i]) {
						qt = ' ';
					}
				}
				text += qt;
				cout << qt;
			}
			tcsetattr(0, TCSANOW, &Old);
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			break;
		case 2:
			system("clear");
			menu_end();
			tcgetattr(0, &Old);
			New = Old;
			New.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &New);
			qt = getchar();
			while ((qt = getchar()) != 27) {
				for (int i = 0; i < Symb.length(); i++) {
					if (qt == Symb[i]) {
						qt = ' ';
					}
				}
				text += qt;
				cout << qt;
			}
			tcsetattr(0, TCSANOW, &Old);
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			break;
		case 3:
			system("clear");
			menu_end();
			tcgetattr(0, &Old);
			New = Old;
			New.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &New);
			qt = getchar();
			while ((qt = getchar()) != 27) {
				for (int i = 0; i < Eng.length(); i++) {
					if (qt == Eng[i]) {
						qt = ' ';
					}
				}
				text += qt;
				cout << qt;
			}
			tcsetattr(0, TCSANOW, &Old);
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			break;
		case 4:
			system("clear");
			menu_end();
			tcgetattr(0, &Old);
			New = Old;
			New.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &New);
			qt = getchar();
			while ((qt = getchar()) != 27) {
				for (int i = 0; i < Укр.length(); i++) {
					if (qt == Укр[i]) {
						qt = ' ';
					}
				}
				text += qt;
				cout << qt;
			}
			tcsetattr(0, TCSANOW, &Old);
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			break;
		default:
			menu_run = false;
			break;
		}
	}

#elif _WIN32

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	bool run = true;
	string test;
	while (menu_run)
	{
		menu();
		cin >> choice;
		switch (choice) {
		case 1:
			system("CLS");
			menu_end();
			while (run) {
				if (_kbhit()) {
					qt = _getch();
					for (int i = 0; i < Num.length(); i++) {
						if (qt == Num[i]) {
							qt = ' ';
						}
						else if (qt == 13) {
							qt = '\n';
						}
						else if (qt == 27) {
							run = false;
							qt = ' ';
							break;
						}
					}
					text += qt;
					cout << qt;
				}
			}
			cout << endl << "Ви ввели текст:\n";
			cout << test << endl;
			run = true;
			break;
		case 2:
			system("CLS");
			menu_end();
			while (run) {
				if (_kbhit()) {
					qt = _getch();
					for (int i = 0; i < Symb.length(); i++) {
						if (qt == Symb[i]) {
							qt = ' ';
						}
						else if (qt == 13) {
							qt = '\n';
						}
						else if (qt == 27) {
							run = false;
							qt = ' ';
							break;
						}
					}
					text += qt;
					cout << qt;
				}
			}
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			run = true;
			break;
		case 3:
			system("CLS");
			menu_end();
			while (run) {
				if (_kbhit()) {
					qt = _getch();
					for (int i = 0; i < Eng.length(); i++) {
						if (qt == Eng[i]) {
							qt = ' ';
						}
						else if (qt == 13) {
							qt = '\n';
						}
						else if (qt == 27) {
							run = false;
							qt = ' ';
							break;
						}
					}
					text += qt;
					cout << qt;
				}
			}
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			run = true;
			break;
		case 4:
			system("CLS");
			menu_end();
			while (run) {
				if (_kbhit()) {
					qt = _getch();
					for (int i = 0; i < Укр.length(); i++) {
						if (qt == Укр[i]) {
							qt = ' ';
						}
						else if (qt == 13) {
							qt = '\n';
						}
						else if (qt == 27) {
							run = false;
							qt = ' ';
							break;
						}
					}
					text += qt;
					cout << qt;
				}
			}
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			run = true;
			break;
		default:
			menu_run = false;
			break;
		}
	}
#endif
}