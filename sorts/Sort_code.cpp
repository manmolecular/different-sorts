#include "Sorts.h"
using namespace std;

/*Поразрядная через десятичную*/
void radix10sort(int *a, int n, int length)
{
	int *temp = new int[n];
	int range = 1;
	int current_elem;
	for (int i = 0; i < length; i++)
	{
		int digits[10] = { 0 };
		for (int j = 0; j < n; j++)
		{
			current_elem = a[j] / range % 10;
			digits[current_elem]++;
		}
		for (int j = 1; j < 10; j++)
		{
			digits[j] += digits[j - 1];
		}
		for (int j = n - 1; j > -1; j--)
		{
			current_elem = --digits[a[j] / range % 10];
			temp[current_elem] = a[j];
		}
		for (int j = 0; j < n; j++)
		{
			a[j] = temp[j];
		}
		range = range * 10;
	}
	delete[] temp;
}

/*Получить байт*/
int get_byte(int n, int p)                          //получение байта p
{                                                   //8*p = 1 Б
	return (n >> (8 * p) & 255);                    //забираем байт и откидываем лишнее
}

/*Поразрядная байтами*/
void radixsort(int *a, int mass_size)
{
	int *temp = new int[mass_size];
	int k = 256;                                    //максимальное число байтов
	int n = mass_size;                              //количество элементов в массиве
	int current_elem;
	for (int i = 0; i < k; i++)                      //цикл по всем байтам
	{
		int *c = new int[256];                      //всего возможно 256 значений
		for (int j = 0; j < 256; j++)
		{
			c[j] = 0;
		}
		for (int j = 0; j < n; j++)                  //counting sort - кол-во элементов на каждый байт
		{
			current_elem = get_byte(a[j], i);
			c[current_elem]++;
		}
		for (int j = 1; j < 256; j++)                //теперь c[j] ук. на элем первый, после i (k) блока
		{
			c[j] += c[j - 1];
		}
		for (int j = n - 1; j >-1; j--)                //сдвиг массива
		{
			current_elem = get_byte(a[j], i);
			temp[--c[current_elem]] = a[j];
		}
		for (int j = 0; j < n; j++)                  //возврат
		{
			a[j] = temp[j];
		}
		delete[] c;
	}
	delete[] temp;
}

/*Сортировка Шелла*/
void shellsort(int *mass, int m)
{
	int t;
	for (int k = m / 2; k > 0; k = k / 2)
	{
		for (int i = k; i < m; i = i + 1)
		{
			t = mass[i];
			int j;
			for (j = i; j >= k; j -= k)
			{
				if (t < mass[j - k])
				{
					mass[j] = mass[j - k];
				}
				else
				{
					break;
				}
			}
			mass[j] = t;
		}
	}
}

/*Быстрая сортировка*/
void quicksort(int *mass, int first, int last)
{
	int temp;
	int left = first, right = last;				// для использования подмассивов
	int average = mass[(left + right) / 2];		// средний опорный элемент
	while (left <= right)
	{
		while (mass[left] < average)
		{
			left++;
		}
		while (mass[right] > average)
		{
			right--;
		}
		if (left <= right)						// если до сих пор меньше, то поменяем местами
		{
			temp = mass[left];
			mass[left] = mass[right];
			mass[right] = temp;
			left++;
			right--;
		}
	}
	if (first < right)
	{
		quicksort(mass, first, right);
	}
	if (last > left)
	{
		quicksort(mass, left, last);
	}
}

/*Сортировка методом вставок (лекция 3)*/
void inputsort(int *mass, int m)
{
	int temp;
	for (int i = 1; i < m; i++)
	{
		for (int j = i; j > 0 && mass[j - 1] > mass[j]; j--)
		{
			temp = mass[j - 1];
			mass[j - 1] = mass[j];
			mass[j] = temp;
		}
	}
}

