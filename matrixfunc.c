#include <stdio.h>
#include "matrixfunc.h"

// очистка буфера
void clear_buf(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
}

// пунк b: заполнение матрицы
void fill_matrix(int *matptr, int rows, int cols) {
	int i, j, res;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++){
            int *elem_ptr = matptr + i * cols + j;
            printf("Введите элемент [%d][%d]: ", i, j);
            res = scanf("%d", elem_ptr);

		    if (res == EOF) {
			    break;
		    }
		    if (res != 1) {
			    printf("ошибка: ведите целое число.\n");
			    clear_buf();
			    continue;
		    }
		    clear_buf();
        }
	}
}
// пункт c: вывод
void print_matrix( int *matptr, int rows, int cols) {
	int i, j;

	printf("\nИндекс | Значение | Адрес\n");
	for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            int *elem_ptr = matptr + i * cols + j;
            printf("[%2d][%2d] | %8d | %p\n" , i, j, *elem_ptr, (const void *)elem_ptr);
        }
	}
	printf("\n");
}
// функция № 2: определение минимального элемента матрицы
int min_mat( int *matptr, int rows, int cols, int *res) {
	if (rows <= 0 || cols <= 0) {
		return ERR;
	}
	int min = *matptr;
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++){
            int val = *(matptr + i * cols + j);
            if (val < min) {
                min = val;
            }
        }
    }
	*res = min;
	return OK;
}

// функция 18: определение количества элементов, значения которых находятся в заданном
//диапазоне значений k–m
int cnt_range( int *matptr, int rows, int cols, int k, int m, int *res) {
	if (rows <= 0 || cols <= 0 || k > m) {
		return ERR;
	}
	int count = 0;
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++){
            int val = *(matptr + i * cols + j);
            if (val >= k && val <= m) {
                count++;
            }
        }
    }

	*res = count;
	return OK;
}

// функция 28: суммы элементов строк, индексы которых находятся в заданном
//диапазоне k–m
int sum_range( int *matptr, int rows, int cols, int k, int m, int *res) {
	if (rows <= 0 || cols <= 0 || k < 0 || m >= rows || k > m) {
        return ERR;
    }
    int sum = 0;
    int i, j;
    for (i = k; i <= m; i++) {
        for (j = 0; j < cols; j++){
            sum = *(matptr + i * cols + j);

        }
    }
    *res = sum;
	return OK;
}