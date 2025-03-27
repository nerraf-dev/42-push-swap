import random

random.seed(42)  # Fixed seed for consistency

with open("bm_100.txt", "w") as f:
    for i in range(4):
        test_case = random.sample(range(-2147483648, 2147483647), 5)
        f.write(" ".join(map(str, test_case)) + "\n")
