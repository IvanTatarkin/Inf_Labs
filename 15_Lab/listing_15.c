#include <stdio.h>

int main(void) {
    int size;
    FILE * file = stdin;
    fscanf(file, "%d", &size);
    int matrix[size][size];
    int i, j;
    for (int i = 0; i < size && !feof(file); i++) {
        for (int j = 0; j < size && !feof(file); j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
        putchar('\n');
    }
    fclose(file);

    int max_product = -2147483646;
    int min_product = 2147483646;
    int ma_i = 0;
    int mi_i = 0;
    for (int i = 0; i < size; i++) {
        int cur_prouct = 1;
        for (int j = 0; j < size; j++) {
            cur_prouct *= matrix[i][j];
        }
        if (cur_prouct >= max_product){
            max_product = cur_prouct;
            ma_i = i;
        }
        if (cur_prouct <= min_product){
            min_product = cur_prouct;
            mi_i = i;
        }
    }
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (i == ma_i){
                printf("%d ", matrix[mi_i][j]);
            }
            else if (i == mi_i){
                printf("%d ", matrix[ma_i][j]);
            }
            else{
                printf("%d ", matrix[i][j]);
            }
        }
        putchar('\n');
    }
    return 0;
}