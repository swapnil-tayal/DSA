class Solution(object):
    def isCircularSentence(self, s):
        return s[0]==s[-1] and all(s[i-1]==s[i+1] for i in range(1, len(s)-1) if s[i]==' ')
        