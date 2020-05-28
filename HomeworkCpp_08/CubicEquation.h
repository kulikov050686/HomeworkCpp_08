#pragma once
#include "Array/TemplateMyArray.h"
#include <cmath>

class CubicEquation
{
private:

	/// Возвращает знак переданного выражения 
	static int sign(double x);

	/// Ареакосинус
	static double arch(double x);

public:

	/// Действительные корни кубического уравнения
	static MyArray<double> RootsOfEquation(double a1, double a2, double a3, double a4);
};

