#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Comparison function for integers
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int main(int argc, char** argv) {
    printf("day 1.\n");

    FILE *fd = fopen("inputs/input1.txt", "r");

    char line[1024];
    int *left, *right;
    int len = 0;

    left = malloc(0);
    right = malloc(0);


    while (fgets(line, sizeof(line), fd)) {
        // Print each line to the standard output.

        len ++;
        left = (int*) realloc(left, len * sizeof(int));
        right = (int*) realloc(right, len * sizeof(int));

        char *token;
        token = strtok(line, " ");
        if (token != NULL) {
            left[len-1] = atoi(token); // Convert to integer
        }

        token = strtok(NULL, " ");
        if (token != NULL) {
            right[len-1] = atoi(token); // Convert to integer
        }
        
    }

    qsort(left, len, sizeof(int), compare);
    qsort(right, len, sizeof(int), compare);

    int total = 0;
    for (int i=0; i < len; i++) {
        total += abs(left[i] - right[i]);
    }

    int similarity = 0;
    for (int i=0; i < len; i++) {
        int hits = 0;
        for (int j=0; j < len; j++) {
            if (left[i] == right[j]) {
                hits++;
            }
        }
        similarity += (left[i] * hits);
    }


    free(left);
    free(right);
    fclose(fd);

    printf("result1: %d. result2: %d", total, similarity);

    return 0;
}
