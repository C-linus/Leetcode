


def is_contains_duplicate(nums:list):
	hash_set = set()
	for num in nums:
		if (num in hash_set):
			return True
		else:
			hash_set.add(num)
	return False


def main():
	### Entry point
	nums = [1,1,1,3,3,4,3,2,4,2]
	result = "Contains" if (is_contains_duplicate(nums)) else "Not contains"
	print(f"The numbers list {result} at least one duplicate of an element")

main()
