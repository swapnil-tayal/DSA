class Solution:
    def isValid(self, s: str) -> bool:
        return bool(match('(?=.*[aeiou])(?=.*[^\daeiou])\w{3,}$',s,I))