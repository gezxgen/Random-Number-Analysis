/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* defines */
#define ARRAY_SIZE 100000

/* functions */
void print_stats(int *p);

/* main */
int main(int argc, char *argv[]) {
        /* Get length of strings */
        int size = 0;
        int len[argc];
        for (int i=1; i<=argc; i++) {
                len[i] = strlen(argv[i]);
                printf("%d\n", len[i]);
        }

        /* Switch case to get command-line arguments */
        /* nichts, -p, --print, -h, --help */
        switch (argc) {
        case 1:
                size = ARRAY_SIZE;
        default:
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