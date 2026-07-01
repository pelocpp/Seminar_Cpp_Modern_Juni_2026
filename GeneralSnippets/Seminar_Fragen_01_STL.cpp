#include <vector>
#include <algorithm>
#include <print>
#include <string>
#include <iostream>
#include <list>

// The signature does not need to have const &.

// Sehr klassisch, keine Objekt-Orientierung
// Variante 1

// static std::string g_header{" Header: "};

static void printValue(int value)
{
    static std::string g_header{ " Header: " };

    std::println("{} {}", g_header, value);
}

// Variante 2
// Aufrufbare Objekt
class MyPrinter
{
private:
    std::string m_header;

public:
    MyPrinter() : m_header{"Aufrufbares Objekt: >>> "} {}

    // Operator (): Dieser kann auf Instanzvariablen zugreifen
    void operator () (int value) {

        std::println("{} {}", m_header, value);
    }

    void operator () (int value, int zwei) {

        std::println("{} {}", m_header, value);
    }
};


static void lambda_01_classic()
{
    std::vector<int> vec{ 1, 2, 3 };

    //std::for_each(
    //    vec.begin(),
    //    vec.end(),
    //    printValue
    //);

    MyPrinter printer;

    std::for_each(
        vec.begin(),
        vec.end(),
        printer
    );

    std::println();
}


static void lambda_01_modern()
{
    std::vector<int> vec{ 1, 2, 3 };

    std::for_each(
        vec.begin(),
        vec.end(),
        [] (int value) { std::println(" ===> {}", value); }
    );

    std::println();
}

void main_seminar_stl()
{
    lambda_01_modern();
}

// =================================================================

void main_seminar_vector()
{
    std::vector<std::size_t> numbers;

    numbers.reserve(80);  // use reserve ..........

    for (std::size_t i{}; i != 100; ++i) {

        numbers.push_back( 2 * i );

        std::println("{}: Size: {} - Capacity: {}", i, numbers.size(), numbers.capacity());
    }

    numbers.shrink_to_fit();

    std::println("    Size: {} - Capacity: {}", numbers.size(), numbers.capacity());
}

void main_seminar_vector_die_zweite()
{
    using MyContainer = std::list<int>;

    MyContainer numbers;

    MyContainer::value_type elem = 123;

    numbers.push_back(elem);

    std::list<int> numbers2;

    std::list<int>::iterator pos = numbers.begin();

    auto pos2 = numbers.begin();
}















void main_seminar_zeichenketten()
{
    const char* cp = "111111111111111111111111111111111111111111111";

    std::string s = "111111111111111111111111111111111111111111111";

    std::size_t sz = sizeof(std::string);

    std::string klein = "123";   // kurz ???????????????????

    auto size{ sizeof(std::string) };
    auto capacity{ std::string{}.capacity() };
    auto small{ std::string(capacity, '*') };
    auto big{ std::string(capacity + 1, '#') };

    std::cout << "sizeof  : " << size << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Small   : " << small.capacity() << ": " << small << std::endl;
    std::cout << "Big     : " << big.capacity() << ": " << big << std::endl;
}
