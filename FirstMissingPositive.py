class Solution(object):
    def firstMissingPositive(self, nums):
        a = max(nums)

        dflag = {}
        for e in nums:
            if e > 0 and dflag.get(e, -1) == -1:
                dflag[e] = 1

        for e in range(1, a+2):
            if dflag.get(e, -1) == -1:
                return e
        return 1


if __name__ == "__main__":
    nums = [1,3,5]
    s = Solution()
    print s.firstMissingPositive(nums)
