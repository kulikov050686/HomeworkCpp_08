#pragma once
#include "Array/TemplateMyArray.h"
#include <cmath>

class CubicEquation
{
private:

	/// ���������� ���� ����������� ��������� 
	static int sign(double x);

	/// �����������
	static double arch(double x);

public:

	/// �������������� ����� ����������� ���������
	static MyArray<double> RootsOfEquation(double a1, double a2, double a3, double a4);
};

