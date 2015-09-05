class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        lcs = [i-j for i, j in zip(gas, cost)]
        sum_temp = 0
        index = 0
        max_temp = -3333
        for i in range(len(lcs)):
            sum_temp += lcs[i]
            if sum_temp < 0:
                index = i+1
                sum_temp = 0
            if sum_temp > max_temp:
                max_temp = sum_temp

        max_temp = lcs[j]
        if max_temp < 0:
            return -1
        j = (index+1) % len(lcs)
        while j != index :
            max_temp += lcs[j]
            print j, max_temp
            if max_temp < 0:
                return -1
            j = (j+1) % len(lcs)
        
        return index


if __name__ == "__main__":
    s = Solution()
    print s.canCompleteCircuit([6,1,4,3,5], [3,8,2,4,2])
