#include <iostream>			// ввод-вывод
#include <string>			// строки
#include <fstream>			// файловый ввод-вывод
#include <time.h>			// время / рандом
#define N 1000000			// дефолтное количество элементов

/*Функция получения байта (числа)*/
/*аргументы: (текущий элемент массива, требуемый байт)*/
int get_byte(int n, int p);

/*Поразрядная сортировка (для десятичных чисел)*/
/*аргументы: (массив, длина массива, длина числа)*/
void radix10sort(int *a, int n, int length);

/*Поразрядная сортировка (по байтам)*/
/*аргументы: (массив, длина массива)*/
void radixsort(int *a, int mass_size);

/*Авто - проверка*/
/*аргументы: (массив, длина массива)*/
void check_all_sort(int *mass, int m);

/*Сортировка Шелла*/
/*аргументы: (массив, длина массива)*/
void shellsort(int *mass, int m);

/*Быстрая сортировка*/
/*аргументы: (массив, индекс первого элемента, индекс последнего элемента)*/
void quicksort(int *mass, int first, int last);

/*Сортировка методом вставок*/
/*аргументы: (массив, длина массива)*/
void inputsort(int *mass, int m);

/*Сортировка пузырьком*/
/*аргументы: (массив, длина массива)*/
void bubblesort(int *mass, int m);

/*Запись сортированного массива в файл*/
/*аргументы: (длина сортируемого массива, массив)*/
void output_file(int m, int *mass);

/*Объявление списка*/
struct treenode
{
	int data;					// данные
	treenode *left;				// левая часть от корня
	treenode *right;			// правая часть от корня
};

/*Переопределение указателя на дерево*/
typedef treenode *point_treenode;

/*Вывод дерева*/
/*аргументы: (указатель на объект treenode, временный массив)*/
void treeprint(point_treenode tree, int *temp);

/*Создание узла*/
/*аргументы: (число в корне, указатель на объект treenode)*/
point_treenode create_node(int x, point_treenode tree);

/*Рекурсивная очистка памяти*/
/*аргументы: (указатель на объект treenode*/
void delmem(point_treenode tree);

/*Сортировка двоичным деревом*/
/*аргументы: (массив)*/
void sort_tree(int *mass, int m);

/*Сортировка подсчётом*/
/*аргументы: (массив)*/
void countingsort(int *mass, int m);

/*Сортировка слиянием - объединение отрезков*/
/*аргументы: (массив, первый эл, средний эл, последний эл)*/
void merge(int *mass, int first, int mid, int last);

/*Сортировка слиянием*/
/*аргументы: (массив, первый эл, последний эл)*/
void mergesort(int *mass, int first, int last);

/*Заполнение рандомными значениями*/
/*аргументы: (массив, длина массива) */
void input(int *mass, int m);

/*Вывод*/
/*аргументы: (массив, длина массива) */
void output(int *mass, int m);

/*Проверочный вывод*/
/*аргументы: (массив, длина массива) */
void check_output(int *mass, int m);