def summary_ranges(nums):
	result = list()
	index = 0
	while(index < len(nums)):
		start = nums[index]
		while(index < len(nums) - 1 and nums[index] + 1 == nums[index + 1]):
			index += 1
		if(start == nums[index]):
			result.append(str(nums[index]))
		else:
			result.append(f"{start} -> {nums[index]}")
		index += 1
	return result


def main():
	### Entry point
	nums = [0,2,3,4,6,8,9]
	for intervals in summary_ranges(nums):
		print(intervals)

main()
