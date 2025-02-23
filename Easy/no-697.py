def findShortestSubArray(nums: list[int]) -> int:
	count = dict()
	start = dict()
	end = dict()
	max_freq = 1

	for index,num in enumerate(nums):
		if num not in count:
			count[num] = 1
			start[num] = index
			end[num] = index
		else:
			count[num] += 1
			max_freq = max(max_freq,count[num])
			end[num] = index
	min_len = float('inf')

	for key, value in count.items():
		if(value == max_freq):
			min_len = min(min_len,end[key] - start[key] + 1)

	return min_len


def main():
	### Entry point
	nums = [1,2,2,3,1]
	print(f"Degree of Array:{findShortestSubArray(nums)}")

main()
