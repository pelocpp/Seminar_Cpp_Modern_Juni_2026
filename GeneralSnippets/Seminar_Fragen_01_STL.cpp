#include <vector>
#include <algorithm>
#include <print>
#include <string>

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