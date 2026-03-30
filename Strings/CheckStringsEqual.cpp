#include<iostream>
using namespace std;

class Solution{
    public:
    bool checkStrings(string s1, string s2){
        int n=s1.size();
        int Evens[26] = {0};
        int Odds[26] = {0};
                
        for(int i=0;i<n;i++){
            if(i%2==0){
                Evens[s1[i]-'a']++;
                Evens[s2[i]-'a']--;
            }else{
                Odds[s1[i]-'a']++;
                Odds[s1[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(Evens[i] != 0 || Odds[i] != 0) return false;
        }
        return true;
    }
    
};


int main(){
    Solution sol;
    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    if(sol.checkStrings(s1, s2)){
        cout<<"True s1 can be made equal to s2";
    }else{
        cout<<"s1 can not be made equal to s2";
    }
    return 0;
}