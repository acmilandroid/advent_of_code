// advent calendar day 2

#define PART 2
#define SIZE 1000
#define SUM 2020
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
     int i, count;

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
    int *begin_index = calloc(sizeof(int), SIZE);
    int *end_index = calloc(sizeof(int), SIZE);
    char trash;
    char *letter = calloc(sizeof(char), SIZE);
    char **pw = calloc(sizeof(char *), SIZE);
    for (i = 0; i < SIZE; i++) {
        pw[i] = calloc(sizeof(char), SIZE);
    }

    //read file
    int lines = 0;
    int valid = 0;
    while (fscanf(fpt, "%d%c%d %c%c %s\n", &begin_index[lines], &trash, &end_index[lines], &letter[lines], &trash, pw[lines]) == 6) {
        printf("%d %c %d %c %c %s\n", begin_index[lines], trash, end_index[lines], letter[lines], trash, pw[lines]);
        
        // check pw conditions
        if (PART == 1) {   
            count = 0;
            for (i = 0; i < strlen(pw[lines]); i++) {
                if (pw[lines][i] == letter[lines]) count++;
            }
            if (count >= begin_index[lines] && count <= end_index[lines]) valid++;
        } else {
            if (pw[lines][begin_index[lines]-1] == letter[lines] && pw[lines][end_index[lines]-1] != letter[lines]) valid++;
            else if (pw[lines][begin_index[lines]-1] != letter[lines] && pw[lines][end_index[lines]-1] == letter[lines]) valid++;
        }

        lines++;    
    }

    printf("Total valid pws: %d\n", valid);
    return 0;

}