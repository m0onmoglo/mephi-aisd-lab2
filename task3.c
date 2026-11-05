#include <stdio.h>
#include <stdlib.h>

void reverse_part(int array[], int left, int right);
int move_less_than(int array[], int left, int right, int border);
void separate_array(int array[], int size);
void print_array(int array[], int size);

int main(void)
{
    int size;

    printf("Эта программа располагает отрицательные числа, нули и положительные числа по группам.\n");
    printf("Введите размер массива от 1 до 1000: ");

    if(scanf("%d", &size) != 1 || size < 1 || size > 1000){
        printf("Некорректный размер массива.\n");
        return 1;
    }

    int *array = malloc(size * sizeof(int));
    if(array == NULL){
        printf("Не удалось выделить память.\n");
        return 1;
    }

    printf("Вводите целые числа.\n");

    for(int i = 0; i < size; i++){
        printf("Введите элемент с индексом %d (с номером %d): ", i, i + 1);
        if(scanf("%d", &array[i]) != 1){
            printf("Не удалось прочитать число.\n");
            free(array);
            return 1;
        }
    }

    separate_array(array, size);

    printf("Результат: ");
    print_array(array, size);

    free(array);
    return 0;
}

void reverse_part(int array[], int left, int right)
{
    while(left < right){
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }
}

// обрабатываем индексы от left до right - 1 и возвращаем начало части, в которой элементы не меньше border.
int move_less_than(int array[], int left, int right, int border)
{
    if(left == right){
        return left;
    }

    if(right - left == 1){
        if(array[left] < border){
            return right;
        }
        return left;
    }

    int middle = left + (right - left) / 2;
    int left_end = move_less_than(array, left, middle, border);
    int right_end = move_less_than(array, middle, right, border);

    // меняем местами два средних блока, сохраняя порядок внутри них.
    if(left_end < middle && middle < right_end){
        reverse_part(array, left_end, middle - 1);
        reverse_part(array, middle, right_end - 1);
        reverse_part(array, left_end, right_end - 1);
    }

    return left_end + (right_end - middle);
}

void separate_array(int array[], int size)
{
    int negative_end = move_less_than(array, 0, size, 0);

    // в оставшейся неотрицательной части меньше 1 только нули.
    move_less_than(array, negative_end, size, 1);
}

void print_array(int array[], int size)
{
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}