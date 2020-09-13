#include <iostream>
#include <cmath>

//#include <Eigen/Core>
//#include<Eigen/Geometry>

#include <eigen3/Eigen/Core>
#include<eigen3/Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main()
{
    /* 3D 旋转矩阵使用Matrix3d或者Matrix3f */
    Matrix3d rotation_matrix = Matrix3d::Identity();

    /* 旋转向量使用角轴，绕Z轴旋转45度 */
    AngleAxisd rotation_vector(M_PI/4, Vector3d(0,0,1));

    /* 设置输出精度 */
    cout .precision(3);
    
    /* 旋转向量转换为旋转矩阵 */
    cout<<"rotation_matrix =\n"<<rotation_vector.matrix()<<endl;
    rotation_matrix = rotation_vector.toRotationMatrix();
    cout<<"rotation_matrix=\n"<<rotation_matrix<<endl;

    /* 使用角轴AngleAxisd 进行坐标变换 */
    Vector3d v (1,0,0);
    Vector3d v_rotated = rotation_vector * v;
    cout<<"(1,0,0) after rotation use rotation vector="<<v_rotated.transpose()<<endl;

    /* 使用旋转矩阵*/
    v_rotated = rotation_matrix * v;
    cout<<"(1,0,0) after rotation use rotation matrix="<<v_rotated.transpose()<<endl;

    /* 旋转矩阵转换为欧拉角 */
    Vector3d euler_angles = rotation_matrix.eulerAngles(2,1,0);//ZYX顺序
    cout<<"yaw pitch roll="<<euler_angles.transpose()<<endl;

    /* 欧式变换使用Isometry */
    Isometry3d  T_ometry = Isometry3d::Identity();
    T_ometry.rotate(rotation_vector);
    T_ometry.pretranslate(Vector3d(1,3,4));
    cout<<"Transform matrix(ometry)=\n"<<T_ometry.matrix()<<endl;

    Vector3d v_transformed = T_ometry*v;
    cout<<"v transformed(ometry)="<<v_transformed.transpose()<<endl;

    /* 防射变换使用Affine */
    Affine3d  T_affine = Affine3d::Identity();
    T_affine.rotate(rotation_vector);
    T_affine.pretranslate(Vector3d(1,3,4));
    cout<<"Transform matrix(Affine)=\n"<<T_affine.matrix()<<endl;

    v_transformed = T_affine*v;
    cout<<"v transformed(Affine)="<<v_transformed.transpose()<<endl;

    /* 投影变换使用Projective*/
    Projective3d  T_projective = Projective3d::Identity();
    T_projective.rotate(rotation_vector);
    T_projective.pretranslate(Vector3d(1,3,4));
    cout<<"Transform matrix(projective)=\n"<<T_projective.matrix()<<endl;

    //v_transformed = T_projective*v;
    //cout<<"v transformed(Affine)="<<v_transformed.transpose()<<endl;

    /* 四元数*/
    Quaterniond q= Quaterniond(rotation_vector);//使用旋转向量初始化
    cout<<"Quaterniond=\n"<<q.coeffs().transpose()<<endl; //coeffs的顺序是(x,y,z,w),其中w是实部

    q=Quaterniond(rotation_matrix); //使用旋转矩阵初始化
    cout<<"Quaterniond=\n"<<q.coeffs().transpose()<<endl; //coeffs的顺序是(x,y,z,w),其中w是实部

    v_rotated =q*v;//使用四元数重载一个向量，数学上 是qvq(-1)
    cout<<"(1,0,0) after rotation(quaternion)="<<v_rotated.transpose()<<endl;


    return 0;
}

