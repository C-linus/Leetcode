import re

def mostCommonWord(paragraph: str, banned: list[str]) -> str:

	banned_words = set(banned)
	valid_words = dict()
	words = re.findall(r'\w+',paragraph.lower())

	for word in words:
		if word not in banned_words:
			valid_words[word] = valid_words.get(word,0) + 1

	return max(valid_words,key=valid_words.get)



def main():
	paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
	banned = ["hit"]
	print(f"Most Common Word:{mostCommonWord(paragraph,banned)}")

main()
