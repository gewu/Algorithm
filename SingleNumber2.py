class Solution:
    def singleNumber(self, A):
        dict_a = {}
        for elem in A:
            if dict_a.has_key(elem):
                dict_a[elem] = dict_a[elem] + 1
            else:
                dict_a[elem] = 1

        for (key, value) in dict_a.items():
            if (value == 1):
                return key
        return None

if __name__ == "__main__":
    array_a = {2,2,2,1,3,3,3}
    solution = Solution()
    print solution.singleNumber(array_a)

