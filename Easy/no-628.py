def maximumProduct(nums: list[int]) -> int:
	nums.sort()
	prodMin = nums[0] * nums[1] * nums[-1]
	prodMax = nums[-1] * nums[-2] * nums[-3]
	return prodMin if (prodMin > prodMax) else prodMax




def main():
	### Entry point
	nums = [1,2,3,4]
	print(maximumProduct(nums))

main()
