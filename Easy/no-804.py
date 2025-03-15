def uniqueMorseRepresentations(words: list[str]) -> int:
	unique_morse_codes = set()
	morse_codes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

	for word in words:
		transformation = str()
		for char in word:
			transformation += morse_codes[ord(char) - ord('a')]
		unique_morse_codes.add(transformation)
	return len(unique_morse_codes)




def main():
	words = ["gin","zen","gig","msg"]
	print(f"Unique Morse Codes : {uniqueMorseRepresentations(words)}")


main()
