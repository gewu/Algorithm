class Solution:
    def maxSubArray(self, A):
        max = A[0]
        sum = 0
        for elem in A:
            sum = sum + elem
	    if (sum > max):
	    	max = sum
            if (sum < 0):
                sum = 0
        return max
if __name__ == "__main__":
    solution = Solution()
    A = [-2,1,-3,4,-1,2,1,-5,4]
    print solution.maxSubArray(A)


