class Solution {
public:

    void reversestring(string& s,int i,int j){

        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }


    string reverseWords(string s) {
        
        int n = s.length();
        reversestring(s,0,n-1);

        

        for(int i=0;i<n;i++){
            
            if(s[i]==' '){continue;}

            int j=i;
            while(j<n && s[j]!=' '){
                j++;
            }
            reversestring(s,i,j-1);
            i=j;
        }
        
        int i=0,j=0;
        while(i<n && s[i]==' '){
                i++;
        } 
        while(i<n){

           
            while(i<n && s[i]!=' '){
                s[j]=s[i];i++;j++;
            }
            while(i<n && s[i]==' '){
                i++;
            } 
            if(i!=n){
                s[j] = ' ';j++;
            }
        }

        s.resize(j);
        return s;
    }
};