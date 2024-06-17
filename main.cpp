#include <iostream>


#include "factory.h"

std::string GenerateProgram(const std::shared_ptr<LanguageFactory> &factory)
{
    auto class_a = factory->CreateClass("ClassA");
    auto class_b = factory->CreateClass("ClassB");

    class_b->add(factory->CreateMethod("testFunc1", "void", 0), ClassUnit::PUBLIC);

    class_a->add(class_b, ClassUnit::PUBLIC);

    class_a->add(factory->CreateMethod("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);

    auto method = factory->CreateMethod("testFunc4", "void", MethodUnit::STATIC | MethodUnit::VIRTUAL);

    method->add(factory->CreatePrintOperator("Hello, world!"));

    class_a->add(method, ClassUnit::PROTECTED);
    class_a->add(factory->CreateMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);

    return class_a->compile();
}


int main(int argc, char *argv[])
{
    // C++
    std::cout << "C++:" << std::endl;

    // обработка ошибок сделана для того чтобы ошибка при генерации программы на одном из языков, программы на других языках имели возможность быть сгенерированными, так как они слабо зависят друг от друга
    try
    {
        std::cout << GenerateProgram(std::make_shared<CppFactory>()) << std::endl; // создание фабрики языка C++ и генерация кода программы на этом языке
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }

    // C#
    std::cout << "C#:" << std::endl;

    try
    {
        std::cout << GenerateProgram(std::make_shared<CsFactory>()) << std::endl; // создание фабрики языка C# и генерация кода программы на этом языке
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
