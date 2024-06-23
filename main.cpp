#include <QCoreApplication>
#include <iostream>
#include "factory.h"

std::shared_ptr<LanguageFactory> ChoiceLang(std::string lang)
{
    if(lang == "cpp"){
        return std::make_shared<CppFactory>();
    }

    if(lang == "cs"){
        return std::make_shared<CsFactory>();
    }
    if(lang == "java"){
        return std::make_shared<JavaFactory>();
    }

    return std::make_shared<LanguageFactory>();
}

std::string GenerateProgram(const std::shared_ptr<LanguageFactory> &factory)
{
    auto class_a = factory->CreateClass("ClassA"); // самый верхний класс, в который будет помещаться всё остальное

    class_a->add(factory->CreateMethod("testFunc1", "void", 0), ClassUnit::PUBLIC); // публичная функция, находящаяся в подклассе ClassB

    class_a->add(factory->CreateMethod("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE); // добавление приватной статической функции в верхний класс

    auto method = factory->CreateMethod("testFunc4", "void", MethodUnit::STATIC | MethodUnit::FINAL); // создание метода

    method->add(factory->CreatePrintOperator("Hello, world!")); // добавление в метод операции вывода

    class_a->add(method, ClassUnit::PROTECTED); // помещение метода в верхний класс

    class_a->add(factory->CreateMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC); // добавление публичного виртуального константного метода

    return class_a->compile(); // генерация кода программы, по произведенным выше настройкам
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string lang;
    while(true){
        std::cout << "Input language:" << std::endl;
        std::cin >> lang;
        // обработка ошибок сделана для того чтобы ошибка при генерации программы на одном из языков, программы на других языках имели возможность быть сгенерированными, так как они слабо зависят друг от друга
        try
        {
            std::cout << GenerateProgram(ChoiceLang(lang)) << std::endl; // создание фабрики языка C++ и генерация кода программы на этом языке
        }
        catch (const std::runtime_error &error)
        {
            std::cout << error.what() << std::endl;
        }
    }
    return a.exec();
}
