    #include <iostream>
    #include <vector>
    #include <locale.h>
    #include <cassert>
    #include <cstdlib>
    using namespace std;

    class Polynomial {

    private:
        vector<double> coefficients;

    public:
        // Конструктор класса, принимающий массив коэффициентов
        Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {}

        // Метод для вычисления значения многочлена для заданного аргумента x
        double evaluate(double x) const {
            double result = 0.0;
            int degree = coefficients.size() - 1;

            // Проход по каждому коэффициенту многочлена и вычисление значения многочлена для заданного x
            for (int i = 0; i < coefficients.size(); ++i) {
                result += coefficients[i] * pow(x, degree);
                degree--;
            }

            return result;
        }

        // Метод для сложения многочленов
        Polynomial add(const Polynomial& other) const {
            // Сложение коэффициентов многочленов для получения нового многочлена
            int size1 = coefficients.size();
            int size2 = other.coefficients.size();
            int maxSize = max(size1, size2);
            vector<double> resultCoeffs(maxSize);

            for (int i = 0; i < maxSize; ++i) {
                double term1 = (i < size1) ? coefficients[i] : 0.0;
                double term2 = (i < size2) ? other.coefficients[i] : 0.0;
                resultCoeffs[i] = term1 + term2;
            }

            return Polynomial(resultCoeffs);
        }

        // Метод для вычитания многочленов
        Polynomial subtract(const Polynomial& other) const {
            // Вычитание коэффициентов многочленов для получения нового многочлена
            int size1 = coefficients.size();
            int size2 = other.coefficients.size();
            int maxSize = max(size1, size2);
            vector<double> resultCoeffs(maxSize);

            for (int i = 0; i < maxSize; ++i) {
                double term1 = (i < size1) ? coefficients[i] : 0.0;
                double term2 = (i < size2) ? other.coefficients[i] : 0.0;
                resultCoeffs[i] = term1 - term2;
            }

            return Polynomial(resultCoeffs);
        }

        // Метод для умножения многочленов
        Polynomial multiply(const Polynomial& other) const {
            // Умножение многочленов для получения нового многочлена
            int size1 = coefficients.size();
            int size2 = other.coefficients.size();
            vector<double> resultCoeffs(size1 + size2 - 1, 0.0);

            for (int i = 0; i < size1; ++i) {
                for (int j = 0; j < size2; ++j) {
                    resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
                }
            }

            return Polynomial(resultCoeffs);
        }

        // Метод для вывода на экран описания многочлена
        void display() const {
            int degree = coefficients.size() - 1;

            // Вывод описания многочлена на экран
            for (int i = 0; i < coefficients.size(); ++i) {
                cout << coefficients[i] << "x^" << degree;
                if (i != coefficients.size() - 1) {
                    cout << " + ";
                }
                degree--;
            }
            cout << endl;
        }
        vector<double> getCoefficients() const {
            return coefficients;
        }
    };

   
    void testConstructor() {
        std::vector<double> coeffs = { 2, -3, 1 };
        Polynomial poly(coeffs);

        std::vector<double> resultCoeffs = poly.getCoefficients();
        assert(resultCoeffs == coeffs && "Ошибка: Конструктор Polynomial работает неверно");
        std::cout << "Конструктор Polynomial работает корректно" << std::endl;
    }

    // Тестирование метода evaluate
    void testEvaluate() {
        std::vector<double> coeffs = { 2, -3, 1 };
        Polynomial poly(coeffs);

        double x = 2.0;
        double expected = 2 * x * x - 3 * x + 1;
        double result = poly.evaluate(x);

        assert(result == expected && "Ошибка: Метод evaluate работает неверно");
        std::cout << "Метод evaluate работает корректно для x = " << x << std::endl;
    }

    // Тестирование метода add
    void testAdd() {
        std::vector<double> coeffs1 = { 2, -3, 1 };
        std::vector<double> coeffs2 = { 1, 4 };
        Polynomial poly1(coeffs1);
        Polynomial poly2(coeffs2);

        Polynomial result = poly1.add(poly2);

        std::vector<double> expectedCoeffs = { 3, 1, 1 }; // Ожидаемые коэффициенты для суммы многочленов
        assert(result.getCoefficients() == expectedCoeffs && "Ошибка: Метод add работает неверно");
        std::cout << "Метод add работает корректно" << std::endl;
    }

    // Тестирование метода subtract
    void testSubtract() {
        std::vector<double> coeffs1 = { 2, -3, 1 };
        std::vector<double> coeffs2 = { 1, 4 };
        Polynomial poly1(coeffs1);
        Polynomial poly2(coeffs2);

        Polynomial result = poly1.subtract(poly2);

        std::vector<double> expectedCoeffs = { 1, -7, 1 }; // Ожидаемые коэффициенты для разности многочленов
        assert(result.getCoefficients() == expectedCoeffs && "Ошибка: Метод subtract работает неверно");
        std::cout << "Метод subtract работает корректно" << std::endl;
    }

    // Тестирование метода multiply
    void testMultiply() {
        std::vector<double> coeffs1 = { 2, -3, 1 };
        std::vector<double> coeffs2 = { 1, 4 };
        Polynomial poly1(coeffs1);
        Polynomial poly2(coeffs2);

        Polynomial result = poly1.multiply(poly2);

        std::vector<double> expectedCoeffs = { 2, -5, 5, -12, 4 }; // Ожидаемые коэффициенты для произведения многочленов
        assert(result.getCoefficients() == expectedCoeffs && "Ошибка: Метод multiply работает неверно");
        std::cout << "Метод multiply работает корректно" << std::endl;
    }

    // Тестирование метода display
    void testDisplay() {
        // Можно направить вывод метода display в поток std::stringstream и затем сравнить строку со строкой-ожиданием
        // В данном примере просто вызываем метод display и ручной проверкой смотрим вывод в консоль
        std::vector<double> coeffs = { 2, -3, 1 };
        Polynomial poly(coeffs);

        std::cout << "Ожидаемый вывод: 2x^2 - 3x^1 + 1x^0" << std::endl;
        std::cout << "Фактический вывод: ";
        poly.display();
    }
    int main() {
        setlocale(LC_ALL, "Russian"); // задаём русский текст
        system("chcp 1251"); // настраиваем кодировку консоли
        // Создание двух многочленов с заданными коэффициентами
        vector<double> coeffs1 = { 2, -3, 1 }; // Пример коэффициентов для многочлена 2x^2 - 3x + 1
        vector<double> coeffs2 = { 1, 4 };    // Пример коэффициентов для многочлена x + 4

        Polynomial poly1(coeffs1);
        Polynomial poly2(coeffs2);
        // Запуск тестов
        testConstructor();
        testEvaluate();
        testAdd();
        testSubtract();
        testMultiply();
        testDisplay();

        std::cout << "Все тесты прошли успешно" << std::endl;
        int choice;
        // Вывод меню и выполнение выбранной операции
        do {
            cout << "Выберите операцию:\n";
            cout << "1. Вычислить значение многочлена для заданного аргумента\n";
            cout << "2. Сложить многочлены\n";
            cout << "3. Вычесть многочлены\n";
            cout << "4. Умножить многочлены\n";
            cout << "5. Вывести описание многочлена\n";
            cout << "0. Выйти\n";
            cout << "Ваш выбор: ";
            cin >> choice;

            switch (choice) {
            case 1:
                double x;
                cout << "Введите значение аргумента: ";
                cin >> x;
                // Вычисление значения многочлена для заданного аргумента
                cout << "Значение многочлена для аргумента " << x << ": " << poly1.evaluate(x) << endl;
                break;
            case 2:
                // Сложение многочленов и вывод результата
                (poly1.add(poly2)).display();
                break;
            case 3:
                // Вычитание многочленов и вывод результата
                (poly1.subtract(poly2)).display();
                break;
            case 4:
                // Умножение многочленов и вывод результата
                (poly1.multiply(poly2)).display();
                break;
            case 5:
                // Вывод описания обоих многочленов
                cout << "Многочлен 1: ";
                poly1.display();
                cout << "Многочлен 2: ";
                poly2.display();
                break;
            case 0:
                cout << "Программа завершена.\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте еще раз.\n";
            }
        } while (choice != 0);

        return 0;

    }