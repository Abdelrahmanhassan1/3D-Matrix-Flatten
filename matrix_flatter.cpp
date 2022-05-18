#include <iostream>
#include <vector>

class matrix2vector
{
    public:
        int depth, width, height;
        int size_1d;
        std::vector<int> * vector_1d;
        std::vector<std::vector<std::vector<int>>> * vector_3d;
        
        
        matrix2vector(int n, int m, int p)
        {
            depth = n;
            width = m;
            height = p;
            size_1d = n * m * p;
            vector_1d = new std::vector<int>(size_1d,0);
            vector_3d = new std::vector<std::vector<std::vector<int>>>(depth, std::vector<std::vector<int>>(width, std::vector<int>(height, 0)));
        }
        void initalize_matrix()
        {
            for(int i=0;i<depth;i++)
            {
                for(int j=0;j<height;j++)
                {
                    for(int k=0;k<width;k++)
                    {
                        int value;
                        std::cin>>value;
                        (*vector_3d)[i][j][k] = value;
                        int index = get_index(i, j, k);
                        (*vector_1d)[index] = value;
                        std::cout<<"index"<<index<<" ";
                    }     
                }   
            }
        }

        void print_matrix()
        {
            std::cout<<"---------------:3D Matrix:------------------ \n";
            for(int i=0;i<depth;i++)
            {
                for(int j=0;j<height;j++)
                {
                    for(int k=0;k<width;k++)
                    { 
                        std::cout << (*vector_3d)[i][j][k] << " ";
                    }   
                    std::cout<<"\n";
                }
                std::cout<<"\n";
            }
            std::cout<<"----------------------------------------\n";
        }

        void set_value(int i, int j, int k, int value)
        {
            int index = get_index(i, j, k);
            (*vector_3d)[i][j][k] = value;
            (*vector_1d)[index] = value;
        }

        void print_vector()
        {
            std::cout<<"--------------:1D Vector:---------------- \n";
            for(int i = 0 ; i < size_1d; i++)
            {
                std::cout<<(*vector_1d)[i]<<" ";
            }
            std::cout<<"\n";
            std::cout<<"----------------------------------------\n";

        }

        int get_index(int i,int j,int k){
            return ((i*width*height) + (j*height) + k);
        }
};

int main(void)
{
    matrix2vector obj1(5,3,2);
    obj1.initalize_matrix();
    // obj1.set_value(0,0,1, 20);
    obj1.print_matrix();
    obj1.print_vector();
    return 0;
}