/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* defines */
#define ARRAY_SIZE 100000

/* functions */
void print_stats(int *p);

/* main */
int main(int argc, char *argv[]) {
        /* nichts, -p, --print, -h, --help */
        int size = 0;
        if (argc == 4) {
                printf("4 args");
                size = ARRAY_SIZE;
        } else {
                size = ARRAY_SIZE;
        }

        /* init */
        int array[ARRAY_SIZE];
        int *p = &array[0];
        srand(time(NULL));   // Initialization, should only be called once.

        /* set values to 0 */
        for (int i=0; i<50; i++) {
                array[i] = 0;
        }

        /* calculate random numbers */
        for (int i=0; i<ARRAY_SIZE; i++) {
                array[rand() % 50] += 1;
        }

        print_stats(p);

        char ret = 'A';
        scanf("%c", &ret);
        return 0;
}

/* print the generated stats */
void print_stats(int *p) {
        for (int i=0; i<50; i++) {
                if (i < 9) {
                        printf("0");
                }
                printf("%d: %d\t\t", i+1, *p);
                p += 1;
                if ((i+1) % 5 == 0) {
                        printf("\n");
                }
        }
}