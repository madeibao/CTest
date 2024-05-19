
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    stack<int> st;
    map<string,int> mp;
    string reverse(string f)
    {
        string str = "";
        int len = f.length();	
        for(int i = len - 1; i >= 0; i--){
            str += f[i];	
        }
        return str;
    }
    string countOfAtoms(string fomula)
    {
        int len = fomula.length();
        string f = "";
        while(len > 0){
            if(fomula[len - 1]>='0' && fomula[len - 1]<='9') {
                if(fomula[len]>='0' && fomula[len]<='9')	{
                    int i = st.top();
                    st.pop();
                    int tmp = (fomula[len - 1] - '0')*10;
                    if(!st.empty()){
                        int i2 = st.top();
                        tmp *= i2;
                    }
                    tmp += i;
                    st.push(tmp);
                }	
                else{
                    int tmp = fomula[len - 1] - '0';
                    if(!st.empty()){
                        int i = st.top();
                        tmp *= i;
                    }
                    st.push(tmp);
                }		
            }
            else if(fomula[len - 1]>='A' && fomula[len - 1] <= 'Z'){
                if(len == fomula.length() || ( fomula[len] >= 'A' && fomula[len] <= 'Z') || fomula[len] == ')' || fomula[len] == '('){
                    if(!st.empty()){
                        int i = st.top();
                        st.push(i);			
                    }				
                    else
                        st.push(1);	
                }
                f += fomula[len - 1];
                f = reverse(f);
                int i = st.top();
                st.pop();
                if(mp.find(f) != mp.end()){
                    mp.find(f)->second += i;			
                }else
                    mp.insert(make_pair(f,i));
                f = "";
            }	
            else if(fomula[len - 1]>='a' && fomula[len - 1] <= 'z'){
                if(len == fomula.length() || (fomula[len] >= 'A' && fomula[len] <= 'Z') || fomula[len] == ')' || fomula[len] == '('){
                    if(!st.empty()){
                        int i = st.top();
                        st.push(i);			
                    }				
                    else
                        st.push(1);
                }
                f += fomula[len - 1];
            }
            else if(fomula[len-1] == '('){
                if(!st.empty())
                    st.pop();
            }
            len--;
        }


        map<string,int>::iterator it;
        string result = "";

        for(it = mp.begin(); it != mp.end(); it++){
            if(it->second <= 1){
                result += it->first;
            }		
            else{
                result += it->first;
                result += to_string(it->second);			
            }
        }

        return result;
    }
};



int main() {


    string formula = "Mg(OH)2"
    Solution s2;
    cout<<s2.countOfAtoms(formula)<<endl;
    return 0;
}