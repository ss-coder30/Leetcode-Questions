class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int i,j,y=0;
    for(i=0;i<sentences.size();i++){
        string t=sentences[i];
        int j=0;
        int z=0;
        while(j<t.size()){
          if(t[j]==' '){
              z++;
              j++;
          }
          j++;
        }
        if(z>y){
            y=z;
        }
        }
    
  return y+1;
    }
};