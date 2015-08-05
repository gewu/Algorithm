class Solution:
    def nextPermutation(self, nums):
        if len(nums) <= 1:
            return 
        n = len(nums)
        j = n-2
        while j >= 0 and nums[j] >= nums[j+1]:
            j -= 1
        if j < 0:
            nums.sort()
            return 
        i = j+1
        while i<n and nums[i] > nums[j]:
            i += 1

        i -= 1
        tmp = nums[i]
        nums[i] = nums[j]
        nums[j] = tmp

        tmp = nums[j+1:]
        tmp.sort()
        nums[j+1:] = tmp

if __name__ == "__main__":
    nums = [1,3,2]
    s = Solution()
    s.nextPermutation(nums)
    print nums
        

