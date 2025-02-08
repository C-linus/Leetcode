class NumArray:
	def __init__(self,nums:list[int]):
		self.prefix = list()
		soFar = 0
		for num in nums:
			soFar += num
			self.prefix.append(soFar)
	def sumRange(self,left:int,right:int)->sum:
		rightSum = self.prefix[right]
		leftSum = self.prefix[left - 1] if (left > 0) else 0
		return rightSum - leftSum




def main():
	###Entry point
	nums1 = NumArray([-2, 0, 3, -5, 2, -1])
	#Test case - 1
	print("sumRange(0,2):",nums1.sumRange(0,2))
	#Test case - 2
	print("sumRange(2,5):",nums1.sumRange(2,5))
	#Test case - 3
	print("sumRange(0,5):",nums1.sumRange(0,5))


main()
