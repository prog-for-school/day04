#include <iostream>
#include <string>
#include <cassert>
#include <stack>

// Цветовые коды ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

bool validAllParentheses(const std::string& str) {
    std::stack<char> stack;
    bool is_valid = true;

    // ВАШ КОД ЗДЕСЬ

    return is_valid;
}

// НЕ ТРОГАТЬ ФУНКЦИИ СНИЗУ


void dotest(const std::string& str, bool expected) {
    bool result = validAllParentheses(str);
    
    if (result == expected) {
        std::cout << GREEN "[ OK ]" RESET " Test passed: \"" 
                  << str << "\" -> " << (expected ? "true" : "false") << std::endl;
    } else {
        std::cerr << RED "[ FAIL ]" RESET " Test failed for: \"" << str << "\"\n"
                  << "         Expected: " << (expected ? "true" : "false") << "\n"
                  << "         Got:      " << (result ? "true" : "false") << std::endl;
    }

    assert(result == expected);
}

int main() {
    std::cout << YELLOW << "=== STARTING TESTS ===" << RESET << std::endl;

    std::cout << "\n--- Valid Cases (Mixed Brackets) ---" << std::endl;
    dotest("()",                 true);
    dotest("[]",                 true);
    dotest("{}",                 true);
    dotest("<>",                 true);
    dotest("([])",               true);
    dotest("{[<>]()}",           true);
    dotest("<()[{} division]>",  true); // Текст внутри игнорируется, скобки валидны

    std::cout << "\n--- Empty String Case ---" << std::endl;
    dotest("", true);

    std::cout << "\n--- Invalid Cases (Mixed Brackets) ---" << std::endl;
    dotest(")(",     false);
    dotest("([)]",    false); // Неверный порядок вложенности
    dotest("{[}]",    false); // Неверный порядок вложенности
    dotest("<(>",     false); // Круглая не закрыта, закрывается угловая
    dotest("((())",  false);
    dotest(")",      false);
    dotest("([<>}",   false); // Фигурная закрывает квадратную

    std::cout << "\n" << GREEN "=== ALL TESTS PASSED SUCCESSFULLY ===" << RESET << std::endl;
    return 0;
}
