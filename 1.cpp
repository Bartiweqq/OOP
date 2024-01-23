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
        // ����������� ������, ����������� ������ �������������
        Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {}

        // ����� ��� ���������� �������� ���������� ��� ��������� ��������� x
        double evaluate(double x) const {
            double result = 0.0;
            int degree = coefficients.size() - 1;

            // ������ �� ������� ������������ ���������� � ���������� �������� ���������� ��� ��������� x
            for (int i = 0; i < coefficients.size(); ++i) {
                result += coefficients[i] * pow(x, degree);
                degree--;
            }

            return result;
        }

        // ����� ��� �������� �����������
        Polynomial add(const Polynomial& other) const {
            // �������� ������������� ����������� ��� ��������� ������ ����������
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

        // ����� ��� ��������� �����������
        Polynomial subtract(const Polynomial& other) const {
            // ��������� ������������� ����������� ��� ��������� ������ ����������
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

        // ����� ��� ��������� �����������
        Polynomial multiply(const Polynomial& other) const {
            // ��������� ����������� ��� ��������� ������ ����������
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

        // ����� ��� ������ �� ����� �������� ����������
        void display() const {
            int degree = coefficients.size() - 1;

            // ����� �������� ���������� �� �����
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
        assert(resultCoeffs == coeffs && "������: ����������� Polynomial �������� �������");
        std::cout << "����������� Polynomial �������� ���������" << std::endl;
    }

    // ������������ ������ evaluate
    void testEvaluate() {
        std::vector<double> coeffs = { 2, -3, 1 };
        Polynomial poly(coeffs);

        double x = 2.0;
        double expected = 2 * x * x - 3 * x + 1;
        double result = poly.evaluate(x);

        assert(result == expected && "������: ����� evaluate �������� �������");
        std::cout << "����� evaluate �������� ��������� ��� x = " << x << std::endl;
    }

    // ������������ ������ add
    void testAdd() {
        std::vector<double> coeffs1 = { 2, -3, 1 };
        std::vector<double> coeffs2 = { 1, 4 };
        Polynomial poly1(coeffs1);
        Polynomial poly2(coeffs2);

        Polynomial result = poly1.add(poly2);

        std::vector<double> expectedCoeffs = { 3, 1, 1 }; // ��������� ������������ ��� ����� �����������
        assert(result.getCoefficients() == expectedCoeffs && "������: ����� add �������� �������");
        std::cout << "����� add �������� ���������" << std::endl;
    }

    // ������������ ������ subtract
    void testSubtract() {
        std::vector<double> coeffs1 = { 2, -3, 1 };
        std::vector<double> coeffs2 = { 1, 4 };
        Polynomial poly1(coeffs1);
        Polynomial poly2(coeffs2);

        Polynomial result = poly1.subtract(poly2);

        std::vector<double> expectedCoeffs = { 1, -7, 1 }; // ��������� ������������ ��� �������� �����������
        assert(result.getCoefficients() == expectedCoeffs && "������: ����� subtract �������� �������");
        std::cout << "����� subtract �������� ���������" << std::endl;
    }

    // ������������ ������ multiply
    void testMultiply() {
        std::vector<double> coeffs1 = { 2, -3, 1 };
        std::vector<double> coeffs2 = { 1, 4 };
        Polynomial poly1(coeffs1);
        Polynomial poly2(coeffs2);

        Polynomial result = poly1.multiply(poly2);

        std::vector<double> expectedCoeffs = { 2, -5, 5, -12, 4 }; // ��������� ������������ ��� ������������ �����������
        assert(result.getCoefficients() == expectedCoeffs && "������: ����� multiply �������� �������");
        std::cout << "����� multiply �������� ���������" << std::endl;
    }

    // ������������ ������ display
    void testDisplay() {
        // ����� ��������� ����� ������ display � ����� std::stringstream � ����� �������� ������ �� �������-���������
        // � ������ ������� ������ �������� ����� display � ������ ��������� ������� ����� � �������
        std::vector<double> coeffs = { 2, -3, 1 };
        Polynomial poly(coeffs);

        std::cout << "��������� �����: 2x^2 - 3x^1 + 1x^0" << std::endl;
        std::cout << "����������� �����: ";
        poly.display();
    }
    int main() {
        setlocale(LC_ALL, "Russian"); // ����� ������� �����
        system("chcp 1251"); // ����������� ��������� �������
        // �������� ���� ����������� � ��������� ��������������
        vector<double> coeffs1 = { 2, -3, 1 }; // ������ ������������� ��� ���������� 2x^2 - 3x + 1
        vector<double> coeffs2 = { 1, 4 };    // ������ ������������� ��� ���������� x + 4

        Polynomial poly1(coeffs1);
        Polynomial poly2(coeffs2);
        // ������ ������
        testConstructor();
        testEvaluate();
        testAdd();
        testSubtract();
        testMultiply();
        testDisplay();

        std::cout << "��� ����� ������ �������" << std::endl;
        int choice;
        // ����� ���� � ���������� ��������� ��������
        do {
            cout << "�������� ��������:\n";
            cout << "1. ��������� �������� ���������� ��� ��������� ���������\n";
            cout << "2. ������� ����������\n";
            cout << "3. ������� ����������\n";
            cout << "4. �������� ����������\n";
            cout << "5. ������� �������� ����������\n";
            cout << "0. �����\n";
            cout << "��� �����: ";
            cin >> choice;

            switch (choice) {
            case 1:
                double x;
                cout << "������� �������� ���������: ";
                cin >> x;
                // ���������� �������� ���������� ��� ��������� ���������
                cout << "�������� ���������� ��� ��������� " << x << ": " << poly1.evaluate(x) << endl;
                break;
            case 2:
                // �������� ����������� � ����� ����������
                (poly1.add(poly2)).display();
                break;
            case 3:
                // ��������� ����������� � ����� ����������
                (poly1.subtract(poly2)).display();
                break;
            case 4:
                // ��������� ����������� � ����� ����������
                (poly1.multiply(poly2)).display();
                break;
            case 5:
                // ����� �������� ����� �����������
                cout << "��������� 1: ";
                poly1.display();
                cout << "��������� 2: ";
                poly2.display();
                break;
            case 0:
                cout << "��������� ���������.\n";
                break;
            default:
                cout << "�������� �����. ���������� ��� ���.\n";
            }
        } while (choice != 0);

        return 0;

    }