class Solution {
public:

    string sortSentence(string s) {
    map<int,string>mp;
    string s1="";
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
         mp[int(s[i])]=s1;
         s1="";
        }
        else if(s[i]!=' ')
        {
            s1+=s[i];
        }
    }
    string f="";
    for(auto x:mp)
    {
        f+=x.second;
        f+=' ';
    }
    f.pop_back();
    return f;
    }
};