class Solution:
    def hammingWeight(self, n):
        count = 0
        while (n):
            n = n & (n-1)
            count = count + 1
        return count
if __name__ == "__main__":
    solution = Solution()
    print solution.hammingWeight(6)
