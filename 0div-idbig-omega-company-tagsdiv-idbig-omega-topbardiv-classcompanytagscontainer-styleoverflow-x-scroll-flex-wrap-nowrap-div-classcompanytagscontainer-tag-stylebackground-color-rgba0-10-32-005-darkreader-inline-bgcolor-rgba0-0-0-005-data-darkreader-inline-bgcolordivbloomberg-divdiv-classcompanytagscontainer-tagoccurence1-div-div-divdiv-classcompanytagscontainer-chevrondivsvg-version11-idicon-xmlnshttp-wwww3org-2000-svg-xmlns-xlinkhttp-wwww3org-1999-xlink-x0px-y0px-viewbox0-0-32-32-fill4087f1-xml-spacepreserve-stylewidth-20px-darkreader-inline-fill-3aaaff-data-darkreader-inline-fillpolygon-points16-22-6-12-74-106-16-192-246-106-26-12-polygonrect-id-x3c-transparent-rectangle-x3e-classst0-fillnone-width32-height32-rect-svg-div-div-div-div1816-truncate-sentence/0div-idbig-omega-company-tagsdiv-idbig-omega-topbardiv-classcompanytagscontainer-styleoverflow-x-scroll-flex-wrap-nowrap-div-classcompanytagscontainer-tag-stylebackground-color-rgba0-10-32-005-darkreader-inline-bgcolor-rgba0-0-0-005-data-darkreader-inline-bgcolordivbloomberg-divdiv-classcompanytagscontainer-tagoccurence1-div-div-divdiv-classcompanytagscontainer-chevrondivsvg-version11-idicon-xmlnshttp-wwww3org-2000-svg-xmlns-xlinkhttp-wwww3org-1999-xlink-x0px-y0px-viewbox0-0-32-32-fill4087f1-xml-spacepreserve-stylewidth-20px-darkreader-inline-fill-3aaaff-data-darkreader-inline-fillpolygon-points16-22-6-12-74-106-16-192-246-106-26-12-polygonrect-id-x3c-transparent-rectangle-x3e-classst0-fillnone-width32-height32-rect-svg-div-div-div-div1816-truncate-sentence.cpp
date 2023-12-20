class Solution {
public:
    string truncateSentence(string s, int k) {
    stringstream a(s);
    vector<string> words;
    string word;
    string x="";
    while (a >> word) {
        words.push_back(word);
    }
    for(int i=0;i<k;i++)
    {
       if(i==k-1)
        x.append(words[i]);
        else
        x.append(words[i]+" ");
        
    }
    return x;    
    }
};