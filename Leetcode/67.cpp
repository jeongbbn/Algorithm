class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int maxx= max((int)a.size(), (int)b.size());
        int bfr = 0;
        string tmp = "";
        for(int i=0; i<maxx; i++){
            int l = 0, r = 0;
            if(a.size() > i) l = a[i] - '0';
            if(b.size() > i) r = b[i] - '0';
            
            int sum = l+r+bfr;
            
            bfr = sum / 2;
            sum %= 2;
            tmp += to_string(sum);
        }
        
        
        if(bfr == 1) tmp += "1";
        reverse(tmp.begin(), tmp.end());
        
        return tmp;
    }
};
