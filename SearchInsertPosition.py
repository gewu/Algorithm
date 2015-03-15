class Solution:
    def searchInsert(self, A, target):
        min = 0
        max = len(A)-1
        if (max-min <= 1):
            if (target <= A[min]):
                return min
            if (target >= A[max]):
                return max+1
        mid = (min+max)/2
        if (A[mid] == target):
            return mid
        if (A[mid] > target):
            return self.searchInsert(A[:mid], target)
        if (A[mid] < target):
            return (mid+1)+self.searchInsert(A[mid+1:], target)            

if __name__ == "__main__":
	solution = Solution()
	arrint = [1,3,5,6]
	print solution.searchInsert(arrint, 0)
