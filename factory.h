#ifndef FACTORY_H
#define FACTORY_H
#include <memory>
#include "cs/class_unit.h"
#include "cs/method_unit.h"
#include "cs/print_operator_unit.h"
#include "cpp/class_unit.h"
#include "cpp/method_unit.h"
#include "cpp/print_operator_unit.h"
#include "java/class_unit.h"
#include "java/method_unit.h"
#include "java/print_operator_unit.h"

// фабрика языков, классический вариант
// базовый класс создателя обьектов
class LanguageFactory
{
public:
    virtual ~LanguageFactory() = default; // обьявляем деструктор по умолчанию как виртуальный, для корректного вызова деструкторов конкретных реализаций
    virtual std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const{
        throw std::runtime_error("There are only cpp, cs and java languages");
    } // интерфейс фабричного метода, создающего за создание Unit'а класса
    virtual std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const {
        throw std::runtime_error("There are only cpp, cs and java languages");
    } // интерфейс фабричного метода, создающего за создание Unit'а метода
    virtual std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const {
        throw std::runtime_error("There are only cpp, cs and java languages");
    } // интерфейс фабричного метода, создающего за создание Unit'а оператора вывода
};

// конкретный создатель обьектов языка C++
// данный набор классов отличается только типом создаваемого обьекта, по этому можно остановиться на описании только первого из них
class CppFactory : public LanguageFactory
{
public:
    // набор конкретных реализаций фабричных методов
    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const override
    {
        return std::make_shared<CppClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const override
    {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const override
    {
        return std::make_shared<CppPrintOperatorUnit>(name);
    }
};

// конкретный создатель обьектов языка C#
class CsFactory : public LanguageFactory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const override
    {
        return std::make_shared<CsClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const override
    {
        return std::make_shared<CsMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const override
    {
        return std::make_shared<CsPrintOperatorUnit>(name);
    }
};

class JavaFactory : public LanguageFactory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const override
    {
        return std::make_shared<JavaClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const override
    {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const override
    {
        return std::make_shared<JavaPrintOperatorUnit>(name);
    }
};


#endif // FACTORY_H
