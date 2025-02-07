def is_contains_duplicate(nums,k):
	hash_map = dict()
	for index,element in enumerate(nums):
		if element in hash_map and abs(hash_map[element] - index ) <= k:
			return True
		else:
			hash_map[element] = index
	return False



def main():
	### Entry point
	nums = [1,2,3,1,2,3]
	k = 2
	result = "Contains" if (is_contains_duplicate(nums,k)) else "Not Contains"
	print(f"The list {result} duplicate");

main()
