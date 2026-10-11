# day04
This repository is for 4th lesson in school

## TASK 1

Вы — ведущий инженер связи на орбитальной станции «Ares-7». К вам приближается грузовой шаттл снабжения. Автоматическая система стыковки обменивается зашифрованными сигналами с бортовым компьютером станции. Сигнал состоит из импульсов захвата `(` и подтверждения `)`.

Из-за солнечной бури в потоке данных возникли помехи. Если протокол нарушен и импульсы не сбалансированы, замки стыковочного шлюза заклинит, что приведет к катастрофе. 

Вы находите под столом инструкцию с описанием того, как должна работать функция валидации сигнала. Вы вбиваете эти инструкции, чтобы получить набор тестов:

``` cpp
void dotest(const std::string& str, bool expected) {
    bool result = validParentheses(str);
    
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

    std::cout << "\n--- Valid Cases ---" << std::endl;
    dotest("()",                 true);
    dotest("((()))",             true);
    dotest("()()()",             true);
    dotest("(()())()",           true);
    dotest("()(())((()))(())()", true);

    std::cout << "\n--- Empty String Case ---" << std::endl;
    dotest("", true);

    std::cout << "\n--- Invalid Cases ---" << std::endl;
    dotest(")(",     false);
    dotest("()()(",  false);
    dotest("((())",  false);
    dotest("())(()", false);
    dotest(")()",    false);
    dotest(")",      false);

    std::cout << "\n" << GREEN "=== ALL TESTS PASSED SUCCESSFULLY ===" << RESET << std::endl;
    return 0;
}
```
### Задание

Вам нужно написать фукцию `bool validParentheses(const std::string& str)`

- Каждый импульс захвата ( должен иметь строго последующий парный импульс подтверждения ).
- Сигнал подтверждения не может быть отправлен до импульса захвата.
- Пустая строка сигналов считается валидной (режим ожидания).

## TASK 2

Археологическая экспедиция глубоко под водой обнаружила легендарные Врата Атлантиды. На воротах высечены цепочки из четырех видов древних рун, обозначающих стихии: Воздух `()`, Землю `[]`, Воду `{}` и Огонь `<>`. Врата заперты на магический замок, который реагирует на правильный порядок активации защитных заклинаний.

Заклинания могут быть вложенными (например, внутри стихии Земли активируется Вода), но они обязаны закрываться в строгом иерархическом порядке. Если нарушить последовательность или закрыть стихию Огня руной Воды, сработает древняя ловушка и пещеру затопит.

Понимая, как должен работать правильный порядок, вы подготавливаете программу для тестирования, чтобы убедиться в правильности ваших идей:

```cpp
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
```

### Задание

Напишите функцию `bool validParentheses(const std::string& str)`, которая спасет экспедицию и определит, откроют ли руны ворота.
- Доступны 4 вида рун: `( )`, `[ ]`, `{ }`, `< >`.
- Руна закрытия должна соответствовать последней открытой руне того же типа.
- Посторонние символы (следы от страшных морских существ) внутри строки нужно просто игнорировать.