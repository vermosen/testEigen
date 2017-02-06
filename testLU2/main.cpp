#include <iostream>
#include <Eigen/Dense>

#include <boost/chrono.hpp>

using namespace boost::chrono;
high_resolution_clock::time_point start;

int main()
{
	typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrixRhs;
	typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrixLhs;

	matrixRhs m = matrixRhs::Random(1000, 600);
	
	start = high_resolution_clock::now();
	{
		Eigen::FullPivLU<matrixRhs> lu(m);
		matrixRhs res = lu.matrixLU();
	}
	
	std::cout	<< "Test realized in " 
				<< duration_cast<milliseconds>(high_resolution_clock::now() - start) 
				<< std::endl;

	system("pause");
	return 0;
}
