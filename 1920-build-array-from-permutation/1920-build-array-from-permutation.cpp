class Solution {
public:
    vector<int> buildArray(vector<int>& a) 
    {
        vector<int> arranged(a.size());
        for(int i=0;i<a.size();i++)
        {
            arranged[i]=a[a[i]];
        }
        return arranged;
    }
};