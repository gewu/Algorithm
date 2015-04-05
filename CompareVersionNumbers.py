class Solution:
    def compareVersion(self, version1, version2):
        version1list = version1.split(".")
        version2list = version2.split(".")
        ver1 = 0
        ver2 = 0
        value1 = 1
        value2 = 1
        for elem in version1list:
            ver1 += int(elem)*value1
            value1 = value1 * 0.1
        for elem in version2list:
            ver2 += int(elem)*value2
            value2 = value2*0.1
        if ver1 > ver2:
            return 1
        if ver1 < ver2:
            return -1
        else:
            return 0
if __name__ == "__main__":
            solution = Solution()
            print solution.compareVersion("13.37", "0.1")
            

