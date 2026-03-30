#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>

void inputFromKeyboard(std::vector<int>& v) {
    int n;
    std::cout << "Введите кол-во элементов: ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "Ошибка" << std::endl;
        return;
    }

    std::cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
}

void inputRandom(std::vector<int>& v) {
    std::srand(std::time(0));
    int n;
    std::cout << "Введите кол-во элементов: ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "Ошибка" << std::endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        int x = std::rand() % 201 - 100;
        v.push_back(x);
    }

    std::cout << "Сгенерированные числа: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void inputFromFile(std::vector<int>& v, const std::string& filename) {
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cout << "Ошибка " << filename << std::endl;
        return;
    }

    int n;
    file >> n;

    if (n % 2 != 0) {
        std::cout << "Ошибка" << std::endl;
        file.close();
        return;
    }

    for (int i = 0; i < n; i++) {
        int x;
        file >> x;
        v.push_back(x);
    }
    file.close();
}

void printVector(const std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool isNegative(int x) {
    return x < 0;
}

bool isPositive(int x) {
    return x > 0;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<int> v;
    int choice;

    std::cout << "Выберите способ ввода данных:\n";
    std::cout << "1 - с клавиатуры\n";
    std::cout << "2 - случайными числами\n";
    std::cout << "3 - из файла\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        inputFromKeyboard(v);
        break;
    case 2:
        inputRandom(v);
        break;
    case 3: {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        inputFromFile(v, filename);
        break;
    }
    default:
        std::cout << "Ошибка: неверный выбор" << std::endl;
        return 1;
    }

    std::cout << "\nИсходный вектор: ";
    printVector(v);

    int half = v.size() / 2;

    std::replace_if(v.begin(), v.begin() + half, isNegative, -1);

    std::replace_if(v.begin() + half, v.end(), isPositive, 1);

    std::cout << "Результат: ";
    printVector(v);
}
