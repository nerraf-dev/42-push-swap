#!/usr/bin/env python3
import subprocess
import random
import sys
from config import PUSH_SWAP, MAX_TEST_SIZE, TEST_COUNT, COLOUR
from setup import set_checker, check_bonus, check_push_swap
from tests import (
	ERROR_HANDLING,
	EDGE_CASES,
	ALMOST_SORTED,
	DESCENDING_ORDER,
	RANDOM_ORDER,
	BM_3,
	BM_5,
	BM_100,
	BM_500,
	)



def run_test(numbers):
	"""Test push_swap with given numbers and verify with checker"""
	args = [str(n) for n in numbers]
	cmd_push = [PUSH_SWAP] + args
	cmd_check = [CHECKER] + args
	cmd_bonus = ["./checker"] + args

	try:
		# Run push_swap and count operations
		result = subprocess.run(cmd_push, capture_output=True, text=True, check=True)
		ops = result.stdout.splitlines()
		op_count = len(ops)
		# Verify with checker
		checker = subprocess.run(cmd_check, input=result.stdout, capture_output=True, text=True)
		# print(f"Checker: {checker.stdout}")
		if "KO" in checker.stdout:
			print(f"❌ Failed on: {numbers}")
			return False
		if BONUS:
			# Verify with bonus checker
			checker_bonus = subprocess.run(cmd_bonus, input=result.stdout, capture_output=True, text=True)
			if "KO" in checker_bonus.stdout:
				print(f"❌ Bonus checker failed on: {numbers}")
				return False
		return op_count
	except subprocess.CalledProcessError:
		print(f"⚠️  Crash on: {numbers}")
		return False

def test_random(size):
	"""Test with random numbers of given size"""
	numbers = random.sample(range(-2147483648, 2147483647), size)
	op_count = run_test(numbers)
	if op_count:
		print(f"✅ Size {size}: {op_count} ops")
		return op_count
	return 0

def run_test_cases(test_name, test_cases):
	"""Run test cases"""
	count = 0
	ops = 0
	op_total = 0
	op_low = 2147483647
	op_high = -21474836478
	for name, test in test_cases:
		# print(f"Testing: {test_name}")
		ops = run_test(test.split())
		print(f"TEST: {name} OPS: {ops}")
		if (ops < op_low):
			op_low = ops
		if (ops > op_high):
			op_high = ops
		op_total += ops
		count+=1
	print(COLOUR["GREEN"],f"✅ Push Swap \"{test_name}\" cases passed",COLOUR["ENDC"])
	if BONUS:
		print(COLOUR["PURPLE"],f"✅ Checker \"{test_name}\" cases passed",COLOUR["ENDC"])
	print(f"LOW: {op_low} HIGH: {op_high}")
	return op_total/count

def test_error_handling():
	"""Verify error cases"""
	count, bonus_count = 0, 0
	for name, test, should_error in ERROR_HANDLING:
		result = subprocess.run([PUSH_SWAP] + test.split(), capture_output=True, text=True)
		if BONUS:
			result_bonus = subprocess.run(["./checker"] + test.split(), input=result.stdout, capture_output=True, text=True)
			if ("Error" in result_bonus.stderr) != should_error:
				print(f"❌ Error checker test failed: {name} - {test}")
				return False
			bonus_count += 1
		count+=1
		if ("Error" in result.stderr) != should_error:
			print(f"❌ Error test failed: {name} - {test}")
			return False
	print(COLOUR["GREEN"],f"✅ Push Swap \"Error\" cases passed",COLOUR["ENDC"])
	if BONUS:
		print(COLOUR["PURPLE"],f"✅ Checker \"Error\" cases passed",COLOUR["ENDC"])
	return True

def print_error_exit(msg):
	print(COLOUR["RED"], msg, COLOUR["ENDC"])
	sys.exit(1)

def main():
	global CHECKER
	global BONUS

	# Check if push_swap is available
	# Error & exit if not found
	try:
		isPushSwap = check_push_swap()
	except Exception as e:
		print_error_exit(e)
	# Set correct checker binary
	# Error & exit if not found
	try:
		CHECKER = set_checker()
	except Exception as e:
		print_error_exit(e)
	# Check if bonus checker is available
	try:
		BONUS = check_bonus()
	except Exception as e:
		print(COLOUR["YELLOW"], e, COLOUR["ENDC"])
		BONUS = False

	# --- BEGIN TESTING ---
	# Test error handling
	errors = test_error_handling()
	# Test edge cases
	edge_cases = run_test_cases("Edge cases", EDGE_CASES)
	# Test ALMOST_SORTED
	almost_sorted = run_test_cases("Almost sorted", ALMOST_SORTED)
	# Test DESCENDING_ORDER
	descending_order = run_test_cases("Descending order", DESCENDING_ORDER)
	# Test random inputs
	random_cases = run_test_cases("Random", RANDOM_ORDER)
	print(random_cases)
	# Test benchmarks
	# 3 values: no more than 3 actions.
	bm3 = run_test_cases("Benchmarks: 3", BM_3)
	print(f"🌐 Average ops: {bm3:.1f}")
	# 5 values: no more than 12 actions.
	bm5 = run_test_cases("Benchmarks: 5", BM_5)
	print(f"🌐 Average ops: {bm5:.1f}")
	# # 100 values: from 1 to 5 points depending on the number of actions:
	# bm100 = run_test_cases("Benchmarks: 100", BM_100)
	# print(f"🌐 Average ops: {bm100:.1f}")
	# # 500 values: from 1 to 5 points depending on the number of actions:
	# bm500 = run_test_cases("Benchmarks: 500", BM_500)
	# print(f"🌐 Average ops: {bm500:.1f}")

	# Test random inputs
	# total_ops = 0
	# for size in range(1, MAX_TEST_SIZE + 2, 50):  # Test sizes 3, 53, 103...
	# 	for _ in range(TEST_COUNT):
	# 		total_ops += test_random(size) or 0

	# print(f"\n🌐 Average ops: {total_ops / (TEST_COUNT * (MAX_TEST_SIZE // 50)):.1f}")

if __name__ == "__main__":
	main()
