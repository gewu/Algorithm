class Solution:
    def singleNumber(self, A):
	b = 0
        for a in A:
            b ^= a
        return b
if __name__ == '__main__':
	s = Solution()
	A = [1,2,3,2,1]
	print s.singleNumber(A)
