class Solution {
public:
    string getHint(string secret, string guess) {
        int b = 0, c = 0;
        vector<char> notin;
        unordered_map<char, int> mps, mpg;


        for(int i = 0;i<secret.length();i++)
        {
            if(secret[i] == guess[i]) {
                b++;
                continue;
            }

            if(mps.find(secret[i]) == mps.end()) mps[secret[i]] = 1;
            else mps[secret[i]]++;

            if(mpg.find(guess[i]) == mpg.end()) mpg[guess[i]] = 1;
            else mpg[guess[i]]++;
            
        }
        for(auto i : mpg) cout<<i.first<<" "<<i.second<<endl;
        // cout<<endl;
        for(auto p : mpg)
        {
            if(mps.find(p.first)!= mps.end())
            {
                // cout<<p.second<<" "<<mps[p.first]<<endl;
                c+= p.second<mps[p.first]?p.second:mps[p.first];
            }
        }

        
        string Bb = "", Cc = "";
        Bb+=to_string(b);
        Cc+=to_string(c);
        return Bb+"A"+Cc+"B";
    }
};
