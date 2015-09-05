import string

class Solution(object):
    def isPalindrome(self, s):
        i = 0
        j = len(s)-1

        my_case = "{}{}{}".format(string.lowercase, string.uppercase, string.digits)
        while (i < j):
            if (s[i] in my_case and s[j] in my_case):
                flag = abs(ord(s[i]) - ord(s[j]))
                if (flag != 0 and flag != 32):
                    return False
                i += 1
                j -= 1
            else:
                if s[i] not in my_case:
                    i += 1
                if s[j] not in my_case:
                    j -= 1

        return True

if __name__ == "__main__":
    test_str = "1a2"
    s = Solution()
    print s.isPalindrome(test_str)


