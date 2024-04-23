public class Solution {
    public bool IsPalindrome(string s) {
        List<char> list = new List<char>();
        s = s.ToLower();
        for(int i = 0; i<s.Length; i++){
            char c = s[i];
            if((c>='a' && c<='z') || (c>='0' && c<='9'))list.Add(c);
        }

        for(int i = 0; i<list.Count/2;i++){
            if(list[i]!=list[list.Count-i-1]) return false;
        } 
        return true;
    }
}