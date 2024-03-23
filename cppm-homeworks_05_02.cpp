// cppm-homeworks_05_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

//базовый родитель
class Figure {
protected:    
    std::string name;
    Figure() {}; 
public:
    virtual void get_info() {};
};

//треугольник
class Triangle : public Figure {
protected:
    //стороны
    int a;
    int b;
    int c;
   
    //углы
    int A;
    int B;
    int C;
   
public:
    Triangle(int a, int b, int c, int A, int B, int C) :Figure() {
        name = "Треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    };
    void get_info() override {
        std::cout << name << ":\nCтороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << std::endl;
    }
   

};

//четырехугольник
class Quadrangle:public Figure {
protected:
    //стороны
    int a;
    int b;
    int c;
    int d;
    //углы
    int A;
    int B;
    int C;
    int D;
    
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) :Figure(){
        name = "Четырехугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    void get_info() override{
        std::cout << name << ":\nCтороны: "<<"a="<< a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }

};

//прямоугольный треугольник
class Triangle_C_90 : public Triangle {
public:
    Triangle_C_90(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    };

};

//равнобедренный треугольник
class Triangle_bedra_ravny : public Triangle {
public:
    Triangle_bedra_ravny(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    };
};

//равносторонний треугольник
class Triangle_all_sides_equal : public Triangle_bedra_ravny {
public:
    Triangle_all_sides_equal(int a) : Triangle_bedra_ravny(a, a, 60, 60) {
        name = "Равносторонний треугольник";
    };

};

//параллелограмм
class Parallelogramm : public Quadrangle {
public:
    Parallelogramm(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    };
};

//прямоугольник
class Quadrangle_all_corners_90 : public Parallelogramm {
public:
    Quadrangle_all_corners_90(int a, int b) : Parallelogramm(a, b, 90, 90) {
        name = "Прямоугольник";
    };

};

//квадрат
class Square :public Quadrangle_all_corners_90 {
public:
    Square(int a) :Quadrangle_all_corners_90(a, a) {
        name = "Квадрат";
    };
};

//ромб
class Romb : public Parallelogramm {
public:
    Romb(int a, int A, int B) :Parallelogramm(a, a, A, B) {
        name = "Ромб";
    };
};

//выводит информацию об экземпляре методом через указатель на базовый родитель
void print_info(Figure* adress) {
    
    adress->get_info();
    std::cout << std::endl;

}
int main()
{
    setlocale(LC_ALL, "rus");
    Triangle triangle_0(10, 20, 30, 50, 60, 70);
    Triangle_C_90 triangle_1(10, 20, 30, 50, 60);
    Triangle_bedra_ravny triangle_2(10, 20, 50, 60);
    Triangle_all_sides_equal triangle_3(30);
    Quadrangle quadrangle_0(10, 20, 30, 40, 50, 60, 70, 80);
    Quadrangle_all_corners_90 quadrangle_1(10,20);
    Square quadrangle_2(20);
    Parallelogramm quadrangle_3(20, 30, 30, 40);
    Romb quadrangle_4(30, 30, 40);

    Figure** arr_ptr = new Figure* [9];
    arr_ptr[0] = &triangle_0;
    arr_ptr[1] = &triangle_1;
    arr_ptr[2] = &triangle_2;
    arr_ptr[3] = &triangle_3;
    arr_ptr[4] = &quadrangle_0;
    arr_ptr[5] = &quadrangle_1;
    arr_ptr[6] = &quadrangle_2;
    arr_ptr[7] = &quadrangle_3;
    arr_ptr[8] = &quadrangle_4;

    for (int i = 0; i < 9; i++) {
        print_info(arr_ptr[i]);
    }
    delete[]arr_ptr;

    

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
