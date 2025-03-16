#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Function to generate unique random integers
generate_random_numbers() {
    local count=$1
    local min=$2
    local max=$3
    local numbers=()
    local num

    while [ ${#numbers[@]} -lt $count ]; do
        num=$((min + RANDOM % (max - min + 1)))
        if [[ ! " ${numbers[@]} " =~ " ${num} " ]]; then
            numbers+=("$num")
        fi
    done

    echo "${numbers[@]}"
}

# Function to test valid inputs
test_valid_inputs() {
    echo -e "${YELLOW}Testing valid inputs...${NC}"

    # Test cases
    local test_cases=(
        "2 integers" "$(generate_random_numbers 2 -100 100)"
        "3 integers" "$(generate_random_numbers 3 -100 100)"
        "4 integers" "$(generate_random_numbers 4 -100 100)"
        "5 integers" "$(generate_random_numbers 5 -100 100)"
        "10 integers" "$(generate_random_numbers 10 -100 100)"
        "50 integers" "$(generate_random_numbers 50 -1000 1000)"
        "100 integers" "$(generate_random_numbers 100 -1000 1000)"
        "200 integers" "$(generate_random_numbers 200 -10000 10000)"
        "500 integers" "$(generate_random_numbers 500 -10000 10000)"
        "INT_MIN and INT_MAX" "-2147483648 2147483647"
    )

    # Run tests
    for ((i=0; i<${#test_cases[@]}; i+=2)); do
        description="${test_cases[i]}"
        input="${test_cases[i+1]}"

        echo -e "\n${YELLOW}Test: $description${NC}"
        echo "Input: $input"

        # Run push_swap and checker
        ./push_swap $input | ./checker_Mac $input
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}KO${NC}"
        fi
    done
}

# Function to test invalid inputs
# Function to test invalid inputs
test_invalid_inputs() {
    echo -e "${YELLOW}Testing invalid inputs...${NC}"

    # Test cases
    local test_cases=(
        "No arguments" ""
        "Duplicate values" "1 2 3 4 5 5"
        "Value larger than INT_MAX" "2147483648"
        "Value smaller than INT_MIN" "-2147483649"
        "Incorrect type (string)" "1 2 three 4"
        "Incorrect type (char)" "1 2 @ 4"
    )

    # Run tests
    for ((i=0; i<${#test_cases[@]}; i+=2)); do
        description="${test_cases[i]}"
        input="${test_cases[i+1]}"

        echo -e "\n${YELLOW}Test: $description${NC}"
        echo "Input: $input"

        if [ -z "$input" ]; then
            # Special case for no arguments
            output=$(./push_swap)
            if [ -z "$output" ]; then
                echo -e "${GREEN}No output as expected${NC}"
            else
                echo -e "${RED}Unexpected output: $output${NC}"
            fi
        else
            # Run push_swap and check for error message
            ./push_swap $input 2>&1 | grep -q "Error"
            if [ $? -eq 0 ]; then
                echo -e "${GREEN}Error message displayed${NC}"
            else
                echo -e "${RED}Error message not displayed${NC}"
            fi
        fi
    done
}

# Main script
echo -e "${YELLOW}Starting tests...${NC}"

# Test valid inputs
test_valid_inputs

# Test invalid inputs
test_invalid_inputs

echo -e "${YELLOW}Tests completed.${NC}"
