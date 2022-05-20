#include <iostream>
#include <vector>

class matrix2vector
{
    public:
        int depth, rows, cols;
        int size_1d;
        std::vector<int> * vector_1d;
        std::vector<std::vector<std::vector<int>>> * vector_3d;
        
        
        matrix2vector(int n, int m, int p)
        {
            depth = n;
            rows = m;
            cols = p;
            size_1d = n * m * p;
            vector_1d = new std::vector<int>(size_1d,0);
            vector_3d = new std::vector<std::vector<std::vector<int>>>(depth, std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0)));
        }
        
        void initalize_matrix()
        {
            for(int i=0;i<depth;i++)
            {
                for(int j=0;j<rows;j++)
                {
                    for(int k=0;k<cols;k++)
                    {
                        std::cout<<"Enter value at "<<i << " "<<j << " "<< k << "\n";
                        int value;
                        std::cin>>value;
                        (*vector_3d)[i][j][k] = value;
                        int index = get_index(i, j, k);
                        (*vector_1d)[index] = value;
                    }     
                }   
            }
        }
        
        void initalize_matrix_with_same_value(int value)
        {

            for(int i=0;i<depth;i++)
            {
                for(int j=0;j<rows;j++)
                {
                    for(int k=0;k<cols;k++)
                    {
                        (*vector_3d)[i][j][k] = value;
                        int index = get_index(i, j, k);
                        (*vector_1d)[index] = value;
                    }     
                }   
            }
        }

        void print_matrix()
        {
            std::cout<<"---------------:3D Matrix:------------------ \n";
            for(int i=0;i<depth;i++)
            {
                for(int j=0;j<rows;j++)
                {
                    for(int k=0;k<cols;k++)
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

        int get_element_value_from_3d_matrix(int i, int j, int k)
        {
            return (*vector_3d)[i][j][k];
        }

        int get_element_value_from_1d_vector(int i, int j, int k)
        {
            int index = get_index(i, j, k);
            return (*vector_1d)[index];
        }

        int get_index(int i,int j,int k){
            return ((i*rows*cols) + (j*cols) + k);
        }
};

int main(void)
{
    int flag = 9;
    int option = 0;
    int n,m,p;
    std::cout<<"3D Matrix Flatter Application:\n";
    std::cout<<"Enter the dimensions of the matrix: ";
    std::cin>>n>>m>>p;
    matrix2vector obj1(n,m,p);
    do
    {
        std::cout<<"----------------------------------------\n";
        std::cout<<"initalize matrix -> (1) \n";
        std::cout<<"initalize matrix with same value -> (2) \n";
        std::cout<<"set value at specific location -> (3) \n";
        std::cout<<"print 3D matrix -> (4) \n";
        std::cout<<"print 1D vector -> (5) \n";
        std::cout<<"1D vector index of 3d matrix location -> (6) \n";
        std::cout<<"get element from matrix -> (7) \n";
        std::cout<<"get element from vector -> (8) \n";
        std::cout<<">> ";
        
        std::cin>>option;
        if(option == 1)
        {
            std::cout<<"----------------------------------------\n";
            std::cout<<"Initalize Matrix: \n";
            obj1.initalize_matrix();        
        }
        else if (option == 2)
        {
            std::cout<<"----------------------------------------\n"; 
            std::cout<<"Enter Value: ";       
            int value;
            std::cin>>value;
            obj1.initalize_matrix_with_same_value(value);
        }
        else if (option == 3)
        {
            std::cout<<"----------------------------------------\n"; 
            int i,j,k,value;
            std::cout<<"Enter location indices i, j, k :";
            std::cin>>i>>j>>k;
            std::cout<<"Enter Value: ";
            std::cin>>value;
            obj1.set_value(i,j,k,value);
        }
        else if (option == 4)
        {
            std::cout<<"----------------------------------------\n"; 
            obj1.print_matrix();
        }
        else if (option == 5)
        {
            std::cout<<"----------------------------------------\n"; 
            obj1.print_vector();        
        }
        else if (option == 6)
        {
            std::cout<<"----------------------------------------\n"; 
            int i,j,k;
            std::cout<<"Enter location indices i, j, k : ";
            std::cin>>i>>j>>k;
            std::cout<<"The index in 1D vector -> "<<obj1.get_index(i,j,k)<<"\n";
        }
        else if (option == 7)
        {
            std::cout<<"----------------------------------------\n"; 
            int i,j,k;
            std::cout<<"Enter location indices i, j, k : ";
            std::cout<<"The element at index "<<i<<" "<<j<<" "<<k << " : "<<obj1.get_element_value_from_3d_matrix(i,j,k);
        }
        else if (option == 8)
        {
            std::cout<<"----------------------------------------\n"; 
            int i,j,k;
            std::cout<<"Enter location indices i, j, k : ";
            std::cout<<"The element at index "<<i<<" "<<j<<" "<<k << " : "<<obj1.get_element_value_from_1d_vector(i,j,k);
        }
        std::cout<<"----------------------------------------\n";   
        std::cout<<"To continue -> (9) \n";
        std::cout<<"To exit -> (0) \n";
        std::cout<<">> ";
        std::cin>>flag;     
    }
    while(flag == 9);

    return 0;
}