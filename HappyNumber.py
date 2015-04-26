class Solution:
    def isHappy(self, n):
        numset = set()
        while n != 1:
            sum_n = 0
            for m in str(n):
                sum_n = int(m)*int(m)
            if sum_n in numset:
                return False
            numset.add(sum_n)
            n = sum_n    
        return True


if __name__ == "__main__":
    solution = Solution()
    print solution.isHappy(19)

    
