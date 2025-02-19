def findLHS( nums: list[int]) -> int:

	freq_map = dict()
	for num in nums:
		if(num not in freq_map):
			freq_map[num] = 1
		else:
			freq_map[num] += 1


	max_subseq = 0
	for num in nums:
		if((num + 1) in freq_map):
			curr_subseq = freq_map[num] + freq_map[num + 1]
			max_subseq = max(max_subseq,curr_subseq)
	return max_subseq



def main():
	### Entry Main
	nums = [1,3,2,2,5,2,3,7]
	print(findLHS(nums))


main()
