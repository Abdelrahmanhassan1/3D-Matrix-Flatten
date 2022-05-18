#include <bits/stdc++.h>


// 1 2 3 4
// 1 2 3 4

// 1 2 3 4
// 1 2 4 4

// 1 2 3 4
// 1 2 3 4

// 3 x 4 x 2
// depth x width x height


// width number of elements per row
// height number of rows in one depth 

int get_index(int i, int j,int k,int Width,int Height){
    return ((i*Width*Height) + (j*Height) + k);
}

std::vector<int> naive_matrix_faltter()
{
    std::vector<int> flattened_matrix;
    int depth = 3;
    int height = 1;
    int width = 2;
    for(int i=0;i<depth;i++)
    {
        for(int j=0;j<height;j++)
        {
            for(int k=0;k<width;k++)
            {
                std::cout<<get_index(i,j,k,height,width);
            }
            std::cout<<"\n";   
        }
    }    
    return flattened_matrix;
}

int main(int argc, char **argv)
{
    
    naive_matrix_faltter();
    return 0;
}