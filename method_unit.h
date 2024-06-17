#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H
#include <string>
#include <vector>
#include <memory>
#include "unit.h"
// конкретная языковая конструкция метода некоторого языка
class MethodUnit : public Unit
{
public:
    // перечисление всех поддерживаемых модификаторов методов всех поддерживаемых языков
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1, // используются битовые флаги, то есть они могут быть установлены независимо, например STATIC | CONST
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3
    };

public:
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags)//конструктор по умолчанию с 3 переменными
        : m_name(name)
        , m_returnType(returnType)
        , m_flags(flags)
    {}

    virtual ~MethodUnit() = default;

    void add( const std::shared_ptr<Unit>& unit, Flags /*flags*/ = 0)
    {
        if (unit == nullptr) {
            throw std::runtime_error("The unit is nullptr.");
        }
        m_body.push_back( unit );
    }

protected:
    std::string m_name; // имя метода
    std::string m_returnType; // тип возвращаемого методом значения

    Flags m_flags; // выбранные модификаторы метода

    std::vector<std::shared_ptr<Unit>> m_body; // тело метода в котором хранятся принадлежащие ему языковые конструкции
};

#endif // METHOD_UNIT_H

