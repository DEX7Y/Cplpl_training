#include <iostream>

void swap(double&, double&);
double lenght(double, double, double, double);
void coord_input(double&, double&);
double hight(double, double);
double square(double, double, double);
double cos_find(double, double, double);

int main()
{
    setlocale(LC_ALL, "Russian");

    double x1{}, x2{}, x3{}, y1{}, y2{}, y3{};
    double a{}, b{}, c{};

    std::cout << "Введите кординаты x1 y1:\n";
    coord_input(x1, y1);
    std::cout << "Введите кординаты x2 y2:\n";
    coord_input(x2, y2);
    std::cout << "Введите кординаты x3 y3:\n";
    coord_input(x3, y3);

    a = lenght(x1, x2, y1, y2);
    b = lenght(x1, x3, y1, y3);
    c = lenght(x2, x3, y2, y3);

    if (a > b) { swap(a, b); }
    if (b > c) { swap(b, c); }
    if (a > b) { swap(a, b); }


    if (a + b > c)
    {
        double eps = 10E-9;
        double cos_c = cos_find(a, b, c);

        std::cout << "\n";
        if (abs(cos_c) < eps) {
            std::cout << "Треугольник прямоугольный!\n";
        }
        else if (cos_c >= eps) {
            std::cout << "Треугольник остроугольный!\n";
        }
        else if (cos_c <= -eps) {
            std::cout << "Треугольник тупоугольный!\n";
        }

        if (abs(c - a) < eps)
        {
            std::cout << "Треугольник равносторонний!\n";
        }
        else if (abs(b - a) < eps || abs(c-b) < eps)
        {
            std::cout << "Треугольник равнобедренный!\n";
        }

        double s = square(a, b, cos_c);

        double hight_a{}, hight_b{}, hight_c{};

        hight_a = hight(s, a);
        hight_b = hight(s, b);
        hight_c = hight(s, c);

        std::cout << "\n";
        std::cout << "Высота к стороне a = " << hight_a << std::endl;
        std::cout << "Высота к стороне b = " << hight_b << std::endl;
        std::cout << "Высота к стороне c = " << hight_c << std::endl;

    }
    else { std::cout << "Такого треугольника не существует!" << std::endl; }
}

void swap(double& a, double& b)
{
    double buffer = a;
    a = b;
    b = buffer;
}

double lenght(double x1, double x2, double y1, double y2)
{ return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))); }

void coord_input(double& x, double& y)
{
    while (true)
    {
        if (std::cin >> x >> y)
        {
            std::cin.ignore(32000, '\n');
            return;
        }
        std::cout << "Вы ввели некорректное значение, повторите попытку.\n";
        std::cin.clear();
        std::cin.ignore(32000, '\n');
    }

}

double hight(double s, double x)
{ return 2 * s / x; }

double square(double a, double b, double cos)
{ return (a * b * sqrt(1 - cos * cos)) / 2; }

double cos_find(double a,double b,double c)
{ return (a * a + b * b - c * c) / (2 * a * b); }