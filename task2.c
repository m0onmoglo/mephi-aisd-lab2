#include <stdio.h>
#include <stdlib.h>

void reverse_part(double array[], int size);
void shift_right(double array[], int size, int shift);
void print_array(double array[], int size);

int main(void)
{
    int size;

    printf("Эта программа выполняет циклический сдвиг массива вправо.\n");
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

    int shift;
    printf("Введите целую величину сдвига вправо: ");
    if(scanf("%d", &shift) != 1){
        printf("Не удалось прочитать величину сдвига.\n");
        free(array);
        return 1;
    }

    shift_right(array, size, shift);

    printf("Результат: ");
    print_array(array, size);

    free(array);
    return 0;
}

void reverse_part(double array[], int size)
{
    int left = 0;
    int right = size - 1;

    while(left < right){
        double temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }
}

void shift_right(double array[], int size, int shift)
{
    shift = shift % size;
    if(shift < 0){
        shift += size;
    }

    if(shift == 0){
        return;
    }

    reverse_part(array, size);
    reverse_part(array, shift);
    reverse_part(array + shift, size - shift);
}

void print_array(double array[], int size)
{
    for(int i = 0; i < size; i++){
        printf("%f ", array[i]);
    }
    printf("\n");
}