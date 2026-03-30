#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

void inputVectorFromKeyboard(std::vector<int>& v) {
    int n;
    std::cout << "Введите кол-во элементов для вектора: ";
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

void inputVectorRandom(std::vector<int>& v) {
    std::srand(std::time(0));
    int n;
    std::cout << "Введите кол-во элементов для вектора : ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "Ошибка" << std::endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        int x = std::rand() % 101;
        v.push_back(x);
    }
}

void inputVectorFromFile(std::vector<int>& v, const std::string& filename) {
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

void inputListFromKeyboard(std::list<int>& l) {
    int n;
    std::cout << "Введите кол-во элементов для списка: ";
    std::cin >> n;

    std::cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        l.push_back(x);
    }
}

void inputListRandom(std::list<int>& l) {
    std::srand(std::time(0));
    int n;
    std::cout << "Введите кол-во элементов для списка: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int x = std::rand() % 101;
        l.push_back(x);
    }
}

void inputListFromFile(std::list<int>& l, const std::string& filename) {
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cout << "Ошибка " << filename << std::endl;
        return;
    }

    int n;
    file >> n;

    for (int i = 0; i < n; i++) {
        int x;
        file >> x;
        l.push_back(x);
    }
    file.close();
}

void printVector(const std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printList(const std::list<int>& l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    std::vector<int> v;
    std::list<int> l;

    int choice;

    std::cout << "Ввод данных для вектора:\n";
    std::cout << "1 - с клавиатуры\n";
    std::cout << "2 - случайными числами\n";
    std::cout << "3 - из файла\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        inputVectorFromKeyboard(v);
        break;
    case 2:
        inputVectorRandom(v);
        break;
    case 3: {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        inputVectorFromFile(v, filename);
        break;
    }
    default:
        std::cout << "Ошибка" << std::endl;
        return 1;
    }

    if (v.empty() || v.size() % 2 != 0) {
        std::cout << "Ошибка" << std::endl;
        return 1;
    }

    std::cout << "\nВвод данных для списка:\n";
    std::cout << "1 - с клавиатуры\n";
    std::cout << "2 - случайными числами\n";
    std::cout << "3 - из файла\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        inputListFromKeyboard(l);
        break;
    case 2:
        inputListRandom(l);
        break;
    case 3: {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        inputListFromFile(l, filename);
        break;
    }
    default:
        std::cout << "Ошибка" << std::endl;
        return 1;
    }

    if (l.empty()) {
        std::cout << "Ошибка" << std::endl;
        return 1;
    }

    std::cout << "\nИсходный вектор: ";
    printVector(v);

    int half = v.size() / 2;
    std::vector<int> firstHalf(v.begin(), v.begin() + half);

    std::cout << "Первая половина вектора: ";
    printVector(firstHalf);

    std::cout << "Исходный список: ";
    printList(l);

    auto it = std::find_first_of(l.begin(), l.end(), firstHalf.begin(), firstHalf.end());

    if (it != l.end()) {
        l.insert(it, *it);
        std::cout << "\nРезультат: ";
        printList(l);
    }
    else {
        std::cout << "\nСписок не содержит требуемых элементов, список не изменен: ";
        printList(l);
    }
}
