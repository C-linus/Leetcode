def findRelativeRanks(score: list[int]) -> list[str]:
        result = list()
        ranks = sorted(score,reverse = True)
        rank_map = dict()

        for place,rank in enumerate(ranks):
            rank_map[rank] = place

        for scr in score:
            if(rank_map[scr] == 0):
                result.append("Gold Medal")
            elif(rank_map[scr] == 1):
                result.append("Silver Medal")
            elif(rank_map[scr] == 2):
                result.append("Bronze Medal")
            else:
                result.append(str(rank_map[scr] + 1))

        return result



def main():
	### Entry point
	score = [10,3,8,9,4]
	print(findRelativeRanks(score))

main()
