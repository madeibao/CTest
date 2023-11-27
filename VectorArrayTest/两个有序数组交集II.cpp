
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	int lena = nums1.size();
    	int lenb = nums2.size();

		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
    	int i =0, j=0;

    	vector<int> result;

    	while(i < lena && j<lenb) {
    		if(nums1[i] < nums2[j]) {
    			i++;
    		}
    		else if(nums1[i] > nums2[j]) {
    			j++;
    		}
    		else {
    			result.push_back(nums1[i]);
    			i++;
    			j++;
    		}
    	}

    	return result;
    }

};