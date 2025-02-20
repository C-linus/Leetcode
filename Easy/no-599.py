def findRestaurant(list1: list[str], list2: list[str]) -> list[str]:
	hash_map = dict()

	for index,string in enumerate(list1):
		hash_map[string] = index

	minIndexSum = float('inf')
	indexSum = 0
	result = list()
	for index,string in enumerate(list2):
		if string in hash_map:
			indexSum = index + hash_map[string]
			if(indexSum < minIndexSum):
				result.clear()
				result.append(string)
				minIndexSum = indexSum
			elif (minIndexSum == indexSum):
				result.append(string)
	return result



def main():
	### Entry point
	list1 = ["Shogun","Tapioca Express","Burger King","KFC"]
	list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
	print(findRestaurant(list1,list2))


main()
