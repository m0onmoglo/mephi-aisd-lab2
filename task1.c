#include <stdio.h>
#include <stdlib.h>

void reverse_array(double array[], int size);
void print_array(double array[], int size);

int main(void)
{
    int size;

    printf("Эта программа переставляет элементы массива в обратном порядке.\n");
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
        printf("Введите элемент с индексом %d (с номером %d): ", i, i + 1);
        if(scanf("%lf", &array[i]) != 1){
            printf("Не удалось прочитать число.\n");
            free(array);
            return 1;
        }
    }

    reverse_array(array, size);

    printf("Результат: ");
    print_array(array, size);

    free(array);
    return 0;
}

void reverse_array(double array[], int size)
{
    int left = 0;
    int right = size - 1;
    double temp;

    while(left < right){
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }
}

void print_array(double array[], int size) //ввела эту функцию для печати массива с индексом i(принтф не видел i вне циклов, задала заново)
{
    for(int i = 0; i < size; i++){
        printf("%f ", array[i]); // в выводе для дабла так же как и для флоат спецификатор формата
    }
    printf("\n");
}

//clang -std=c11 -Wall -Wextra task1.c -o task1
//./task1
//ВРЕМЯ: O(N)