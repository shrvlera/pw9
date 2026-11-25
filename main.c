#include <stdio.h>
#include "matrixfunc.h"

// очистка буфера
void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void show_menu() {
    printf("a Задать размер матрицы (строки, столбцы)\n");
    printf("b Заполнить матрицу\n");
    printf("c Представление матрицы (значения, адреса элементов) \n");
    printf("d Определение минимального элемента матрицы\n");
    printf("e Определение кол-ва элементов, значения которых в диапазоне значений k–m\n");
    printf("f Вычисление суммы элементов строк, индексы которых в диапазоне k–m\n");
    printf("g Выход\n");
    printf("Выберите пункт: ");
}

int main() {
    int mat[MAX_SIZE][MAX_SIZE] = {0};
    int rows = 0;
    int cols = 0;
    int is_filled = 0;
    int k, m, ans, res;
    char choice;

    while (1) {
        show_menu();

        res = scanf(" %c" ,  &choice);
        if (res == EOF) {
            printf("\nEOF - выход\n");
            break;
        }
        flush_input();

        switch (choice) {
            case 'a' : {
                printf("введите кол-во строк и столбцов (от 1 до %d):" , MAX_SIZE);
                res = scanf("%d %d", &rows, &cols);
                if (res == EOF) {
                    printf("\nEOF - выход\n");
                    return 0;
                }
                flush_input();

                is_filled = 0;
                if (res != 2  || rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE ) {
                    rows = 0;
                    cols = 0;
                    printf("размеры должены быть от 1 до %d.\n\n", MAX_SIZE);
                } else {
                    printf("размер матрицы установлен: %d x %d\n\n", rows, cols);
                }
                break;

            }

            case 'b' : 
                if (rows == 0 || cols == 0 ) {
                   printf("Сначала задайте размер матрицы (пункт a).\n\n");
                   break;
                }
                fill_matrix(&mat[0][0], rows, cols);
                is_filled = 1;
                printf("Марица заполнена.\n\n");
                break;
                
            case 'c' :
                if (rows == 0 || cols == 0 || is_filled == 0) {
                    printf("Матрица не задана или не заполнена (пункты a и b).\n\n");
                    break;
                }
                print_matrix(&mat[0][0], rows, cols);
                break;

            case 'd' :
                if (rows == 0 || cols == 0 || is_filled == 0) {
                    printf("Матрица не задана или не заполнена (пункты a и b).\n\n");
                    break;
                }
                if (min_mat(&mat[0][0], rows, cols, &ans) == OK) {
                    printf("Минимальный элемент матрицы: %d\n\n", ans);
                } else {
                    printf("ошибка при поиске минимума.\n\n");
                }
                break;

            case 'e':
                if (rows == 0 || cols == 0 || is_filled == 0) {
                    printf("Матрица не задана или не заполнена (пункты a и b).\n\n");
                    break;
                }
                printf("Введите диапазон значений k и m :");
                res = scanf("%d %d", &k, &m);
                if (res == EOF) {
                    return 0;
                }
                flush_input();

                if (res != 2) {
                    printf("Ошибка ввода значений.\n\n");
                    break;
                }

                if (cnt_range(&mat[0][0], rows, cols, k, m, &ans) == OK) {
                    printf("Количество элементов в диапазоне[%d..%d]: %d\n\n", k, m, ans);
                } else {
                    printf("ошибка -  должно k<=m.\n\n");
                }
                break;

            case 'f':
                if (rows == 0 || cols == 0 || is_filled == 0) {
                    printf("Матрица не задана или не заполнена (пункты a и b).\n\n");
                    break;
                }
                printf("введите диапазон идексов строк k и m : ");
                res = scanf("%d, %d" , &k, &m);
                if (res == EOF) {
                    return 0;
                }
                flush_input();
                   
                if (res != 2) {
                    printf("ошибка ввода индексов\n\n");
                    break;
                }

                if (sum_range(&mat[0][0], rows, cols, k, m, &ans) == OK) {
                    printf("Сумма элементов строк с %d по %d: %d\n\n", k, m, ans);

                } else {
                    printf("проверьте индексы строк: нужно 0 <= k <= m < %d.\n\n", rows);
                }
                break;
                
            case 'g':
                printf("Выход\n");
                return 0;
            
            default:
                printf("Неизвестный пункт меню.\n\n");
                break;

        }

    }
    return 0;
}