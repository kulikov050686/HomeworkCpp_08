#include "HomeWork.h"

double HomeWork::Max(double x, double y)
{
	return (std::abs(x - y) + x + y) / 2.0;
}

void HomeWork::Task1()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	double force;
	double t;
	double m;

	std::cout << "Введите время: ";
	std::cin >> t;
	std::cout << "Введите массу: ";
	std::cin >> m;
	std::cout << "Введите силу тяги: ";
	std::cin >> force;

	if (m > 0)
	{
		if (t >= 0)
		{
			std::cout << "Пройденное расстояние космическим кораблём равно: " << std::abs(force) * t * t / (2 * m) << std::endl;
		}
		else
		{
			std::cout << "Время не может быть отрицательным!" << std::endl;
		}
	}
	else
	{
		std::cout << "Масса не может быть отрицательной!" << std::endl;
	}
}

void HomeWork::Task5()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	int32_t fileSize;
	int32_t connectionSpeed;

	std::cout << "Укажите размер файла для скачивания: ";
	std::cin >> fileSize;
	std::cout << "Какова скорость Вашего соединения: ";
	std::cin >> connectionSpeed;
	std::cout << "-----------------------------------------" << std::endl;

	if (fileSize > 0 && connectionSpeed > 0)
	{
		double p = 0;
		int32_t k = 0;
		int32_t i = 0;

		while (p < 100)
		{
			i++;

			if (fileSize - k <= connectionSpeed)
			{
				k = fileSize;
			}
			else
			{
				k += connectionSpeed;
			}

			if (k * 100 % fileSize == 0)
			{
				p = k * 100 / fileSize;
			}
			else
			{
				p = k * 100 / fileSize;
				p++;
			}

			std::cout << "Прошло " << i << " сек. Скачано " << k << " из " << fileSize << "Мб (" << p << "%)." << std::endl;		
			
			Sleep(1000);
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}
}

void HomeWork::Task7()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	int32_t n = 0; // Количество километров
	int32_t t = 0; // Количество секунд за которое пробегает километр
	int32_t T = 0; // Общее время

	std::cout << "Привет, Сэм!Сколько километров ты сегодня пробежал? ";
	std::cin >> n;

	if (n > 1)
	{
		for (int32_t i = 1; i <= n; i++)
		{
			std::cout << "Какой у тебя был темп на километре " << i << "? ";
			std::cin >> t;

			if (t > 0)
			{
				T += t;
			}
			else
			{
				std::cout << "Ошибка ввода данных!!!" << std::endl;
				i--;
			}
		}

		if (T % n == 0)
		{
			T /= n;
		}
		else
		{
			T /= n;
			T++;
		}

		int32_t minutes = T / 60;

		std::cout << "Твой средний темп за тренировку: " << minutes << " минуты " << T - 60 * minutes << " секунд." << std::endl;
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}	
}

void HomeWork::Task8()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	double water;
	double antibiotic;
	double bacteria;

	std::cout << "Введите количество капель воды: ";
	std::cin >> water;
	std::cout << "Введите колисество капель антибиотика: ";
	std::cin >> antibiotic;
	std::cout << "Введите количество бактерий: ";
	std::cin >> bacteria;
	std::cout << "----------------------------------------------------------" << std::endl;

	if (water > 0 && antibiotic > 0 && bacteria > 0)
	{
		const double p = 0.8;

		for (int32_t i = 1; i <= 20; i++)
		{
			if (bacteria > 0)
			{
				bacteria = 2 * bacteria - bacteria * antibiotic / water;
				antibiotic = p * antibiotic;

				std::cout << i << ". ";
				std::cout << "Количество бактерий: " << bacteria << " ";				
				std::cout << "Количество антибиотика: " << antibiotic << " " << std::endl;
			}
			else
			{
				bacteria = 0;
			}
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}
}

void HomeWork::Task9()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	double const k = 8.4; // процент затухания амплитуды
	double const accuracy = 0.001; // точность
	double initialAmplitude; // начальная амплитуда
	double finalAmplitude; // конечная амплитуда

	std::cout << "Введите начальную амплитуду: ";
	std::cin >> initialAmplitude;
	std::cout << "Введите конечную амплитуду: ";
	std::cin >> finalAmplitude;

	if (initialAmplitude > 0 && finalAmplitude > 0)
	{
		if (initialAmplitude > finalAmplitude)
		{
			double p = (1 - k / 100);
			int32_t n = 0;
			double amplitude = initialAmplitude;

			while (amplitude - finalAmplitude > accuracy)
			{
				amplitude *= p;
				n++;
			}

			std::cout << "От амплитуды " << initialAmplitude << " до амплитуды " << finalAmplitude << ",маятник совершит за " << n << " колебаний." << std::endl;
		}
		else
		{
			std::cout << "Конечная амплитуда не может быть больше начальной!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}
}

void HomeWork::Task10()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	double hazardLevel = 0;

	std::cout << "Введите максимально допустимый уровень опасности (от 0 до 1): ";
	std::cin >> hazardLevel;

	if (0 <= hazardLevel && hazardLevel <= 1)
	{
		std::cout << "Приблизительная глубина безопасной кладки: " << CubicEquation::RootsOfEquation(1, -3, -12, 10 - hazardLevel)[2] << std::endl;
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}	
}

void HomeWork::Task11()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	double a;
	double b;

	std::cout << "Введите число a=";
	std::cin >> a;
	std::cout << "Введите число b=";
	std::cin >> b;

	std::cout << "Максимально из введённых чисел является: " << Max(a, b) << std::endl;
}

void HomeWork::Run()
{
	//Task1();
	Task5();
	//Task7();
	//Task8();
	//Task9();
	//Task10();
	//Task11();
}
