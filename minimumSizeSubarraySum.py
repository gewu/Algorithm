class Solution(object):
    def minSubArrayLen(self, s, nums):
        size = len(nums)
        start, end, sumNum = 0, 0, 0
        bestAns = size + 1
        
        while end < size:
            while end < size and sumNum < s:
                sumNum += nums[end]
                end += 1

            while start < end and sumNum >= s:
                if sumNum >= s:
                    bestAns = min(bestAns, end-start)
                sumNum -= nums[start]
                start += 1
        return [0, bestAns][bestAns <= size]

if __name__ == "__main__":
    nums = [2,3,1,2,4,3]
    s = Solution()
    print s.minSubArrayLen(7,nums)
    
