class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<int> v1;
        vector<int> v2;
        
        string st = "";
        for(int i=0;i<version1.length();i++){
            if(version1[i]=='.'){
                v1.push_back(stoi(st));
                st = "";
            }else{
                st += version1[i];
            }
        }
        if(st!=""){
           v1.push_back(stoi(st)); 
        }
        st = "";
        
        for(int i=0;i<version2.length();i++){
            if(version2[i]=='.'){
                v2.push_back(stoi(st));
                st = "";
            }else{
                st += version2[i];
            }
        }
        if(st!=""){
           v2.push_back(stoi(st)); 
        }

        int i =0;
        for(i=0;i<v1.size()&&i<v2.size();i++){
            if(v1[i]<v2[i]){
                return -1;
            }else if(v1[i]>v2[i]){
                return 1;
            }
        }
        
        while(i<v1.size()){
            if(v1[i]>0){
                return 1;
            }
            i++;
        }
        while(i<v2.size()){
            if(v2[i]>0){
                return -1;
            }
            i++;
        }
        return 0;

    }
};