#include <stdio.h>
#include <stdlib.h>

void quick_sort(double array[], int left, int right);
void print_array(double array[], int size);

int main(void)
{
    int size;

    printf("Эта программа выполняет быструю сортировку массива по возрастанию.\n");
    printf("Введите размер массива от 1 до 1000: ");

    if(scanf("%d", &size) != 1 || size < 1 || size > 1000){
        printf("Некорректный размер массива.\n");
        return 1;
    }

    double *array = malloc(size * sizeof(double));
    if(array == NULL){
        printf("Не удалось выделить память.\n");
        return 1;
    }

    printf("Дробную часть отделяйте точкой.\n");

    for(int i = 0; i < size; i++){
        printf("Введите элемент номер %d: ", i + 1);
        if(scanf("%lf", &array[i]) != 1){
            printf("Не удалось прочитать число.\n");
            free(array);
            return 1;
        }
    }

    quick_sort(array, 0, size - 1);

    printf("Результат: ");
    print_array(array, size);

    free(array);
    return 0;
}

void quick_sort(double array[], int left, int right)
{
    if(left >= right){
        return;
    }

    int i = left;
    int j = right;
    double pivot = array[left + (right - left) / 2];

    while(i <= j){
        while(array[i] < pivot){
            i++;
        }
        while(array[j] > pivot){
            j--;
        }

        if(i <= j){
            double temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            i++;
            j--;
        }
    }

    if(left < j){
        quick_sort(array, left, j);
    }
    if(i < right){
        quick_sort(array, i, right);
    }
}

void print_array(double array[], int size)
{
    for(int i = 0; i < size; i++){
        printf("%f ", array[i]);
    }
    printf("\n");
}