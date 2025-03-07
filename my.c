#include "my.h"

int p_1(const char *input) {
    if (input[0] == '-') {
        for (int i = 1; input[i] != '\n' && input[i] != '\0'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                return 0;
            }
        }
    } else {
        for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                return 0;
            }
        }
    }
    return 1;
}

int p_2(char* input, int* integer) {
    int temp;
    if (p_1(input) && sscanf_s(input, "%d", &temp) == 1) {
        *integer = temp;
        return 1;
    } else {
        return 0;
    }
}

int p() {
    char in[20];
    int Int = 0;
    while (1) {
        fgets(in, sizeof(in), stdin);
        if (p_2(in, &Int) == 1) {
            break;
        } else if (in[0] == '\n') {
            return INT_MIN;
        } else {
            printf("Invalid input. Please enter an integer: ");
        }
    }
    return Int;
}

int check_int(int a, int b) {
    int c;
    while (1) {
        c = p();
        if (c == INT_MIN) {
            return INT_MIN;
        }
        if (c >= a && c <= b) {
            break;
        } else {
            printf("Input out of range. Please enter a number between %d and %d: ", a, b);
        }
    }
    return c;
}


int p_1_float(const char *input)
{
    int dot_count = 0;
    int i = 0;
    if (input[0] == '-')
    {
        i = 1;
    }
    for (; input[i] != '\0' && input[i] != '\n'; i++)
    {
        if (input[i] == '.')
        {
            dot_count++;
            if (dot_count > 1)
            {
                return 0;
            }
        } else if (!isdigit(input[i]))
        {
            return 0;
        }
    }
    return 1;
}


int p_2_float(const char *input, double *decimal)
{
    double temp;
    if (p_1_float(input) && sscanf_s(input, "%lf", &temp) == 1)
    {
        *decimal = temp;
        return 1;
    } else
    {
        return 0;
    }
}


double p_float()
{
    char in[100];
    double decimal = 0.0;
    while (1) {
        fgets(in, sizeof(in), stdin);
        if (p_2_float(in, &decimal) == 1)
        {
            break;
        } else if (in[0] == '\n')
        {
            return -INFINITY;
        } else
        {
            printf("Invalid input. Please enter a decimal number: ");
        }
    }
    return decimal;
}


double check_float(double a, double b)
{
    double c;
    while (1)
    {
        c = p_float();
        if (c == -INFINITY)
        {
            return -INFINITY;
        }
        if (c >= a && c <= b)
        {
            break;
        } else
        {
            printf("Input out of range. Please enter a number between %.2f and %.2f: ", a, b);
        }
    }
    return c;
}