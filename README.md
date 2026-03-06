# COP4533 Programming Assignment 2: Greedy Algorithms
Created by David Visbal Gomez (UFID: 11497647)

## Compile Instructions
1. Clone into a CLion repository.
2. Run the program in CLion.

## Run Instructions
You will be prompted to input a number from 1 to 3 to determine
how the program will receive the data.
1. Input the data manually.
2. Read the data from a file.
3. Randomly generate the data with a set of parameters.

Then the program will prompt you to input the name of the output
file.

### Manual Input Instructions
You will input two positive integers.  The first two integers go
to determining the following values.
1. The size of the cache.  (k)
2. The amount of requests for the cache.  (m)

Then you must input m integers to represent all m requests that
the cache will receive.

Example Input:
````c++
1 // This is to choose manual input.
output.txt  // This is the name of the output file.
3 // This is the size of the cache.  (k)
8 // This is the request count.  (m)
1 // The rest of these numbers are the requests.
2
3
1
1
1
3
4
````

### File Input Instructions
You will provide the name of the filename with the data.

The input file must be in the cmake-build-debug folder or
else the program will not recognize the file.

The input file must follow this exact format or else the
program will throw an exception and terminate.

k = Cache Size.

m = Request Count.

r_m = Request M.
````
k m
r_1 r_2 r_3 ... r_m-2 r_m-1 r_m
````
There are two provided example files in cmake-build-debug
to test.  They are "example.txt" and "optimal_optff.txt".

Example Input:
````c++
2 // This is to choose to read from a file.
output.txt  // This is the name of the output file.
example.txt  // This is the name of the input file.
````

### Randomly Generated Input Instructions
You will input three positive integers.
1. The size of the cache.  (k)
2. The amount of requests for the cache.  (m)
3. The upper bound of the request range.  ("1 to X" where X is
the upper bound you've provided.)

Example Input:
````c++
3 // This is to choose to generate data.
output.txt  // This is the name of the output file.
256 // This is the size of the cache.
2048 // This is the amount requests the cache will get.
512 // This says the cache will get numbers from 1 to 512
````

### Output Instructions
After inputting the commands for the input method you chose, the
program will output statistics about each algorithms' hits
and misses.  Moreover, the program will create the output file
with the name you provided in the "cmake-build-debug" folder.

## Assumptions
Every input file must be in the "cmake-build-debug" folder for the program to read the file.

This program assumes you're running it in the CLion IDE with
the C++ standard set to C++ 17.

## Written Component
### Question 1: Empirical Comparison
Placeholder.

### Question 2: Bad Sequence for LRU or FIFO
Placeholder.

### Question 3: Prove OPTFF is Optimal
Placeholder.
