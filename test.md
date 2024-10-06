# Test Protocol
**Project Name**: Random Number Analysis Program  
**File Name**: main.c  
**Author**: Kevin  
**Test Date**: 06.10.2024
--- 

### Test Cases:

#### Test Case 1: Program Start without Arguments
- **Description**: Start the program without any command-line arguments.
- **Input**: `./main.c`
- **Expected Outcome**: The program uses the default value `ARRAY_SIZE` (100,000) for the number of random numbers.
- **Observed Outcome**: [Enter what actually happened here]
- **Status**: [Passed / Failed]
--- 

#### Test Case 2: Display Help
- **Description**: Run the program with the `-h` or `--help` option.
- **Input**: `./main.c -h` or `./main.c --help`
- **Expected Outcome**: A help message is displayed, describing the program's purpose and possible inputs.
- **Observed Outcome**: [Enter what actually happened here]
- **Status**: [Passed / Failed]
--- 

#### Test Case 3: Program with Valid Size Input
- **Description**: Run the program with the `-p` or `--print` option and a valid number.
- **Input**: `./main.c -p 1000` or `./main.c --print 1000`
- **Expected Outcome**: The program generates 1,000 random numbers and displays the statistical distribution.
- **Observed Outcome**: [Enter what actually happened here]
- **Status**: [Passed / Failed]
--- 

#### Test Case 4: Program with Invalid Input after `-p` or `--print`
- **Description**: Run the program with invalid characters after the `-p` or `--print` option (e.g., letters).
- **Input**: `./main.c -p abc`
- **Expected Outcome**: An error message is displayed, indicating that invalid characters were found after the number.
- **Observed Outcome**: [Enter what actually happened here]
- **Status**: [Passed / Failed]
--- 

#### Test Case 5: Random Number Generation and Time Output
- **Description**: Verify whether the program correctly generates random numbers and calculates times for each segment (10%, 20%, etc.).
- **Input**: `./main.c`
- **Expected Outcome**: The program correctly displays the statistics for random number distribution and the time per segment.
- **Observed Outcome**: [Enter what actually happened here]
- **Status**: [Passed / Failed]
--- 
