def generate_random_numbers(count, min_value=-10000, max_value=10000):
    import random

    if count > (max_value - min_value + 1):
        raise ValueError("Count exceeds the range of unique numbers available.")

    numbers = set()
    while len(numbers) < count:
        numbers.add(random.randint(min_value, max_value))

    return list(numbers)

if __name__ == "__main__":
    import sys

    if len(sys.argv) != 3:
        print("Usage: python generate_random_numbers.py <num_of_sets> <integer_count> - MAX 10000")
        sys.exit(1)

    try:
        count = int(sys.argv[2])
        for _ in range(int(sys.argv[1])):
            random_numbers = generate_random_numbers(count)
            print(" ".join(map(str, random_numbers)))
    except ValueError as e:
        print(f"Error: {e}")
