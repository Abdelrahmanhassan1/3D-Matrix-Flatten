#include <bits/stdc++.h>
#include "naive.hpp"
#include "efficient.hpp"

int ARRAY_SIZE = 100;

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
        
        /*************** if want to show the 3d matrix **************************/

        // int depth = matrix3d.size(); 
        // int height = matrix3d[0].size(); 
        // int width = matrix3d[0][0].size();
        //  for(int i=0;i<depth;i++)
        //     {
        //         for(int j=0;j<height;j++)
        //         {
        //             for(int k=0;k<width;k++)
        //             {
        //                 std::cout<<matrix3d[i][j][k]<<" ";
        //             }
        //             std::cout<<std::endl;
        //         }
        //         std::cout<<std::endl;
        //     }
        /***********************************************************************/


        std::vector<int> naive_result, efficient_result;

        auto naive_start = std::chrono::high_resolution_clock::now();
        naive_result = naive_matrix_faltter(matrix3d);
        auto naive_finish = std::chrono::high_resolution_clock::now();

        auto efficient_start = std::chrono::high_resolution_clock::now();
        efficient_result = efficient_matrix_flatter(matrix3d);
        auto efficient_finish = std::chrono::high_resolution_clock::now();

        auto naive_time = (naive_finish - naive_start).count();
        auto efficient_time = (efficient_finish - efficient_start).count();

        // if (efficient_result == naive_result)
        // {
        std::cout<<"depth: "<<matrix3d.size()<<" height: " << matrix3d[0].size() << " width: " << matrix3d[0][0].size() <<std::endl;
        std::cout << "equivalent ";
        std::cout << " naive_time ==> " << naive_time;
        std::cout << " efficient_time ==> " << efficient_time;
        std::cout << " performance enhancment ==> " << float(naive_time) / efficient_time << std::endl;
        // }
        // else
        // {
        //     cout << "error, check your inputs and algortihms " << endl;
        //     break;
        // }
    }
    return 0;
}