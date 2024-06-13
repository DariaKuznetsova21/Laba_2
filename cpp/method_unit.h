#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H
#include <string>
#include <vector>
#include <memory>
// конкретная языковая конструкция метода некоторого языка
class MethodUnit : public Unit
{
public:
    // перечисление всех поддерживаемых модификаторов методов всех поддерживаемых языков
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1, // используются битовые флаги, то есть они могут быть установлены независимо, например STATIC | CONST
        VIRTUAL = 1 << 2
    };

public:
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags)//конструктор по умолчанию с 3 переменными
        : m_name(name)
        , m_returnType(returnType)
        , m_flags(flags)
    {}

    void add( const std::shared_ptr<Unit>& unit, Flags /*flags*/ = 0)
    {
        m_body.push_back( unit );
    }

    std:: string compile( unsigned int level = 0) const {
        std:: string result = generateShift(level);
        if (m_flags & STATIC) {
            result += "static";
        } else if (m_flags & VIRTUAL){
            result += "virtual";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if (m_flags & CONST ){
            result += "const";
        }
        result += "{\n";
        for (const auto& b: m_body){
            result += b->compile (level + 1);
        }
        result += generateShift (level) + "}\n";
        return result;
    }

private:
    std::string m_name; // имя метода
    std::string m_returnType; // тип возвращаемого методом значения

    Flags m_flags; // выбранные модификаторы метода

    std::vector<std::shared_ptr<Unit>> m_body; // тело метода в котором хранятся принадлежащие ему языковые конструкции
};

#endif // METHOD_UNIT_H

