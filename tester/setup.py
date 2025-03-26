import platform, os
from config import PUSH_SWAP

def set_checker():
	# Determine the correct checker binary based on the OS
	if platform.system() == "Darwin":  # MacOS
		CHECKER = "./checker_Mac"
	elif platform.system() == "Linux":
		CHECKER = "./checker_Linux"
	else:
		raise Exception("Unsupported OS")
	if not os.path.isfile(CHECKER):
		raise Exception(f"Checker binary not found: {CHECKER}")
	return CHECKER

def check_bonus():
	# Check if bonus checker is available
	if os.path.isfile("./checker"):
		return True
	raise Exception("⚠️  Bonus checker not found")

def check_push_swap():
	# Check if push_swap is available
	if not os.path.isfile(PUSH_SWAP):
		raise Exception(f"⚠️  push_swap not found")
	return False


