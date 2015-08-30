class Solution:
    def reOrderArray(self, array):
        odd = []
        even = []

        for _ in array:
            if _%2 == 0:
                even.append(_)
            else:
                odd.append(_)
        return odd+even
            
if __name__ == "__main__":
    array = [1,2,3,4,5,6,7]
    s = Solution()
    print s.reOrderArray(array)
