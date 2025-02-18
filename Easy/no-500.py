def findwords( words: list[str])-> list[str]:
	hash_map = dict()
	result = list()
	keyboard_group = ["qwertyuiop","asdfghjkl","zxcvbnm"]

	for i in range(len(keyboard_group)):
		for letter in keyboard_group[i]:
			hash_map[letter] = i
			hash_map[letter.swapcase()] = i

	for word in words:
		is_match = True
		first_letter = -1
		for letter in word:
			if(first_letter == -1):
				first_letter =  hash_map[letter]

			else:
				if(hash_map[letter] != first_letter):
						is_match = False
						break
		if(is_match):
			result.append(word)

	return result



def main():
	### Entry point
	words = ["abdfs","cccd","a","qwwewm"]
	print(findwords(words))


main()
