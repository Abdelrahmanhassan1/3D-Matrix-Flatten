#include <bits/stdc++.h>

std::vector<int> efficient_matrix_flatter(std::vector<std::vector<std::vector <int>>> matrix)
{
    std::vector<int> flattened_matrix;
    int depth = matrix.size(); 
    int height = matrix[0].size(); 
    int width = matrix[0][0].size();
    int i = 0 , j = 0, k = 0;
    while(k < depth)
        {
        j = 0;
        while(j < height)
            {
            i = 0;
            while(i < width)
                {
                 flattened_matrix.push_back(matrix[k][j][i]);
                i++;
                }
            j++;
            }
        k++;
        }    
    return flattened_matrix;
}