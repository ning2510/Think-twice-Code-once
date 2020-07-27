class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        nums.insert(0, int(-1e5 - 5))
        nums.insert(len(nums), int(1e5))

        flag = False
        for i in range(1, len(nums) - 2):
            if nums[i] > nums[i + 1]:
                if nums[i] <= nums[i + 2] or nums[i - 1] <= nums[i + 1]:
                    if flag:
                        return False
                    flag = True
                else:
                    return False

        return True