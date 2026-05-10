#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <iostream>

int main()
{
	float pi = acos(-1.0f);

	float quarterpi = pi / 4.0f;

	std::cout << std:: cos(quarterpi) << std::endl;

	std::cout << std:: sin(quarterpi) << std::endl;

	float c = cos(quarterpi);
	float s = sin(quarterpi);

	Eigen::Vector3f v(2.0f, 1.0f, 1.0f);
	
	Eigen::Matrix3f r;
	r << c, -s, 0.0f,
		s, c, 0.0f,
		0.0f, 0.0f, 1.0f;

	std::cout << r * v << std::endl;

	Eigen::Matrix3f t;
	t << 1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 2.0f,
		0.0f, 0.0f, 1.0f;

	std::cout << t * r * v << std::endl;

	return 0;
}