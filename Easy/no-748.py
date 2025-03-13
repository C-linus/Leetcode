def shortestCompletingWord(licensePlate: str, words: list[str]) -> str:
    hash_map = dict()
    shortest_word = None

    for char in licensePlate:
        if char.isalpha():
            l_char = char.lower()
            if l_char in hash_map:
                hash_map[l_char] += 1
            else:
                hash_map[l_char] = 1

    for word in words:
        count = 0
        for key in hash_map:
            if word.count(key) >= hash_map[key]:
                count += 1
            else:
                break

        if count == len(hash_map):
            if shortest_word is None or len(word) < len(shortest_word):
                shortest_word = word

    return shortest_word


def main():
	licensePlate = "1s3 PSt"
	words = ["step","steps","stripe","stepple"]
	print(shortestCompletingWord(licensePlate,words))

main()
