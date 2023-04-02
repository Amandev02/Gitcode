class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(),wordList.end());
        queue<pair<string,int>> words;
        words.push({beginWord,1});
        while(!words.empty()){
            string word = words.front().first;
            int ladder =  words.front().second;
            words.pop();
            if(word==endWord) return ladder;
            list.erase(word);
            for(int i = 0; i<word.length();i++){
                char c = word[i];
                for(int j = 0;j<26;j++){
                    word[i] = 'a'+ j;
                 if(list.find(word)!=list.end()){
                     words.push({word,ladder+1});
                 }
                }
                
                word[i] = c;
            }
            
        }
        
        return  0;
    }
};