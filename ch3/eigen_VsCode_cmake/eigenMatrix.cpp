#include <iostream>
#include <ctime>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

#define MATRIX_SIZE 50

int main(int argc, char *argv[])
{
    Matrix<float, 2, 3,  ColMajor> matrix_23;
    
    Vector3d v_3d;
    
     Matrix3d matrix_33 =  Matrix3d::Zero();
    
     Matrix<double,  Dynamic,  Dynamic> matrix_dynamic;
    
     MatrixXd matrix_x;
    
    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout << "matrix_23:"<<endl;
    cout << matrix_23 << endl;
    
    cout << "matrix_23:" << endl;
    for (int i=0;i<2;++i){
        for (int j=0;j<3;++j){
            cout<<matrix_23(i,j)<<endl;
        }
    }
    
    v_3d << 1, 2,3;
    
     Matrix<double, 2,1> result=matrix_23.cast<double>() * v_3d;
    cout<<"result:"<<endl;
    cout<<result<<endl;
    
    matrix_33 =  Matrix3d::Random();
    cout << "matrix_33:" <<endl;
    cout << matrix_33 <<endl;
    
    cout <<"matrix_33.transpose():"<<matrix_33.transpose() <<endl;
    cout <<"matrix_33.sum():"<<matrix_33.sum()<<endl;
    cout <<"matrix_33.trace():"<<matrix_33.trace()<<endl;
    cout <<"matrix_33 * 10"<<matrix_33 * 10<<endl;
    cout <<"matrix_33.inverse():"<<matrix_33.inverse()<<endl;
    cout<<"matrix_33.determinant():"<<matrix_33.determinant()<<endl;
    
     SelfAdjointEigenSolver< Matrix3d> eigen_slover(matrix_33.transpose()*matrix_33);
    cout<<"eigen_slover.eigenvalues():"<<eigen_slover.eigenvalues()<<endl;
    cout<<"eigen_slover.eigenvectors():"<<eigen_slover.eigenvectors()<<endl;
    
     Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
    matrix_NN =  MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
     Matrix<double, MATRIX_SIZE, 1> v_Nd;
    v_Nd =  MatrixXd::Random(MATRIX_SIZE, 1);
    
    clock_t time_stt=clock();
     Matrix<double, MATRIX_SIZE, 1> x=matrix_NN.reverse()*v_Nd;
    cout<<"time use in normal invers is"<<1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<endl;
    
    time_stt=clock();
    x=matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout<<"time use in Qr compsition is"<<1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<endl;
    
    
    return 0;
}