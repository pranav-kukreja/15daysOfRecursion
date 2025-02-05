// ques -> https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution {
public:
    void f(string& t, int i,int& n,int& ans,bool& isNeg){
        if(i==t.size()) {
            if(isNeg && ans>0) ans*=-1;
            return;
        }
        cout<<i<<" ";
        if(float(ans)<((INT_MAX)/10.0) ||( !isNeg&& ans==INT_MAX/10 && t[i]<='7') || (isNeg&& ans==INT_MAX/10 && t[i]<='8'))
        {
            cout<<" going further"<<endl;
            if(isNeg && ans==INT_MAX/10){
                 ans*=-10; ans-=(t[i]-'0');  
            }
            else {
                ans=ans*10;
                ans+=(t[i]-'0');
            }
            f(t,i+1,n,ans,isNeg);
        }
        else{
            cout<<"possible overflow -> terminating"<<endl;
            if(isNeg) ans=INT_MIN;
            else ans=INT_MAX; 
            return;
        }
    }
    int myAtoi(string s) {
        int i=0, n=s.size();
        bool isNegativeNum=false; bool& isNeg=isNegativeNum;
        string t="";
        while(i<n && s[i]==' ') i++;
        if(i==n) return 0;
        if(s[i]=='-'){
            isNegativeNum= true; i++;
        }
        else if (s[i]=='+') i++;
        while(i<n && s[i]=='0') i++;
        if(i==n) return 0;
        while(i<n && s[i]<='9' && s[i]>='0') {
            t.push_back(s[i]); i++;
        }   
        int ans=0,l=t.size();
        if(t.size()>10){
            if(isNeg) return INT_MIN;
            else return INT_MAX;
        }
        f(t,0,l,ans,isNegativeNum);
        return ans;
    }
};
