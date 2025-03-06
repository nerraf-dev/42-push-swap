#!/bin/bash

# Default file containing the test cases
TEST_FILE="/home/simon/42-push-swap/benchmarks/tests.txt"

# Output file to store the results
OUTPUT_FILE="results.txt"

# Path to the push_swap executable
PUSH_SWAP="./push_swap"

# Function to display usage information
usage() {
    echo "Usage: $0 [-f test_file] [-o output_file]"
    echo "  -f test_file    Specify the test file (default: $TEST_FILE)"
    echo "  -o output_file  Specify the output file (default: $OUTPUT_FILE)"
    exit 1
}

# Parse command-line arguments
while getopts "f:o:" opt; do
    case $opt in
        f)
            TEST_FILE="$OPTARG"
            ;;
        o)
            OUTPUT_FILE="$OPTARG"
            ;;
        *)
            usage
            ;;
    esac
done

# Check if the push_swap executable exists
if [ ! -f "$PUSH_SWAP" ]; then
    echo "Error: push_swap executable not found at $PUSH_SWAP"
    exit 1
fi

# Check if the test file exists
if [ ! -f "$TEST_FILE" ]; then
    echo "Error: test file not found at $TEST_FILE"
    exit 1
fi

# Clear the output file
> "$OUTPUT_FILE"

# Initialize variables for calculating the average
total_commands=0
test_count=0

# Read the test cases from the file
while IFS= read -r line; do
    # Run push_swap with the current test case
    COMMANDS=$($PUSH_SWAP $line)

    # Count the number of commands output by push_swap
    COMMAND_COUNT=$(echo "$COMMANDS" | wc -l)

    # Add to the total command count and increment the test count
    total_commands=$((total_commands + COMMAND_COUNT))
    test_count=$((test_count + 1))

    # Print the test case and the command count to the output file
    echo "Test case: $line" >> "$OUTPUT_FILE"
    echo "Command count: $COMMAND_COUNT" >> "$OUTPUT_FILE"
    echo "------------------------" >> "$OUTPUT_FILE"
done < "$TEST_FILE"

# Calculate the average command count
if [ $test_count -gt 0 ]; then
    average_commands=$(echo "scale=2; $total_commands / $test_count" | bc)
else
    average_commands=0
fi

# Print the average command count to the output file
echo "Average command count: $average_commands" >> "$OUTPUT_FILE"

echo "Results have been written to $OUTPUT_FILE"
