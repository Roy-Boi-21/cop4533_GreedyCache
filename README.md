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
Every input file must be in the "cmake-build-debug" folder 
for the program to read the file.

This program assumes you're running it in the CLion IDE with
the C++ standard set to C++ 17.

## Written Component
### Question 1: Empirical Comparison
All the data for this table was created with the random
data generator with an upper bound of 2k.  The data for
this table can be found in the data folder.

| Input File | k   | m    | FIFO | LRU  | OPTFF |
|------------|-----|------|------|------|-------|
| file1.txt  | 32  | 256  | 148  | 148  | 141   |
| file2.txt  | 64  | 512  | 269  | 269  | 259   |
| file3.txt  | 128 | 1024 | 562  | 562  | 523   |
| file4.txt  | 256 | 2048 | 1089 | 1110 | 1042  |
| file5.txt  | 512 | 4096 | 2270 | 2262 | 2151  |

As seen in the graph, the OPTFF algorithm always has the
least amount of cache misses compared to FIFO and LRU.

FIFO and LRU are comparable in performance.  In the first
three files, FIFO and LRU have the same amount of cache fails.
In the last two files, FIFO and LRU alternate between having the
most cache fails.

### Question 2: Bad Sequence for LRU or FIFO
There is a sequence such that OPTFF incurs strictly fewer
misses than LRU and FIFO.

Consider a sequence of n * (k + 1) integers in increasing order.
There are (k + 1) unique integers and sequence loops back to the
first unique integer after the last unique integer was added to
the sequence.  Take the following sequence below as an example
for k = 3.

`1 2 3 4 1 2 3 4 1 ...`

This sequence exists in "optimal_optff.txt".  Here are the results
of computing this sequence with all three algorithms.

| Input File        | k  | m  | FIFO | LRU | OPTFF |
|-------------------|----|----|------|-----|-------|
| optimal_optff.txt | 3  | 20 | 20   | 20  | 12    |

OPTFF outperformed both LRU and FIFO because LRU and FIFO kept
throwing out their oldest item which would be useful next
iteration while OPTFF knew to discard their newly acquired item
because it would only be needed four iterations from now while the
other items would be useful for all iterations prior to the fourth.

### Question 3: Prove OPTFF is Optimal
Assume that OPTFF is not optimal.

Let i_1, i_2, ..., i_n denote the evictions made by OPTFF.

Let j_1, j_2, ..., j_n denote the evictions made the optimal
algorithm (A) with i_1 = j_1, i_2 = j_2, ..., i_r = j_r where
r is the last value where OPTFF and the optimal algorithm agree.

Let i_r+1 and j_r+1 be the first eviction where OPTFF and (A)
disagree.

(A) evicts j_r+1 because it is the next request that needs to be
accessed the latest out of all the items in the cache currently.

OPTFF evicts i_r+1 because it is the next request in the cache
that occurs farthest in the future if at all.

It is valid for OPTFF to evict j_r+1 because it is the item that
appears again the latest out of everything in the cache.

Thus, we can replace i_r+1 with j_r+1.

This violates the condition that r is the last value where OPTFF
and (A) agree.  Therefore, OPTFF is optimal.
