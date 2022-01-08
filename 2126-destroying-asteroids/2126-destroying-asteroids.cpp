class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        unsigned long long int  current_mass=mass;
        cout<<current_mass<<" ";
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        for(int i=0;i<n;i++)
        {
            if(current_mass >= asteroids[i])
            {
                current_mass+=asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};