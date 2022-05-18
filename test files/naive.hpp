#include <bits/stdc++.h>

std::vector<int> naive_matrix_faltter(std::vector<std::vector<std::vector <int>>> matrix)
{
    std::vector<int> flattened_matrix;
    int depth = matrix.size(); 
    int height = matrix[0].size(); 
    int width = matrix[0][0].size();
    for(int i=0;i<depth;i++)
    {
        for(int j=0;j<height;j++)
        {
            for(int k=0;k<width;k++)
            {
                flattened_matrix.push_back(matrix[i][j][k]);
            }   
        }
    }    
    return flattened_matrix;
}