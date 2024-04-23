public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var dict = new Dictionary<string, IList<string>>();

        foreach(var str in strs){
            var key = GetHashKey(str);
            if(dict.TryGetValue(key, out var value))
                value.Add(str);
            else
                dict.Add(key, new List<string> {str});
        }
        return dict.Values.ToList();
    }

    private string GetHashKey(string s){
        var key = new char[26];
        foreach(var letter in s)
            key[letter - 'a']++;
        return new string(key);
    }
}