/*Обычный пузырек с сохранением позиции*/
void bubblesort(int *mass, int m)
{
	for (int i = 0; i < m - 1; i++)
	{
		bool swapped = 0;
		for (int j = 0; j < m - i - 1; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				int temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

/*Запись сортированного массива в файл*/
void output_file(int m, int *mass)
{
	cout << endl << "	Записать вывод в файл? (y/n): ";
	char whattodo;
	cin >> whattodo;
	if (whattodo == 'y')
	{
		cout << endl << "	Введите имя файла для открытия: ";
		string filename;
		cin >> filename;
		ofstream f;
		f.open(filename);
		int temp = 0;
		f << "Полученный массив: " << endl;
		for (int i = 0; i < m; i++)
		{
			f << mass[i] << " ";
			temp++;
			if (temp == 15)						//по сколько элементов в строку выводить?
			{
				f << endl;
				temp = 0;
			}
		}
		f << endl;
		cout << "	Файл успешно записан" << endl;
	}
}

/*Вывод дерева*/
void treeprint(point_treenode tree, int *temp)
{
	static int i = 0;
	if (tree != 0)									// пока узел не пуст
	{												// рекурсия
		treeprint(tree->left, temp);				// уходим в левое поддерево
		temp[i++] = tree->data;						// записываем корни во временный массив
		treeprint(tree->right, temp);				// выводим правое поддерево
	}
}

/*Создание узла*/
point_treenode create_node(int x, point_treenode tree)
{
	if (tree == 0)					// создаем корень, если дерева нет
	{
		tree = new treenode;		// выделяем память
		tree->data = x;				// получаем число
		tree->left = 0;				// инициализируем ветки
		tree->right = 0;
	}
	else							// если дерево есть
	{
		if (x < tree->data)			// добавляем эл-ты рекурсивно
		{
			tree->left = create_node(x, tree->left);
		}
		else
		{
			tree->right = create_node(x, tree->right);
		}
	}
	return tree;
}

/*Рекурсивная очистка памяти*/
void delmem(point_treenode tree)
{
	if (tree != 0)
	{
		delmem(tree->left);
		delmem(tree->right);
		delete tree;
	}
}

/*Сортировка двоичным деревом*/
void sort_tree(int *mass, int m)
{
	point_treenode root = 0;
	for (int i = 0; i < m; i++)
	{
		root = create_node(mass[i], root);
	}
	//static int temp[n];					// создаем временный массив для рез-тов
	int* temp = new int[m];
	treeprint(root, temp);				// заполняем temp результатами
	for (int i = 0, j = 0; i < m; i++)
	{
		mass[j++] = temp[i];			// выгружаем временный в основной
	}
	delmem(root);
	delete[] temp;
}

/*Сортировка подсчётом*/
void countingsort(int *mass, int m)
{
	int* temp = new int[m];
	for (int i = 0; i < m; i++)
	{
		temp[i] = 0;							//создаем нулевой массив размера n
	}
	for (int i = 0; i < m; i++)
	{
		temp[mass[i]] = temp[mass[i]] + 1;		//подсчитываем количество элементов в массиве mass
	}
	int a = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < temp[j]; i++)
		{
			mass[a] = j;						//последовательно "разгружаем" временный массив в основной
			a += 1;
		}
	}
	delete[] temp;
}

/*Сортировка слиянием - объединение отрезков*/
void merge(int *mass, int first, int mid, int last)
{
	int check1 = 0;						//сдвиг для левой половины
	int check2 = 0;						//сдвиг для правой половины
	int* temp = new int[last - first + 1];	//

											/*заполняем временный массив меньшими элементами*/
	while (first + check1 < mid && mid + check2 < last)
	{
		if (mass[first + check1] < mass[mid + check2])				//если тек. эл. меньше - забираем текущий
		{
			temp[check1 + check2] = mass[first + check1];
			check1 += 1;
		}
		else														//если тек. эл. больше - забираем из второй половины, меньший
		{
			temp[check1 + check2] = mass[mid + check2];
			check2 += 1;
		}
	}
	/*если вдруг одна из половин в цикле выше закончилась раньше другой*/
	while (first + check1 < mid)
	{
		temp[check1 + check2] = mass[first + check1];
		check1 += 1;
	}
	while (mid + check2 < last)
	{
		temp[check1 + check2] = mass[mid + check2];
		check2 += 1;
	}
	/*собираем всё обратно*/
	for (int i = 0; i < check1 + check2; i++)
	{
		mass[first + i] = temp[i];
	}
	delete[] temp;
}

/*Сортировка слиянием*/
void mergesort(int *mass, int first, int last)
{
	if (first + 1 < last)
	{
		int mid = (first + last) / 2;			// определяем середину
		mergesort(mass, first, mid);			// рекурсивно вызываем для первой половины
		mergesort(mass, mid, last);				// рекурсивно вызываем для второй половины
		merge(mass, first, mid, last);			// делаем слияние
	}
}

/*Заполнение рандомными значениями*/
void input(int *mass, int m)
{
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		mass[i] = rand() % m;
	}
}

/*Вывод*/
void output(int *mass, int m)
{
	int temp = 0;
	cout << "	Полученный массив: " << endl;
	for (int i = 0; i < m; i++)
	{
		cout << mass[i] << " ";
		temp++;
		if (temp == 15)						//по сколько элементов в строку выводить?
		{
			cout << endl;
			temp = 0;
		}
	}
	cout << endl;
}

/*Проверочный вывод*/
void check_output(int *mass, int m)
{
	int temp = 0;
	cout << "	Полученный массив (проверка - последние 60 элем): " << endl;
	for (int i = m - 60; i < m; i++)
	{
		cout << mass[i] << " ";
		temp++;
		if (temp == 15)						//по сколько элементов в строку выводить?
		{
			cout << endl;
			temp = 0;
		}
	}
}

/*Авто - проверка*/
void check_all_sort(int *mass, int m)
{
	int i;
	for (i = 1; i < m; i++)
	{
		if (mass[i - 1] > mass[i])
		{
			cout << "	Массив не отсортирован" << endl;
			return;
		}
	}
	cout << endl << "	Массив отсортирован - количество обменов: " << i << endl;
}