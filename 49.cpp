class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        //ordena o anagrama e vai adicionando os que são iguais na mesmo array
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            //add ao map
            mp[word].push_back(x);
        }

        //cria o vetor com as respostas
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};