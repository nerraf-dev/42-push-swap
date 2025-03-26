import random

ERROR_HANDLING = [
    ("Empty input", "", False),           # empty Expect no error: returns to prompt
    ("Non-integer input", "1 2 two", True),    # non-int Expect error
    ("Alphabetic input", "a b c", True),      # non-int Expect error
    ("Special character input", "1 2 #", True),      # non-int Expect error
    ("Duplicate values", "1 1 2", True),      # duplicate Expect error (duplicate)
    ("Underflow value", "-2147483649 1", True),  # out of range Expect error (underflow)
    ("Overflow value", "2147483648 9", True),   # out of range Expect error (overflow)
    ("Valid input", "1 2 3", False)      # Expect no error
]
# Edge cases
# All valid inputs, expect "OK" from checker
# (input, expected output)
EDGE_CASES = [
    ("Single element", "1"),
    ("Two elements sorted", "1 2"),
    ("Two elements unsorted", "2 1"),
    ("Ten elements sorted", "1 2 3 4 5 6 7 8 9 10"),
    ("Ten elements reverse sorted", "10 9 8 7 6 5 4 3 2 1"),
    ("INT_MIN and zero", f"{-2147483648} 0"),  # INT_MIN
    ("INT_MAX and zero", f"{2147483647} 0"),   # INT_MAX
    ("INT_MIN and INT_MAX", f"{-2147483648} {2147483647}"),  # INT_MIN and INT_MAX
    ("INT_MAX and INT_MIN", f"{2147483647} {-2147483648}"),  # INT_MAX and INT_MIN
    ("Zero", "0"),  # Zero
    ("Zero and boundary values", "0 1 -1"),  # Zero and boundary values
    ("Boundary values and zero", "1 -1 0"),  # Boundary values and zero
    ("INT_MAX, INT_MIN, and zero", "2147483647 -2147483648 0"),  # INT_MAX, INT_MIN, and zero
    ("INT_MIN, zero, and INT_MAX", "-2147483648 0 2147483647"),  # INT_MIN, zero, and INT_MAX
    ("INT_MIN, zero, and INT_MAX (reordered)", f"{-2147483648} 0 2147483647"),  # INT_MIN, zero, and INT_MAX
    ("INT_MAX, zero, and INT_MIN", f"{2147483647} 0 {-2147483648}"),  # INT_MAX, zero, and INT_MIN
    ("Zero, INT_MIN, and INT_MAX", f"0 {-2147483648} 2147483647"),  # Zero, INT_MIN, and INT_MAX
]

# "almost sorted" test cases
ALMOST_SORTED = [
    ("Already sorted", "1 2 3 4 5 6 7 8 9 10"),  # 0 swaps
    ("One move needed (rra)", "2 3 4 5 6 7 8 9 10 1"),  # 1 move (rra)
    ("Two moves needed (rra rra)", "3 4 5 6 7 8 9 10 1 2"),  # 2 moves (rra rra)
    ("Three moves needed (rra rra rra)", "4 5 6 7 8 9 10 1 2 3"),  # 3 moves (rra rra rra)
    ("Four moves needed (rra rra rra rra)", "5 6 7 8 9 10 1 2 3 4"),  # 4 moves (rra rra rra rra)
    ("Five moves needed (rotate or rev-rotate)", "6 7 8 9 10 1 2 3 4 5"),  # 5 moves (rotate or rev-rotate) * 5
    ("Four moves needed (ra ra ra ra)", "7 8 9 10 1 2 3 4 5 6"),  # 4 moves (ra, ra, ra, ra)
    ("Three moves needed (ra ra ra)", "8 9 10 1 2 3 4 5 6 7"),  # 3 moves (ra, ra, ra)
    ("Two moves needed (ra ra)", "9 10 1 2 3 4 5 6 7 8"),  # 2 moves (ra, ra)
    ("One move needed (ra)", "10 1 2 3 4 5 6 7 8 9"),  # 1 move (ra)
    ("One swap needed (sa)", "2 1 3 4 5 6 7 8 9 10"),  # 1 move (sa)
    ("Long sequence with one move needed", "2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 1"),
    ("Reverse sorted", "10 9 8 7 6 5 4 3 2 1"),
]

