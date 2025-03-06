#ifndef LABA_2_TASK_H
#define LABA_2_TASK_H

void write_num_to_file(const char* filename, int * amount);
void read_file(const char* filename);
void how_many_num(const char* filename);
int finding_value(const char *filename, double value);
double *num_from_file_to_arr(const char *filename, int *amount);
void cyclic_shift(double arr[], int n, int k);
void write_arr_to_file(const char *filename, double arr[], int amount);
void shift_num_in_file(const char *filename, int k);

#endif //LABA_2_TASK_H
