/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#import <conio.h>

/* defines */
#define ARRAY_SIZE 100000

/* functions */
void print_stats(int *p);
void send_message(void);


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
        srand(time(NULL));   // Initialization, should only be called once.

        /* set values to 0 */
        for (int i=0; i<50; i++) {
                array[i] = 0;
        }

        /* calculate random numbers */
        for (int i=0; i<size; i++) {
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

/* send help message for user */
void send_message() {
    printf("With this program you can test if random numbers are actually random.\n");
    printf("If you want you can give the test size as input.\n");
    printf("If you give no input however a value of %d will be taken.\n", ARRAY_SIZE);
    printf("Example input: main.c -p 1000\n");
    printf("Example input: main.c --print 50000\n");
}