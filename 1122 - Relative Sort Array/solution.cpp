class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_map<int, int> freq;

        for(const int& i : arr1)
            freq[i]++;

        vector<int> ans;

        for(int i = 0 ; i < arr2.size() ; i++)
            for(int j = 0 ; j < freq[arr2[i]] ; j++)
                ans.push_back(arr2[i]);

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        for(int i = 0 ; i < arr1.size() ; i++)
            if(!binary_search(arr2.begin(), arr2.end(), arr1[i]))
                ans.push_back(arr1[i]);

        return ans;
    }
};