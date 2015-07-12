class Solution:
    def compare(self, a, b):
        return [1,-1][a+b > b+a]

    def largestNumber(self, nums):
        nums_list = []
        for n in nums:
            nums_list.append(str(n))

        nums_list=sorted(nums_list, cmp=self.compare)
        return "".join(nums_list).lstrip("0") or "0"

if __name__ == "__main__":
    nums = [3,30,34,5,9]
    s = Solution()
    print s.largestNumber(nums)
