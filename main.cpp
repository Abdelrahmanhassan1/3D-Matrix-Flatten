#include <bits/stdc++.h>
#include "naive.hpp"
#include "efficient.hpp"

int ARRAY_SIZE = 4;

std::vector<std::vector<std::vector <int>>> generate_random_3d_matrix()
{
    srand(time(0));
    std::vector<std::vector<std::vector <int>>> matrix;
    int depth, height, width;
    depth = rand() % ARRAY_SIZE + 1;
    height = rand() % ARRAY_SIZE + 1;
    width = rand() % ARRAY_SIZE + 1;

    for(int i=0;i<depth;i++)
    {
        std::vector<std::vector<int>> v2d;
        for(int j=0;j<height;j++)
        {
            std::vector<int> v1d;
            for(int k=0;k<width;k++)
            {
                v1d.push_back(rand() % 10 + 1);
            }
            v2d.push_back(v1d);
        }
        matrix.push_back(v2d);
    }
    return matrix;
}


int main(int argc, char **argv)
{

    while (true)
    {
        srand(time(0));
        std::vector<std::vector<std::vector <int>>> matrix3d = generate_random_3d_matrix();
        
        
        efficient_matrix_flatter(matrix3d);
        
        std::cout<<"depth: "<<matrix3d.size()<<" height: " << matrix3d[0].size() << " width: " << matrix3d[0][0].size() <<std::endl;
        
    }
    return 0;
}