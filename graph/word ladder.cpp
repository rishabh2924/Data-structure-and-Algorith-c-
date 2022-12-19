#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> dict(wordList.begin(),wordList.end());
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord){
                return step;
            }
             dict.erase(word);
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(dict.find(word)!=dict.end()){
                        q.push({word,step+1});
                       
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};