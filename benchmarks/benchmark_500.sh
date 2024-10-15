#!/bin/bash

# Generate 500 random unique integers
python3 ../generate_random_numbers.py 500 > random_numbers.txt

# Run the push_swap program with the generated numbers
./push_swap < random_numbers.txt > operations.txt

# Count the number of operations
operation_count=$(wc -l < operations.txt)

# Check if the operation count is within the limit
if [ "$operation_count" -le 5500 ]; then
    echo "Benchmark for 500 numbers passed: $operation_count operations."
else
    echo "Benchmark for 500 numbers failed: $operation_count operations."
fi

# Clean up
rm random_numbers.txt operations.txt
