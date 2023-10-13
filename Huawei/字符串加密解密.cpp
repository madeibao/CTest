



#include<iostream>
#include<string>
using namespace std;

void Enpt(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] >='a' && s[i]<='z'){
            s[i] = (s[i]-'a'+1)%26+'A';
        }
        else if(s[i]>='A' && s[i]<='Z'){
            s[i] =(s[i]-'A'+1)%26+'a';
        }
        else if(s[i]>='0' && s[i]<='9'){
            s[i]= (s[i]-'0'+1)%10+'0';
        }
    }
    cout<<s<<endl;
}

void unEnpt(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] >='a' && s[i]<='z'){
            s[i] = (s[i]-'a'+25)%26+'A';
        }
        else if(s[i]>='A' && s[i]<='Z'){
            s[i] =(s[i]-'A'+25)%26+'a';
        }
        else if(s[i]>='0' && s[i]<='9'){
            s[i]= (s[i]-'0'+9)%10+'0';
        }
    }
    cout<<s<<endl;
}

int main(){

    string s1,s2;
    while(cin>>s1){
        cin>>s2;
        Enpt(s1);
        unEnpt(s2);
    }
    return 0;
}
