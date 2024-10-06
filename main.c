/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#import <conio.h>

/* defines */
#define ARRAY_SIZE 100000
#define AE 132
#define OE 148
#define UE 129
#define PERCENT 37

/* functions */
void print_stats(int *p, int k);
void send_message(void);
void print_times(double *q, int j);


/* main */
int main(int argc, char *argv[]) {
        /* Get length of strings */
        int size = 0;

        /* Switch case to get command-line arguments */
        if (argc == 1) {
            size = ARRAY_SIZE;
        } else {
            if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
                send_message();
                getch();
                exit(0);
            } else if ((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "--print") == 0)) {
                if (argc >= 3) {
                    char *p;
                    long answer = strtol(argv[2], &p, 10);
                    if (*p != '\0') {
                        printf("Invalid characters found after number: %c\n", *p);
                        send_message();
                        getch();
                        exit(0);
                    } else {
                        size = (int)answer;
                    }
                } else {
                    send_message();
                    getch();
                    exit(0);
                }
            } else {
                send_message();
                getch();
                exit(0);
            }
        }

        /* init */
        int array[size];
        int *p = &array[0];
        double times[10];
        double *q = &times[0];
        srand(time(NULL));   // Initialization, should only be called once.
        clock_t time;

        /* set values to 0 */
        for (int i=0; i<50; i++) {
            if (i < 10) {
                times[i] = 0;
            }
            array[i] = 0;
        }

        /* calculate random numbers */
        for (int i=0; i<=size; i++) {
            if (i && i % (size/10) == 0) {
                int j = i / (size/10) - 1;
                system("cls");
                time = clock();
                times[j] = (((double)time)/CLOCKS_PER_SEC) - times[j-1];
                print_stats(p, i);
                print_times(q, j+1);
            }
            array[rand() % 50] += 1;
        }

        char ret = getch();
        return 0;
}

/* print the generated stats */
void print_stats(int *p, int k) {
    printf("------------------------- Statistics -------------------------\n");
    for (int i=0; i<50; i++) {
        if (i < 9) {
            printf("0");
        }

        printf("%d: %d (%.3f%c)\t", i+1, *p, 100*((float)*p)/((float)k), PERCENT);
        p += 1;
        if ((i+1) % 5 == 0) {
            printf("\n");
        }
    }
}

void print_times(double *q, int j) {
    printf("------------------------- Timestamps -------------------------\n");
    for (int i=0; i<j; i++) {
        printf("Zeit f%cr %d%c:\t%.3fs\n", UE, (i+1)*10, PERCENT, *q);
        q += 1;
    }
    printf("----------------------------------------------------------\n");
}

/* send help message for user */
void send_message() {
    printf("With this program you can test if random numbers are actually random.\n");
    printf("If you want you can give the test size as input.\n");
    printf("If you give no input however a value of %d will be taken.\n", ARRAY_SIZE);
    printf("Example input: main.c -p 1000\n");
    printf("Example input: main.c --print 50000\n");
}