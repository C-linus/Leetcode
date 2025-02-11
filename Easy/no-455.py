def assign_cookies(greed:list[int],cookie:list[int])->int:
	greed.sort()
	cookie.sort()
	ptr1,ptr2 = 0,0

	while( ptr2 < len(cookie) and ptr1 < len(greed) ):
		if (cookie[ptr2] >= greed[ptr1]):
			ptr2 += 1
			ptr1 += 1
		else:
			ptr2 += 1

	return ptr1



def main():
	### Entry point
	greed = [1,5,3,3,4]
	cookie = [4,2,1,2,1,3]
	print("The maximum no of children's satisfied is:",assign_cookies(greed,cookie))

main()
