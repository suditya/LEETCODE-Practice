class Solution {
public:
    vector<int> minOperations(string boxes) 
    {   
        int n=boxes.size();
        vector<int> ans;
        vector<int> box;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1')
                box.push_back(1);
            else
                box.push_back(0);
        }
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if((i!=j) and box[j]==1)
                    sum=sum+abs(i-j);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};