class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        if(n1>n2) return false;
        vector<int> count_s1(26,0),count_s2(26,0);
        for(int i=0;i<n1;++i){
            count_s1[s1[i]-'a']++;
            count_s2[s2[i]-'a']++;
        }
        int first=0,last=n1;
        while(last<=n2){
            bool flag=1;
            for(int i=0;i<26;++i){
                if(count_s1!=count_s2){
                    flag=0;
                    break;
                }
            }
            if(flag) return true;
            if(last!=n2){
                count_s2[s2[first]-'a']--;
                count_s2[s2[last]-'a']++;
            }
            first++;
            last++;
        }
        return false;
    }
};