DESCENDING_ORDER = [
    ("Descending order 10 elements", "10 9 8 7 6 5 4 3 2 1"),
    ("Descending order mixed range", "50 40 30 20 10 5 4 3 2 1 0 -1 -2 -3 -4 -5 -10 -20 -30 -40 -50"),
    ("Descending order 100 elements", "100 95 90 85 80 75 70 65 60 55 50 45 40 35 30 25 20 15 10 5 0 -5 -10 -15 -20 -25 -30 -35 -40 -45 -50 -55 -60 -65 -70 -75 -80 -85 -90 -95 -100"),
    ("Descending order range 25 to -25", " ".join(map(str, range(25, -25, -1)))),
    ("Descending order range 50 to 0", " ".join(map(str, range(50, 0, -1)))),
    ("Descending order range 100 to 0", " ".join(map(str, range(100, 0, -1)))),
    ("Descending order range 500 to 0", " ".join(map(str, range(500, 0, -1)))),
    ("Descending order range 0 to -100", " ".join(map(str, range(0, -100, -1)))),
]

# Pre-generate random samples
random_2_elements = random.sample(range(-2147483648, 2147483647), 2)
random_3_elements = random.sample(range(-2147483648, 2147483647), 3)
random_5_elements = random.sample(range(-2147483648, 2147483647), 5)
random_10_elements = random.sample(range(-2147483648, 2147483647), 10)
random_25_elements = random.sample(range(-2147483648, 2147483647), 25)
random_50_elements = random.sample(range(-2147483648, 2147483647), 50)
random_100_elements = random.sample(range(-2147483648, 2147483647), 100)
random_500_elements = random.sample(range(-2147483648, 2147483647), 500)

RANDOM_ORDER = [
    ("Random order 2 elements 1", "1 2"),
    ("Random order 2 elements 2", "2 1"),
    ("Random order 2 elements 3", "0 -1"),
    ("Random order 2 elements 4", " ".join(map(str, random_2_elements))),
    # 3 numbers
    ("Random order 3 elements 1", "1 2 3"),
    ("Random order 3 elements 2", "1 3 2"),
    ("Random order 3 elements 3", "2 1 3"),
    ("Random order 3 elements 4", "2 3 1"),
    ("Random order 3 elements 5", "3 1 2"),
    ("Random order 3 elements 6", "3 2 1"),
    ("Random order 3 elements 7", " ".join(map(str, random_3_elements))),
    # 5 numbers
    ("Random order 5 elements 1", "1 2 3 4 5"),
    ("Random order 5 elements 2", "1 2 5 4 3"),
    ("Random order 5 elements 3", "5 4 3 2 1"),
    ("Random order 5 elements 4", "5 4 1 2 3"),
    ("Random order 5 elements 5", "3 2 1 5 4"),
    ("Random order 5 elements 6", "4 5 1 2 3"),
    ("Random order 5 elements 7", " ".join(map(str, random_5_elements))),
    # 10 numbers
    ("Random order 10 elements 1", "1 2 3 4 5 6 7 8 9 10"),
    ("Random order 10 elements 2", "1 2 3 4 5 10 9 8 7 6"),
    ("Random order 10 elements 3", "10 9 8 7 6 1 2 3 4 5"),
    ("Random order 10 elements 4", "10 9 8 7 6 5 4 3 2 1"),
    ("Random order 10 elements 5", "5 4 3 2 1 10 9 8 7 6"),
    ("Random order 10 elements 6", "6 7 8 9 10 1 2 3 4 5"),
    ("Random order 10 elements 7", " ".join(map(str, random_10_elements))),
    # 25 numbers
    ("Random order 25 elements", " ".join(map(str, random_25_elements))),
    # 50 numbers
    ("Random order 50 elements", " ".join(map(str, random_50_elements))),
    # 100 numbers
    ("Random order 100 elements", " ".join(map(str, random_100_elements))),
    # 500 numbers
    ("Random order 500 elements", " ".join(map(str, random_500_elements))),
]

