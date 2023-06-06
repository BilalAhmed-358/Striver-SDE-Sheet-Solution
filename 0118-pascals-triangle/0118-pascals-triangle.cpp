class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        // Creating a pascal triangle 2D vector
        vector<vector<int>> pascal_triangle;
        
        
        // pushing empty vectors in the pascal triangle
        for( int i=0;i<numRows;i++)
        {
            vector<int> temp(i+1,0);
            pascal_triangle.push_back(temp);
            temp.clear();
        }
        
        // assigning 1s to the first and last element of each row
        
        for(int i=0;i<numRows ; i++)
        {
                pascal_triangle[i][0]=1;
                pascal_triangle[i][i]=1;  
        }
        
        
        // now entering values in other non-one elements of the pascal triangle
        
    if(numRows > 2)
    {
        for(int i=0;i<numRows;i++)
        {
            for(int j=1; j<pascal_triangle[i].size()-1 ;j++)
            {
                
                pascal_triangle[i][j]=pascal_triangle[i-1][j-1]+pascal_triangle[i-1][j];
                
            }
        }   
    }
        
        
    return pascal_triangle;
    }
};