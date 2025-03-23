def fairCandySwap(aliceSizes: list[int], bobSizes: list[int]) -> list[int]:
	alice_total_candy_size = sum(aliceSizes)
	bob_total_candy_size = sum(bobSizes)
	hash_set = set(bobSizes)
	borrow = (bob_total_candy_size - alice_total_candy_size) // 2

	for swap in aliceSizes:
		if((swap + borrow ) in hash_set):
			return [swap,swap + borrow]
