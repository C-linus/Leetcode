def arrayPairSum(nums: list[int]) -> int:
        nums.sort()
        result = 0
        for index in range(0,len(nums),2):
            result += nums[index]
        return result


def main():
	### Entry point
	nums = [6,2,6,5,1,2]
	print(f"Sum is:{arrayPairSum(nums)}")


main()
