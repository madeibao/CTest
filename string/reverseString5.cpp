

class Solution {
public:
    string reverseWords(string s) {

    	int i=0;
    	string res="",temp;

    	while (i < s.length()) {
    		temp = "";
    		while (i < s.size()&&s[i] == ' ') {
    			i++;
    		}
    		while (i < s.size()&&s[i]!=' ') {
    			temp+= s[i++];
    		}
    		if(temp!="") {
    			res= temp+" "+res;
    		}
    	}

    	return res.substr(0,res.length()-1);
    }

};

int main(int argc, char* argv[]) {

	s = "the sky is blue";
	Solution s2;
	cout<<s2.reverseWords(s)<<endl;
	return 0;
}