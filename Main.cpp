#include<eigen3/Eigen/Dense>
#include<iostream>
#include<vector>
#include <ctime>
#include<chrono>
int main(void)
{


    for(int ii=4; ii<=2048; ii*=2)
    {

        Eigen::MatrixXd m = Eigen::MatrixXd::Random(ii,ii);
        const auto start = std::chrono::steady_clock::now();
        Eigen::EigenSolver<Eigen::MatrixXd> solution(m);
        const auto end = std::chrono::steady_clock::now();
        std::complex<double> s = solution.eigenvalues()[0];
        // Eigen::VectorXcd k = solution.eigenvectors().col(0);
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << s << "\n"; // << k.transpose() << std::endl;
        std::cout << elapsed_seconds.count() << '\n';
    }
}
