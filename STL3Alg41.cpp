#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>

void inputFromKeyboard(std::list<int>& l) {
    int n;
    std::cout << "Введите кол-во элементов: ";
    std::cin >> n;

    std::cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        l.push_back(x);
    }
}

void inputRandom(std::list<int>& l) {
    std::srand(std::time(0));
    int n;
    std::cout << "Введите кол-во элементов: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int x = std::rand() % 201 - 100;
        l.push_back(x);
    }
}

void inputFromFile(std::list<int>& l, const std::string& filename) {
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

void printList(const std::list<int>& l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    std::list<int> l;
    int choice;

    std::cout << "Выберите способ ввода данных:\n";
    std::cout << "1 - с клавиатуры\n";
    std::cout << "2 - случайными числами\n";
    std::cout << "3 - из файла\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        inputFromKeyboard(l);
        break;
    case 2:
        inputRandom(l);
        break;
    case 3: {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        inputFromFile(l, filename);
        break;
    }
    default:
        std::cout << "Ошибка" << std::endl;
        return 1;
    }

    std::cout << "\nИсходный список: ";
    printList(l);

    std::stable_partition(l.begin(), l.end(), [](int x) { return x > 0; });

    std::cout << "Результат: ";
    printList(l);
}
