// advent calendar day 1

#define TYPE 3
#define SIZE 1000
#define SUM 2020
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    int i, j, k;

    //check input
    if (argc != 2) {
        printf("Incorrect number of input arguments. Exiting...\n");
        exit(1);
    }
    FILE *fpt = fopen(argv[1], "r");
    if (fpt == NULL) {
        printf("File %s not found. Exiting...\n", argv[1]);
        exit(1);
    }

    //allocate space for array
    int *num_array = calloc(sizeof(int), SIZE);

    //read file
    int lines = 0;
    while (fscanf(fpt, "%d", &num_array[lines]) == 1) {
        lines++;
    }

    //2 sum algorithm
    if (TYPE == 2) {
        printf("2 sum\n");
        for (i = 0; i < lines; i++) {
            for (j = i+1; j < lines; j++) {
                if (num_array[i] + num_array[j] == SUM) {
                    printf("%d + %d = %d\n", num_array[i], num_array[j], SUM);
                    printf("product: %d\n", num_array[i]*num_array[j]);
                    exit(0);
                }
            }
        }
    }

    //3 sum algorithm
    if (TYPE == 3) {
        printf("3 sum\n");
        for (i = 0; i < lines; i++) {
            for (j = i+1; j < lines; j++) {
                for (k = j+1; k < lines; k++) {
                    if (num_array[i] + num_array[j] + num_array[k] == SUM) {
                        printf("%d + %d + %d = %d\n", num_array[i], num_array[j], num_array[k], SUM);
                        printf("product: %d\n", num_array[i]*num_array[j]*num_array[k]);
                        exit(0);
                    }
                }
            }
        }
    }

    printf("No sum found. Exiting...\n");
    return 0;

}