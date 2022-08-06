class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        counter1 = {}
        counter2 = {}
        for i in range(26):
            counter1[i+'a']=0
        for i in range(26):
            counter2[i+'26']=0
        for i in range(len(s)):
            counter[s[i]]+=1
        for i in range(len(t)):
            counter[t[i]]+=1
        
        