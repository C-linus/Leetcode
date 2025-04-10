class Solution:
    def GCD(self, a , b):
        while(a * b and a != b):
            if(a > b):
                a %= b
            elif(b > a):
                b %= a
        return a if (a > b) else b


    def hasGroupsSizeX(self, deck: List[int]) -> bool:

        counter = dict()

        for card in deck:
            counter[card] = counter.get(card,0) + 1

        gcd = 0
        for count in counter.values():
            gcd = self.GCD(count,gcd)

        return gcd > 1
