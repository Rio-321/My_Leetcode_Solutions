class Solution {
public:
    
    void swap(int &a, int &b, int &c, int &d)
    {
        int temp = d;
        d = c;
        c = b;
        b = a;
        a = temp;
    }
    

    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int T = 0,B=n-1,L=0,R=n-1;
       while(T<=B && L<=R)
        {
            for(int i=L;i<R;i++)
            {
                swap(matrix[T][i], matrix[T+i-L][R], matrix[B][R-i+L],matrix[B-i+L][L]);
            } 
            
            L++;
            T++;
            B--;
            R--;
        }
            
        return; 
        
    }
};