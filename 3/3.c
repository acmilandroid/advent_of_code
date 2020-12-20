// advent calendar day 3

#define PART 2
#define SIZE 1000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

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

    //get first line to check row size since they are all the same
    char *row = calloc(sizeof(int), SIZE);
    fscanf(fpt, "%s\n", row);
    int row_size = strlen(row);

    //read rest of file after first line
    int pos = 0;
    long long tree = 0;

    if (PART == 1) {
        while (fscanf(fpt, "%s\n", row) == 1) {
            //iterate position and check for tree
            pos += 3;
            pos %= row_size;
            if (row[pos] == '#') tree++;
        }
    }
        
    else {
        //data for part 2
        int horizontal[5] = {1, 3, 5, 7, 1};
        int vertical[5] = {1, 1, 1, 1, 2};
        long long temp = 1;
        for (int i = 0; i < 5; i++) {
            fseek(fpt, 0, SEEK_SET); //need to reset file pointer
            fscanf(fpt, "%s\n", row); //skip first row always
            tree = 0;
            pos = 0;
            while (fscanf(fpt, "%s\n", row) == 1) {
                //read extra lines if the vertical jumps by more than 1
                for (int j = 0; j < vertical[i]-1; j++) {
                    fscanf(fpt, "%s\n", row);
                }
                pos += horizontal[i];
                pos %= row_size;
                if (row[pos] == '#') tree++;
            }
            temp *= tree;
            printf("tree: %lld\n", tree);
        }
        tree = temp;
    }

    printf("Total trees hit: %lld\n", tree);
    return 0;

}