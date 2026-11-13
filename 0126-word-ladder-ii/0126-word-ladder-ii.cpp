class Solution {
public:
 vector<vector<string>>ans;
 unordered_map<string,int>m;
 string b;
 void dfs(string word, vector<string>&seq){
      if(word == b){
         reverse(seq.begin(),seq.end());
         ans.push_back(seq);
         reverse(seq.begin(),seq.end());
         return;
     }
      int steps = m[word];
       for(int i = 0; i<word.size();i++){
                char orig = word[i];
                for(char ch = 'a'; ch <='z';ch++){
                    word[i]=ch;
                    if(m.find(word) != m.end() && steps == m[word] + 1){
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                } 
                word[i] = orig;
            }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        m[beginWord] = 1;
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int steps = m[word];
            q.pop();
            for(int i = 0; i<word.size();i++){
                char orig = word[i];
                for(char ch = 'a'; ch <='z';ch++){
                    word[i]=ch;
                    if(s.find(word) != s.end()){
                        m[word] = steps+1;
                        s.erase(word);
                        q.push(word);

                    }
                } 
                word[i] = orig;
            }
        }
        b = beginWord;
        if(m.find(endWord)!= m.end()){
         vector<string>seq;
         seq.push_back(endWord);
         dfs(endWord,seq);
         
        }

        return ans;
    }
};