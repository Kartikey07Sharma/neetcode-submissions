class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end()); 
        if(beginWord == endWord)return 0;
        queue<pair<string, int>> q;  
        q.push({beginWord, 1});
        s.erase(beginWord);
        while(!q.empty())
        {
            auto x = q.front();
            string word = x.first;
            int step = x.second;
            q.pop();
            if(word == endWord){
                return step;
            }
            for(int i=0; i<word.size(); i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(s.find(word) != s.end())
                    {
                        s.erase(word);
                        q.push({word, step + 1});
                    }
                    word[i] = original;   
                }
            }
        }
        return 0;
    }
};
