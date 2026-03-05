#include <iostream>
#include <vector>
#include <random>

class MatrixCore {
private:
    std::vector<std::vector<int>> matrix;

public:
    MatrixCore(int size){
        std::mt19937 rng(std::random_device{}());
        matrix.resize(size, std::vector<int>(size));

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                matrix[i][j] = rng()%1000;
            }
        }
    }

    int process(){
        int result = 0;

        for(size_t i=0;i<matrix.size();i++){
            for(size_t j=0;j<matrix[i].size();j++){
                result += mix(matrix[i][j], i, j);
            }
        }

        return result;
    }

    int mix(int v,int a,int b){
        int x = v;

        for(int i=0;i<20;i++){
            x = (x + a*11 + b*7) ^ (x << 2);
            x = std::abs(x % 60000);
        }

        return x;
    }

    void rotate(){
        int n = matrix.size();
        std::vector<std::vector<int>> newM(n,std::vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                newM[j][n-1-i] = matrix[i][j];
            }
        }

        matrix = newM;
    }
};