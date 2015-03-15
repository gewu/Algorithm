class Solution:
    def titleToNumber(self, s):
	ret = 0
	for i in range(0, len(s)-1):
        	ret += (ord(s[i])-64)*(26**(len(s)-i-1))
	ret += ord(s[-1]) - 64
        return ret
if __name__ == "__main__":
    s = Solution()
    print s.titleToNumber('AAA')
