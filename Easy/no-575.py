def distributeCandies(candyType: list[int]) -> int:
	return min(len(candyType) // 2, len(set(candyType)))


def main():
	### Entry point
	candyType = [1,1,2,2,3,3]
	print(f"She can eat {distributeCandies(candyType)} candies")

main()
