#include <cstdlib>
#include "Sorts.h"
using namespace std;

/*Запуск всего с выводом времени*/
void all(int *mass, int n)
{
	for (int choose = 1; choose < 10; choose++)
	{
		cout << "	Рандомизация..." << endl;
		input(mass, n);

		cout << "	Сортировка..." << endl;
		clock_t start, end;
		start = clock();

		switch (choose)
		{
		case 1:
			cout << "	1. Слияние";
			mergesort(mass, 0, n);
			break;
		case 2:
			cout << "	2. Подсчетом";
			countingsort(mass, n);
			break;
		case 3:
			cout << "	3. Двоичное дерево";
			sort_tree(mass, n);
			break;
		case 4:
			cout << "	4. Пузырек";
			bubblesort(mass, n);
			break;
		case 5:
			cout << "	5. Метод вставки";
			inputsort(mass, n);
			break;
		case 6:
			cout << "	6. Быстрая сортировка";
			quicksort(mass, 0, n - 1);
			break;
		case 7:
			cout << "	7. Сортировка Шелла";
			shellsort(mass, n);
			break;
		case 8:
			cout << "	8. Поразрядная сортировка (байты)";
			radixsort(mass, n);
			break;
		case 9:
			cout << "	9. Поразрядная сортировка (десятичная)";
			radix10sort(mass, n, 10);
			break;
		}
		end = clock();
		check_all_sort(mass, n);
		cout << "	Общее время выполнения: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << " сек." << endl << endl;
	}
}

/*Пользовательский выбор*/
void choose(int *mass, int n)
{
	/*ASCII-заголовок*/
	cout << endl << endl;
	cout << "	________               _________              __		" << endl;
	cout << "	\\_____  \\             /   _____/ ____________/  |_	" << endl;
	cout << "	  _(__  <    ______   \\_____  \\ /  _ \\_  __ \\   __)	" << endl;
	cout << "	 /       \\  /_____/   /        (  <_> )  | \\/|  |		" << endl;
	cout << "	/______  /           /_______  /\\____/|__|   |__|		" << endl;
	cout << "	       \\/                    \\/						" << endl << endl;
	cout << "	С о р т и р о в к и	 м а с с и в о в" << endl;
	cout << "	Текущее заданное количество элементов: " << n << " (random)" << endl << endl;
	cout << "	Выберите сортировку:" << endl;
	cout << "	1. Слияние" << endl;
	cout << "	2. Подсчетом" << endl;
	cout << "	3. Двоичное дерево" << endl;
	cout << "	4. Пузырек" << endl;
	cout << "	5. Метод вставки" << endl;
	cout << "	6. Быстрая сортировка" << endl;
	cout << "	7. Сортировка Шелла" << endl;
	cout << "	8. Поразрядная сортировка (байты)" << endl;
	cout << "	9. Поразрядная сортировка (десятичная)" << endl;
	cout << "	10. Запустить всё" << endl << endl;
	cout << "	Другие действия:" << endl;
	cout << "	0. Выход" << endl;
	int choose;
	cout << endl << "	Ввод: ";
	cin >> choose;
	cout << endl;

	/*отдельный свитч, чтобы избежать лишних затрат*/
	switch (choose)
	{
	case 0:
		exit(1);
		break;
	case 10:
		all(mass, n);
		cout << "	";
		exit(1);
	}

	cout << "	Рандомизация..." << endl;
	input(mass, n);

	cout << "	Сортировка..." << endl;
	clock_t start, end;
	start = clock();

	switch (choose)
	{
	case 1:
		mergesort(mass, 0, n);
		break;
	case 2:
		countingsort(mass, n);
		break;
	case 3:
		sort_tree(mass, n);
		break;
	case 4:
		bubblesort(mass, n);
		break;
	case 5:
		inputsort(mass, n);
		break;
	case 6:
		quicksort(mass, 0, n - 1);
		break;
	case 7:
		shellsort(mass, n);
		break;
	case 8:
		radixsort(mass, n);
		break;
	case 9:
		radix10sort(mass, n, 10);
		break;
	}

	end = clock();
	check_all_sort(mass, n);
	cout << "	Общее время выполнения: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << " сек." << endl;
	output_file(n, mass);
}

/*Вернуться в меню выбора*/
void ret_or_not(int *mass, int n)
{
	cout << endl << "	Вернуться в окно выбора? (y/n): ";
	char whattodo;
	cin >> whattodo;
	cout << endl;
	if (whattodo == 'y')
	{
		/*Рекурсивно повторяем main*/
		input(mass, n);
		choose(mass, n);
		ret_or_not(mass, n);
	}
	else
	{
		cout << "	Программа завершена" << endl;
		cout << "	";
		exit(1);
	}
}

/*Задать количество элементов*/
int elements_amount(int n)
{
	cout << endl << endl << "	Текущее заданное количество элементов: " << n << " (random)" << endl;
	cout << "	Требуется ли его изменить?" << endl << "	Введите требуемое число (>= 1), либо <0> - оставить по умолчанию" << endl;
	/*Сортирует любое число элементов, начиная с единицы (все сортировки проходят без проблем)*/
	cout << "	Ввод: ";
	int choose_me;
	cin >> choose_me;
	if (choose_me)
	{
		n = choose_me;
	}
	return n;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = N;
	n = elements_amount(n);
	int* mass = new int[n];
	choose(mass, n);
	ret_or_not(mass, n);
	delete[] mass;
	return 0;
}