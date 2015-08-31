class Solution:
    def FindNumsAppearOnce(self, array):
         if (len(array) <= 1):
            reutrn [0,0]
        sum1 = 0;
        flag = 1;
        for a in array:
            sum1 ^= a
        
        sum1 = sum1^(sum1&(sum1-1))
        sum2 = 0
        sum3 = 0
        for n in array:
            if n & sum1 == 0:
                sum2 ^= n
            else:
                sum3 ^= n
        return [sum2, sum3] 


if __name__ == "__main__":
    num_l = [1]
    s = Solution()
    print s.FindNumsAppearOnce(num_l)

