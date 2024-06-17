#ifndef JAVA_CLASS_UNIT_H
#define JAVA_CLASS_UNIT_H

#include "../class_unit.h"


// конкретная языковая конструкция класса некоторого языка
class JavaClassUnit : public ClassUnit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    explicit JavaClassUnit(const std::string &name): ClassUnit(name, ACCESS_MODIFIERS.size()) {}

    void add(const std::shared_ptr< Unit >& unit, Flags flags){

        if(unit == nullptr){
            throw std::runtime_error("This unit is nullptr");
        }

        size_t accessModifier = PRIVATE;

        if(flags < m_fields.size()){
           accessModifier = flags;
        }

        m_fields[accessModifier].push_back(unit);
    }

    std:: string compile(unsigned int level = 0) const
    {
        std::string result = "class " + m_name +" {\n";

        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); i++){

            for (const auto& f: m_fields[i]){
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f -> compile(level + 1);
            }

        }
        result += generateShift(level) + "};\n";

        return result;
    }
};

const std::vector <std:: string> JavaClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"};

#endif // CLASS_UNIT_H
