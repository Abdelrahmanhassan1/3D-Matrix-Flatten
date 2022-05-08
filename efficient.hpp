#include <bits/stdc++.h>


int get_index(int i, int j,int k,int Width,int Height){
    return ((i*Width*Height) + (j*Height) + k);
}

std::vector<int> efficient_matrix_flatter(std::vector<std::vector<std::vector <int>>> matrix)
{
    std::vector<int> vector_1d;
    int depth = matrix.size(); 
    int height = matrix[0].size(); 
    int width = matrix[0][0].size();
    int i = 0 , j = 0, k = 0;
    for(int i=0;i<depth;i++)
    {
        for(int j=0;j<height;j++)
        {
            for(int k=0;k<width;k++)
            {
                int index = get_index(i, j, k, width, height);
                // what to do here ?
            }
        }
    }
    return vector_1d;

}























// while(k < depth)
//         {
//         j = 0;
//         while(j < height)
//             {
//             i = 0;
//             while(i < width)
//                 {
//                  flattened_matrix.push_back(matrix[k][j][i]);
//                 i++;
//                 }
//             j++;
//             }
//         k++;
//         }    