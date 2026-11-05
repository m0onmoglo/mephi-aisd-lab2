//задача 1-4-13, пирамидальная сортировка

#include <stdio.h>
#include <stdlib.h>

void sift_down(double array[], int size, int root);
void heap_sort(double array[], int size);
void print_array(double array[], int size);

int main(void)
{
    int size;

    printf("Эта программа сортирует массив по возрастанию пирамидальным методом.\n");
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

    heap_sort(array, size);

    printf("Результат: ");
    print_array(array, size);

    free(array);
    return 0;
}

void sift_down(double array[], int size, int root)
{
    int child = 2 * root + 1;

    while(child < size){
        if(child + 1 < size && array[child + 1] > array[child]){
            child++;
        }

        if(array[root] >= array[child]){
            return;
        }

        double temp = array[root];
        array[root] = array[child];
        array[child] = temp;

        root = child;
        child = 2 * root + 1;
    }
}

void heap_sort(double array[], int size)
{
    // пирамида: каждый родитель не меньше своих потомков
    for(int root = size / 2 - 1; root >= 0; root--){
        sift_down(array, size, root);
    }

    for(int end = size - 1; end > 0; end--){
        double temp = array[0];
        array[0] = array[end];
        array[end] = temp;

        sift_down(array, end, 0);
    }
}

void print_array(double array[], int size)
{
    for(int i = 0; i < size; i++){
        printf("%f ", array[i]);
    }
    printf("\n");
}