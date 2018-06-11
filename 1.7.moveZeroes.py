#64ms
class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        j=0
        for i in range(len(nums)):
            if nums[i-j] == 0:
                nums.pop(i-j)
                nums.append(0)
                j+=1
                
#163ms        
class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in range(nums.count(0)):
            nums.remove(0)
            nums.append(0)
