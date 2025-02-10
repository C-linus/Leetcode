def find_missing_numbers(nums:list[int],n:int)->list[int]:
	result = list()
	for num in nums:
		mark_index = nums[abs(num) - 1]
		#Check the number is already marked
		if(mark_index > 0):
			nums[abs(num) - 1] = mark_index * (-1)

	#Find the positive indices and append it to the list
	for index in range(0,n):
		if (nums[index] > 0):
			result.append(index + 1)

	return result



def main():
	### Entry point
	nums = [1,1]
	n = len(nums)
	print(f"The missing numbers are:{find_missing_numbers(nums,n)}")


main()
