#!/bin/bash

# Generate 100 random unique integers
python3 ../generate_random_numbers.py 100 > random_numbers.txt

# Run the push_swap program with the generated numbers and capture the output
operations=$(./push_swap < random_numbers.txt | wc -l)

# Check if the number of operations is less than 700
if [ "$operations" -lt 700 ]; then
    echo "Benchmark for 100 numbers: Passed ($operations operations)"
else
    echo "Benchmark for 100 numbers: Failed ($operations operations)"
fi

# Clean up
rm random_numbers.txt
