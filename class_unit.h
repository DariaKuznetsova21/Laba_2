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
    explicit ClassUnit(const std::string &name): m_name(name) {
        m_fields.resize( ACCESS_MODIFIERS.size());
    }// количество поддерживаемых модификаторов доступа конкретным языком, на этапе компиляции процесс происоходит до тела конструктора

    void add (const std::shared_ptr< Unit >& unit, Flags flags){

        int accessModifier = PRIVATE;

        if(flags < ACCESS_MODIFIERS.size()){
           accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }

    std:: string compile (unsigned int level = 0) const
    {
        std::string result = generateShift(level) + "class" + m_name +"{\n";

        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); i++){
            if(m_fields[i].empty()){
                continue;
            }
            result += ACCESS_MODIFIERS[i] + ":\n";
            for (const auto& f: m_fields[i]){
                result += f -> compile(level+1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }

private:
    std::string m_name; // имя создаваемого класса

    using Fields = std::vector<std::shared_ptr<Unit>>; // тип данных для набора полей класса, 1 филдс уже вектор

    std::vector<Fields> m_fields; // каждому модификатору доступа соотвествует свой набор полей
};

const std::vector <std:: string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"};

#endif // CLASS_UNIT_H
