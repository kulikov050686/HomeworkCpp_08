#include "CubicEquation.h"

int CubicEquation::sign(double x)
{
	if (x >= 0)
	{
		return 1;
	}

	return -1;
}

double CubicEquation::arch(double x)
{
	return std::log(x + std::sqrt(x * x - 1));
}

MyArray<double> CubicEquation::RootsOfEquation(double a1, double a2, double a3, double a4)
{
	assert(a1 > 0);

	const double PI = 2 * asin(1);
	const double a = a2 / a1;
	const double b = a3 / a1;
	const double c = a4 / a1;
	const double Q = (a * a - 3 * b) / 9;
	const double R = (2 * a * a * a - 9 * a * b + 27 * c) / 54;
	const double S = Q * Q * Q - R * R;

	int n = 0;

	if (S >= 0)
	{
		n = 3;
	}
	else
	{
		n = 1;
	}

	MyArray<double> rootsOfEquation(n);

	if (S > 0)
	{
		double alfa = std::acos(R / std::sqrt(Q * Q * Q)) / 3;

		rootsOfEquation[0] = -2 * std::sqrt(Q) * std::cos(alfa) - a / 3;
		rootsOfEquation[1] = -2 * std::sqrt(Q) * std::cos(alfa + 2 * PI / 3) - a / 3;
		rootsOfEquation[2] = -2 * std::sqrt(Q) * std::cos(alfa - 2 * PI / 3) - a / 3;
	}
	else if (S == 0)
	{
		rootsOfEquation[0] = -2 * std::pow(R, 1.0 / 3.0) - a / 3;
		rootsOfEquation[1] = std::pow(R, 1.0 / 3.0) - a / 3;
		rootsOfEquation[2] = std::pow(R, 1.0 / 3.0) - a / 3;
	}
	else
	{
		if (Q > 0)
		{
			double alfa = arch(std::abs(R) / std::pow(std::abs(Q * Q * Q), 1.0 / 3.0));

			rootsOfEquation[0] = -2 * sign(R) * std::sqrt(std::abs(Q)) * std::cosh(alfa) - a / 3;
		}

		if (Q < 0)
		{
			double alfa = arch(std::abs(R) / std::pow(std::abs(Q * Q * Q), 1.0 / 3.0));

			rootsOfEquation[0] = -2 * sign(R) * std::sqrt(std::abs(Q)) * std::sinh(alfa) - a / 3;
		}

		if (Q == 0)
		{
			rootsOfEquation[0] = -std::pow(c - a * a * a / 27, 1.0 / 3.0) - a / 3;
		}
	}

	return rootsOfEquation;
}
