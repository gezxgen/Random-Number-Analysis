# Random Number Analysis Program Documentation

## Overview
This program generates random numbers and evaluates their distribution over a specified number of iterations. It also calculates the time taken to generate the numbers and displays the statistics in intervals of 10%. The user can specify the number of random numbers to generate through command-line arguments.

## Compilation
To compile the program, use a C compiler such as GCC:

```bash
gcc main.c -o random_analysis
```

## Execution
The program can be executed from the command line with optional arguments. Below are the possible command-line options:

### Command-Line Options:
- `-h` or `--help`: Displays a help message and exits.
- `-p [number]` or `--print [number]`: Specifies the number of random numbers to generate. The program defaults to 100,000 if no number is provided.

### Example Usage:
```bash
./random_analysis        # Generates 100,000 random numbers
./random_analysis -p 5000 # Generates 5,000 random numbers
./random_analysis -h      # Displays the help message
```

## Code Breakdown

### Constants and Macros

```c
#define ARRAY_SIZE 100000  // Default array size if no size is provided
#define PERCENT 37         // ASCII value for percentage sign (%)
```

### Functions

#### `void print_stats(int *p, int k)`
- **Description**: Prints the statistics of the random number generation.
- **Parameters**:
    - `p`: Pointer to the start of the array holding the random number counts.
    - `k`: Total number of iterations.
- **Functionality**: Iterates over the array and prints the frequency of each random number, along with its percentage relative to the total number of iterations.

```c
void print_stats(int *p, int k) {
    printf("------------------------- Statistik -------------------------\n");
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
```

#### `void send_message(void)`
- **Description**: Displays a help message that explains the program usage.
- **Parameters**: None.
- **Functionality**: Prints out instructions on how to use the program and exits upon completion.

```c
void send_message() {
    printf("With this program you can test if random numbers are actually random.\n");
    printf("If you want you can give the test size as input.\n");
    printf("If you give no input however a value of %d will be taken.\n", ARRAY_SIZE);
    printf("Example input: main.c -p 1000\n");
    printf("Example input: main.c --print 50000\n");
}
```

#### `void print_times(double *q, int j)`
- **Description**: Prints the elapsed time for generating random numbers in 10% intervals.
- **Parameters**:
    - `q`: Pointer to the array storing the time data.
    - `j`: Number of intervals for which times are printed.
- **Functionality**: Iterates over the time array and prints the elapsed time for each segment of the random number generation process.

```c
void print_times(double *q, int j) {
    printf("------------------------- Zeiten -------------------------\n");
    for (int i=0; i<j; i++) {
        printf("Zeit f%cr %d%c:\t%.3fs\n", UE, (i+1)*10, PERCENT, *q);
        q += 1;
    }
    printf("----------------------------------------------------------\n");
}
```

### Main Function

#### `int main(int argc, char *argv[])`
- **Description**: Main function that initializes the program, handles command-line arguments, and controls the random number generation process.
- **Parameters**:
    - `argc`: Number of command-line arguments.
    - `argv[]`: Array of command-line arguments.

- **Flow**:
    1. Checks if command-line arguments are provided. If not, defaults to `ARRAY_SIZE`.
    2. If `-h` or `--help` is passed, the help message is displayed.
    3. If `-p` or `--print` is passed, the program parses the provided number as the array size.
    4. Initializes an array of integers to hold the count of random numbers and a `times` array for time tracking.
    5. Random numbers are generated and stored in the array. Statistics are printed at 10% intervals, along with the time taken for each segment.
    6. The user presses a key to exit the program.

```c
int main(int argc, char *argv[]) {
    int size = 0;

    // Handle command-line arguments
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

    int array[size];
    int *p = &array[0];
    double times[10];
    double *q = &times[0];
    srand(time(NULL));   // Seed random number generator
    clock_t time;

    // Initialize arrays
    for (int i = 0; i < 50; i++) {
        if (i < 10) {
            times[i] = 0;
        }
        array[i] = 0;
    }

    // Generate random numbers
    for (int i = 0; i <= size; i++) {
        if (i && i % (size / 10) == 0) {
            int j = i / (size / 10) - 1;
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
```

### Error Handling
- If invalid characters are passed after the `-p` option (e.g., letters instead of numbers), the program will display an error message and terminate.
- If insufficient arguments are passed with the `-p` option, the program displays the help message and exits.

## Dependencies
The program uses the following libraries:
- `stdio.h`: For input/output functions.
- `stdlib.h`: For memory allocation, random number generation, and process control.
- `time.h`: For time functions.
- `string.h`: For string comparison (`strcmp`).
- `conio.h`: For handling user input (`getch`).

## Example Output

```text
------------------------- Statistics ---------------------
01: 123 (12.300%)   02: 89 (8.900%)   03: 95 (9.500%)   ...
...
------------------------- Timestamps ---------------------
Zeit für 10%:  0.345s
Zeit für 20%:  0.672s
...
----------------------------------------------------------
```

## Limitations
- The program is limited to generating random numbers within the range of 0 to 49.
- The time calculations may not be highly accurate for small datasets due to the resolution of the system clock.

## Future Enhancements
- Allowing users to specify the range of random numbers.
- Improved error handling and user prompts for invalid inputs.
---
