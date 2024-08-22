#include<bits/stdc++.h>
using namespace std;
class Solution {
unordered_map<string, unordered_set<string>> list;
vector<vector<string>> ans;
int shortest;

public:
    void dfs(string node, string &endWord, vector<string> &path, unordered_map<string, bool> &vis)
    {
        //
        vis.insert({node, 1});
        // path.push_back(node);
        if (node == endWord)
        {
            if(path.size() == shortest)
                ans.push_back(path);
            // cout << cnt << " : ";
            // for (string &word : path)
            // {
            //     cout << word << " ";
            // }
            return;
        }
        for (string const& Word : list[node])
        {
            if (vis.find(Word) == vis.end())
            {
                // vis.insert({Word, 1});
                
                path.push_back(Word);
                // path.push_back
                dfs(Word, endWord, path, vis);
                vis.erase(Word);
                path.pop_back();
            }
        }
        // path.pop_back();
        // return;
    }
// vector<int> v;
public:
    vector<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {


        list.clear();
        ans.clear();
        unordered_set<string> s;
        s.insert(beginWord);
        for(string& word : wordList){
            s.insert(word);
        }
        // do for begin word
        int n = wordList.size();
        for(int i = -1; i < n; i++){
            string word;
            if(i == -1){
                word = beginWord;
            }
            else{
                word = wordList[i];
                
            }
            for(int j = 0; j < word.size(); j++){
                string newword = word;
                for(int k = 0; k < 26; ++k){
                    newword[j] = char('a'+k);
                    if(s.find(newword) != s.end()){
                        list[word].insert(newword);
                    }
                    newword = word;
                }
            }
        }
        unordered_map<string, int> d;
        queue<string> q;
        q.push(beginWord);
        d.insert({beginWord, 1});
        while(!q.empty()){
            string front = q.front();
            q.pop();
            for(string const& word: list[front]){
                if(d.find(word) == d.end()){
                    q.push(word);
                    d.insert({word, d[front]+1});
                }
            }
        }
        if(d.find(endWord) == d.end())
            return ans;
        shortest = d[endWord];
        // Print all possible paths from src to target
        vector<string> path;
        path.push_back(beginWord);
        unordered_map<string, bool> vis;
        // int cnt = 1;
        dfs(beginWord, endWord, path, vis);

        return ans;
        
    }
};

int main(){

    Solution obj;
    // obj.ladderLength
    vector<string> wordl = {"a","b","c"};
    
    vector<vector<string>> res = obj.ladderLength("a", "c", wordl);

    for(vector<string> v: res){
        for(string word : v){
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}