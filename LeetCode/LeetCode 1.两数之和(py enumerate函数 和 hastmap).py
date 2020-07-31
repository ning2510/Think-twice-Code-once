class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}

        for i, x in enumerate(nums):
            if hashmap.get(target - x) is not None:
                return [i, hashmap.get(target - x)]
            hashmap[x] = i