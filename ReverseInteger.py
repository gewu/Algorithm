class Solution(object):
    def reverse(self, x):
        flag = 1
        if x < 0:
            flag = -1
        x = abs(x)
        strs = str(x)
        num = int("".join((list(strs))[::-1]))*flag
        if num > 2147483647 or num < -2147483648:
            return 0
        return num

if __name__ == "__main__":

