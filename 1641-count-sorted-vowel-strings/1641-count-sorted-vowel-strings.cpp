class Solution {
public:
    
    int countVowelString(int n, int vowels){
        if(n == 1) return vowels;
        if(vowels == 1) return 1;
        
        return countVowelString(n-1, vowels) + countVowelString(n, vowels-1);
    }
    
    int countVowelStrings(int n) {
        
        return countVowelString(n, 5);
    }
};