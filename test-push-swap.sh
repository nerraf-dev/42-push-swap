#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Number of tests to run for 100 and 500 values
NUM_TESTS=5

# OS-specific checker
OS=$(uname)
if [ "$OS" == "Darwin" ]; then
    CHECKER='./checker_Mac'
else
    CHECKER='./checker_linux'
fi

# Check if push_swap and checker exist
if [ ! -f ./push_swap ]; then
    echo -e "${RED}Error: ./push_swap not found!${NC}"
    exit 1
fi

if [ ! -f $CHECKER ]; then
    echo -e "${RED}Error: $CHECKER not found!${NC}"
    exit 1
fi

# Function to generate random integers without duplicates
generate_random_numbers() {
    local count=$1
    local min=$2
    local max=$3
    local numbers=()
    while [ ${#numbers[@]} -lt $count ]; do
        local num=$((min + RANDOM % (max - min + 1)))
        if [[ ! " ${numbers[@]} " =~ " ${num} " ]]; then
            numbers+=("$num")
        fi
    done
    echo "${numbers[@]}"
}

# Function to generate a mostly sorted list
generate_mostly_sorted_list() {
    local size=$1
    local list=()
    for ((i=1; i<=size; i++)); do
        list+=("$i")
    done
    # Move the last element to the beginning
    list=("${list[-1]}" "${list[@]:0:size-1}")
    echo "${list[@]}"
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
        "10 integers" "$(generate_random_numbers 10 -1000 1000)"
        "50 integers" "$(generate_random_numbers 50 -1000 1000)"
        "INT_MIN and INT_MAX" "-2147483648 2147483647"
        "Mostly sorted list (100 values)" "2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 1"
    )

    # Run tests
    for ((i=0; i<${#test_cases[@]}; i+=2)); do
        description="${test_cases[i]}"
        input="${test_cases[i+1]}"

        echo -e "\n${YELLOW}Test: $description${NC}"
        echo "Input: $input"

        # Run push_swap and checker
        ./push_swap $input | $CHECKER $input
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}KO${NC}"
        fi
    done
}

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

# Function to evaluate efficiency based on the number of operations
evaluate_efficiency() {
    local operations=$1
    local size=$2

    if [ $size -eq 3 ]; then
        if [ $operations -le 3 ]; then
            echo -e "${GREEN}3 values: $operations operations (Perfect)${NC}"
        else
            echo -e "${RED}3 values: $operations operations (Fail)${NC}"
        fi
    elif [ $size -eq 5 ]; then
        if [ $operations -le 12 ]; then
            echo -e "${GREEN}5 values: $operations operations (Perfect)${NC}"
        else
            echo -e "${RED}5 values: $operations operations (Fail)${NC}"
        fi
    elif [ $size -eq 100 ]; then
        if [ $operations -lt 700 ]; then
            echo -e "${GREEN}100 values: $operations operations (5 points)${NC}"
        elif [ $operations -lt 900 ]; then
            echo -e "${GREEN}100 values: $operations operations (4 points)${NC}"
        elif [ $operations -lt 1100 ]; then
            echo -e "${YELLOW}100 values: $operations operations (3 points)${NC}"
        elif [ $operations -lt 1300 ]; then
            echo -e "${YELLOW}100 values: $operations operations (2 points)${NC}"
        elif [ $operations -lt 1500 ]; then
            echo -e "${RED}100 values: $operations operations (1 point)${NC}"
        else
            echo -e "${RED}100 values: $operations operations (Fail)${NC}"
        fi
    elif [ $size -eq 500 ]; then
        if [ $operations -lt 5500 ]; then
            echo -e "${GREEN}500 values: $operations operations (5 points)${NC}"
        elif [ $operations -lt 7000 ]; then
            echo -e "${GREEN}500 values: $operations operations (4 points)${NC}"
        elif [ $operations -lt 8500 ]; then
            echo -e "${YELLOW}500 values: $operations operations (3 points)${NC}"
        elif [ $operations -lt 10000 ]; then
            echo -e "${YELLOW}500 values: $operations operations (2 points)${NC}"
        elif [ $operations -lt 11500 ]; then
            echo -e "${RED}500 values: $operations operations (1 point)${NC}"
        else
            echo -e "${RED}500 values: $operations operations (Fail)${NC}"
        fi
    fi
}

# Function to run multiple tests and calculate the average number of operations
run_multiple_tests() {
    local size=$1
    local total_operations=0

    echo -e "\n${YELLOW}Running $NUM_TESTS tests for $size values...${NC}"

    for ((i=1; i<=NUM_TESTS; i++)); do
        input=$(generate_random_numbers $size -10000 10000)
        operations=$(./push_swap $input | tee >(wc -l > ops_count) | $CHECKER $input)
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}KO${NC}"
        fi
        operations=$(cat ops_count)
        total_operations=$((total_operations + operations))
        echo -e "Test $i: $operations operations"
    done

    average_operations=$((total_operations / NUM_TESTS))
    echo -e "${YELLOW}Average operations for $size values: $average_operations${NC}"
    evaluate_efficiency $average_operations $size
    rm ops_count
}

# Function to test benchmark requirements
test_benchmark() {
    echo -e "${YELLOW}Testing benchmark requirements...${NC}"

    # Test 3 values
    echo -e "\n${YELLOW}Test: 3 random numbers${NC}"
    input=$(generate_random_numbers 3 -100 100)
    operations=$(./push_swap $input | wc -l)
    evaluate_efficiency $operations 3

    # Test 5 values
    echo -e "\n${YELLOW}Test: 5 random numbers${NC}"
    input=$(generate_random_numbers 5 -100 100)
    operations=$(./push_swap $input | wc -l)
    evaluate_efficiency $operations 5

    # Test 100 values (multiple tests)
    run_multiple_tests 100

    # Test 500 values (multiple tests)
    run_multiple_tests 500
}

# Main script
echo -e "${YELLOW}Starting tests...${NC}"

# Test valid inputs
test_valid_inputs

# Test invalid inputs
test_invalid_inputs

# Test benchmark requirements
test_benchmark

echo -e "${YELLOW}Tests completed.${NC}"
