#!/bin/bash
# Function to generate random numbers using python3
generate_random_numbers() {
    count=$1
    python3 -c "import random; print(' '.join(map(str, random.sample(range(1, $count + 1), $count))))"
}

# Run tests
for i in {1..100}; do
    input=$(generate_random_numbers 100)
    ./push_swap $input > /dev/null
    if [ $? -ne 0 ]; then
        echo "Test failed with input: $input"
        exit 1
    fi
done

echo "All tests passed!"
