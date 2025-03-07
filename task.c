#include "my.h"
#include "task.h"

void write_num_to_file(const char* filename, int* amount) {
    puts("Task 1");

    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("Press Enter on an empty line to finish:\n");
    *amount = 0;

    while (1) {
        double num = check_float(-1.79769e+308, 1.79769e+308);

        if (num == -INFINITY) {
            break;
        }

        fprintf(file, "%f ", num);
        (*amount)++;
    }

    fclose(file);
    puts("End task without errors");
}

void read_file(const char* filename) {
    puts("Read file");

    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    double num;
    while (fscanf(file, "%lf", &num) == 1) {
        printf("%lf ", num);
    }

    if (feof(file)) {
        printf("\nEnd of file reached.\n");
    } else if (ferror(file)) {
        perror("Error reading file");
    }

    fclose(file);
}

void how_many_num(const char* filename)
{
    puts("Task 2");
    puts("Input value");
    double value = check_float(-1.79769e+308, 1.79769e+308);
    int amount_value = finding_value(filename, value);
    printf("How many %lf in file %d\n", value, amount_value);
    puts("End task without errors");

}

int finding_value(const char *filename, double value)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error");
        return -1;
    }
    int count = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file))
    {
        double num;
        if (sscanf_s(buffer, "%lf", &num) == 1)
        {
            if (num == value) {
                count++;
            }
        }
    }
    fclose(file);
    return count;
}

double* num_from_file_to_arr(const char* filename, int* amount) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    double number;
    *amount = 0;

    while (fscanf(file, "%lf", &number) == 1) {
        (*amount)++;
    }

    if (*amount == 0) {
        fclose(file);
        return NULL;
    }

    rewind(file);

    double* arr = malloc(sizeof(double) * (*amount));
    if (arr == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *amount; i++) {
        if (fscanf(file, "%lf", &arr[i]) != 1) {
            perror("Error reading file");
            free(arr);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    return arr;
}

// Циклический сдвиг массива на k позиций вправо
void cyclic_shift(double arr[], int n, int k) {
    k = k % n;
    if (k == 0) return;

    double* temp = malloc(sizeof(double) * k);
    if (temp == NULL) {
        perror("Error allocating memory");
        return;
    }

    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    free(temp);
}

void write_arr_to_file(const char* filename, double arr[], int amount) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < amount; i++) {
        fprintf(file, "%lf ", arr[i]);
    }

    fclose(file);
}

void shift_num_in_file(const char* filename, int q) {
    int amount;
    puts("Shift value");
    int k = check_int(1 , q);
    double* arr = num_from_file_to_arr(filename, &amount);

    if (arr == NULL) {
        return;
    }

    cyclic_shift(arr, amount, k);
    write_arr_to_file(filename, arr, amount);

    free(arr);
}