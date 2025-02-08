def intersection(nums1:list[int],nums2:list[int])->list[int]:
	hash_set = set(nums1)
	result = list()
	for num in nums2:
		if num in hash_set:
			hash_set.remove(num)
			result.append(num)
	return result



def main():
	### Entry point
	nums1 = [4,9,5]
	nums2 = [9,4,9,8,4]
	print(f"Intersection:{intersection(nums1,nums2)}")



main()
