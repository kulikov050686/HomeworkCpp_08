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

void HomeWork::Task2()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	int32_t numberOfLockHandles; // Количество ручек замка
	int32_t numberOfPositions; // Количество положений
	double t; // Количество времени на одну комбинацию

	std::cout << "Введите количество ручек замка: ";
	std::cin >> numberOfLockHandles;
	std::cout << "Введите количество положений ручки: ";
	std::cin >> numberOfPositions;
	std::cout << "Введите время для одной комбинации: ";
	std::cin >> t;

	if (numberOfLockHandles > 0 && numberOfPositions && t > 0)
	{
		std::cout << "Время которое требуется для перебора всех комбинаций: " << t * std::pow(numberOfPositions, numberOfLockHandles) << std::endl;
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}
}

void HomeWork::Task3()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	double health; // здоровье 
	double magicResistance; // сопротивляемость к магии 
	double impactPower; // мощность удара 

	std::cout << "Введите уровень здоровья орка (от 0 до 1): ";
	std::cin >> health;
	std::cout << "Введите сопротивляемость к магии у орка (от 0 до 1): ";
	std::cin >> magicResistance;

	if (0 < health && health <= 1 && 0 < magicResistance && magicResistance <= 1)
	{
		if (magicResistance != 1)
		{
			while (health > 0)
			{
				std::cout << "Введите мощность водяного шара (от 0 до 1): ";
				std::cin >> impactPower;

				if (0 < impactPower && impactPower <= 1)
				{
					std::cout << "Наносимый урон: " << (1 - magicResistance) * impactPower << std::endl;

					if (health > (1 - magicResistance) * impactPower)
					{
						health = health - (1 - magicResistance) * impactPower;
					}
					else
					{
						health = 0;
					}

					std::cout << "Очки здоровья: " << health << std::endl;
				}
				else
				{
					std::cout << "Ошибка ввода данных!!!" << std::endl;
				}
			}

			std::cout << "Победа!!!" << std::endl;
		}
		else
		{
			std::cout << "Орка победить невозможно!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}		
}

void HomeWork::Task4()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	double const k = 5; // размер ребра кубика

	double a; // ширина бруска
	double b; // высота бруска
	double c; // длина бруска

	std::cout << "Введите ширину бруска: ";
	std::cin >> a;
	std::cout << "Введите высоту бруска: ";
	std::cin >> b;
	std::cout << "Введите длину бруска: ";
	std::cin >> c;

	if (a > 0 && b > 0 && c > 0)
	{
		double numberOfCubes = floor(a / k) * floor(b / k) * floor(c / k);

		std::cout << "Из этого буска можно изготовить: " << numberOfCubes << " кубиков." << std::endl;

		double n = floor(std::pow(numberOfCubes, 1.0 / 3.0));

		std::cout << "Из них можно составить набор из " << std::pow(n, 3) << " кубиков." << std::endl;
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
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

void HomeWork::Task6()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	double positionX = 0;
	double positionY = 0;
	bool exit = false;
	std::string key;

	std::cout << "Программа управления марсоходом." << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Команды:" << std::endl;
	std::cout << "W - движение на север" << std::endl;
	std::cout << "S - движение на юг" << std::endl;
	std::cout << "A - движение на запад" << std::endl;
	std::cout << "D - движение на восток" << std::endl;
	std::cout << "С - выход из программы" << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	while (!exit)
	{
		std::cout << "Марсоход находится на позиции (" << positionX << "," << positionY << ") введите команду :";
		std::getline(std::cin, key);

		if (key == "w" || key == "W")
		{
			if (positionY < 20)
			{
				positionY++;
			}
		}
		else if (key == "s" || key == "S")
		{
			if (positionY > 0)
			{
				positionY--;
			}
		}
		else if (key == "a" || key == "A")
		{
			if (positionX > 0)
			{
				positionX--;
			}
		}
		else if (key == "d" || key == "D")
		{
			if (positionX < 15)
			{
				positionX++;
			}
		}
		else if (key == "c" || key == "C")
		{
			exit = true;
		}
		else
		{
			std::cout << "Такой команды не существует!!!" << std::endl;
		}
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
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	bool exit = false;
	std::string text = "Выберите пункт меню";
	std::string items[12] = { "Задача 1",
							  "Задача 2",
							  "Задача 3",
							  "Задача 4",
							  "Задача 5",
							  "Задача 6",
							  "Задача 7",
							  "Задача 8",
							  "Задача 9",
							  "Задача 10",
							  "Задача 11",
							  "Выход" };

	MenuController menu(items, 12);

	while (!exit)
	{
		switch (menu.selectedMenuItem(text))
		{
		case 0:
			Task1();
			break;
		case 1:
			Task2();
			break;
		case 2:
			Task3();
			break;
		case 3:
			Task4();
			break;
		case 4:
			Task5();
			break;
		case 5:
			Task6();
			break;
		case 6:
			Task7();
			break;
		case 7:
			Task8();
			break;
		case 8:
			Task9();
			break;
		case 9:
			Task10();
			break;
		case 10:
			Task11();
			break;
		case 11:
			exit = true;
			break;
		}

		_getch();
	}	
}
