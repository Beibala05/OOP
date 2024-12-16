#include "comporable.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

A::A(int k) : key(k)                                {}
bool A::operator <  (const Comparable& other) const {return  key <  other.getKey();}
bool A::operator >  (const Comparable& other) const {return  key >  other.getKey();}
bool A::operator <= (const Comparable& other) const {return  key <= other.getKey();}
bool A::operator >= (const Comparable& other) const {return  key >= other.getKey();}
bool A::operator == (const Comparable& other) const {return  key == other.getKey();}
bool A::operator != (const Comparable& other) const {return  key != other.getKey();}
int  A::getKey()                              const {return  key;}


B::B(int k) : key(new int(k))                       {}
B::~B()                                             {delete key;}
bool B::operator <  (const Comparable& other) const {return *key <  other.getKey();}
bool B::operator >  (const Comparable& other) const {return *key >  other.getKey();}
bool B::operator <= (const Comparable& other) const {return *key <= other.getKey();}
bool B::operator >= (const Comparable& other) const {return *key >= other.getKey();}
bool B::operator == (const Comparable& other) const {return *key == other.getKey();}
bool B::operator != (const Comparable& other) const {return *key != other.getKey();}
int  B::getKey()                              const {return *key;}





int main() {
    // Создание объектов A и B
    A a1(10), a2(20);
    B b1(15), b2(25);

    // Проверка операций сравнения
    std::cout << "a1 < b1: " << (a1 < b1) << "\n";  // true
    std::cout << "a2 > b2: " << (a2 > b2) << "\n";  // false
    std::cout << "b1 <= a2: " << (b1 <= a2) << "\n"; // true
    std::cout << "b2 >= a1: " << (b2 >= a1) << "\n"; // true
    std::cout << "a1 == a2: " << (a1 == a2) << "\n"; // false
    std::cout << "b1 != b2: " << (b1 != b2) << "\n"; // true

    // Создание вектора указателей на Comparable
    std::vector<std::unique_ptr<Comparable>> vec;
    vec.push_back(std::make_unique<A>(10));
    vec.push_back(std::make_unique<B>(5));
    vec.push_back(std::make_unique<A>(30));
    vec.push_back(std::make_unique<B>(20));

    // Сортировка вектора
    std::sort(vec.begin(), vec.end(), [](const std::unique_ptr<Comparable>& lhs, const std::unique_ptr<Comparable>& rhs) {
        return *lhs < *rhs; // Сравнение через перегруженный оператор
    });

    // Вывод отсортированного вектора
    std::cout << "Отсортированный вектор ключей:\n";
    for (const auto& elem : vec) {
        std::cout << elem->getKey() << " ";
    }
    std::cout << "\n";

    return 0;
}
