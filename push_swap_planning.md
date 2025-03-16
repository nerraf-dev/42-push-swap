# Planning...of some sort

## Check the arguments
- if args <= 1: Error "No arguments passed"
- else if > 1:
	- check arguments are ints
	- check for duplicates



## Sort the stack: 3 numbers
1 2 3	sorted
2 1 3	sa [0]>[1] [2]==max
2 3 1	rra [2] == min [0]<[1]
3 2 1	ra sa [0] == max [1]>[2]
3 1 2	ra [1]<[2]
1 3 2	sa ra [1] == max [0]<[2]
