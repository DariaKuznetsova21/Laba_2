#ifndef CLASS_UNIT_H
#define CLASS_UNIT_H
#include "unit.h"
#include <string>
#include <vector>
#include <memory>

// конкретная языковая конструкция класса некоторого языка
class ClassUnit : public Unit
{
public:
    // перечисление всех поддерживаемых модификаторов доступа всех поддерживаемых языков
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const std::string &name, size_t fields_size): m_name(name), m_fields(fields_size){}

    virtual ~ClassUnit() = default;

private:
    std::string m_name; // имя создаваемого класса

    using Fields = std::vector<std::shared_ptr<Unit>>; // тип данных для набора полей класса, 1 филдс уже вектор

    std::vector<Fields> m_fields; // каждому модификатору доступа соотвествует свой набор полей
};


#endif // CLASS_UNIT_H
