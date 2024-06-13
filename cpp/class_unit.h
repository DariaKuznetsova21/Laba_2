#ifndef CLASS_UNIT_H
#define CLASS_UNIT_H
#include "unit.h"
#include <string>
#include <vector>
#include <memory>

// конкретная языковая конструкция класса некоторого языка
class CppClassUnit : public ClassUnit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    explicit CppClassUnit(const std::string &name):ClassUnit (name, ACCESS_MODIFIERS.size()){}

    void add (const std::shared_ptr< Unit >& unit, Flags flags){

        if(unit == nullptr){
            throw std::runtime_error("This unit is nullptr");
        }

        size_t accessModifier = PRIVATE;

        if(flags < m_fields.size()){
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

            result += generateShift(level) + ACCESS_MODIFIERS[i] + ":\n";

            for (const auto& f: m_fields[i]){
                result += f -> compile(level+1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";

        return result;
    }
};

const std::vector <std:: string> CppClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"};

#endif // CLASS_UNIT_H
