class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        len_s = len(nums)
        max= 0
        for num in nums:
            if abs(num) > max:
                max = abs(num)
                
        abs_target = abs(target)
        if abs_target>max:
            max = abs_target
        
        max_1 = max+1
        flag = [0 for x in range(max_1)]
        index_pos = [max_1 for x in range(max_1)]
        index_minus = index_pos[:]
        
        result = []
        len_s = len(nums)
        for i in range(len_s):
            abs_temp = abs(nums[i])
            abs_rev_temp = abs(abs_target- abs_temp)
            if flag[abs_temp] == 0 and flag[abs_rev_temp] == 0:
                flag[abs_temp] = 1
                
                if nums[i] >0:
                    index_pos[abs_temp] = i
                else:
                    index_minus[abs_temp] = i
            
            else:
                if index_pos[abs_temp] != max_1:
                    if nums[i] + nums[index_pos[abs_temp]] == target:
                        result.append(index_pos[abs_temp] +1)
                        result.append(i+1)
                        break
                        
                if index_minus[abs_temp] != max_1:
                    if nums[i] + nums[index_minus[abs_temp]] == target:
                        result.append(index_minus[abs_temp] +1)
                        result.append(i+1) 
                        break
            
                if index_pos[abs_rev_temp] != max_1:
                    if nums[i] + nums[index_pos[abs_rev_temp]] == target:
                        result.append(index_pos[abs_rev_temp] +1)
                        result.append(i+1)
                        break
                        
                if index_minus[abs_rev_temp] != max_1:
                    if nums[i] + nums[index_minus[abs_rev_temp]] == target:
                        result.append(index_minus[abs_rev_temp] +1)
                        result.append(i+1)
                        break
                    
        return result