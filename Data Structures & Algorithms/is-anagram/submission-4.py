class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count_char = {}
        
        for ch in s:
            if ch not in count_char:
                count_char[ch]=1
            else:
                count_char[ch]+=1

        for ch in t:
            if ch not in count_char:
                return False
            
            count_char[ch]-=1

        for count in count_char.values():
            
            if (count!=0):
                return False

        return True
        