#ifndef CS_METHOD_UNIT_H
#define CS_METHOD_UNIT_H
#include "../method_unit.h"
// конкретная языковая конструкция метода некоторого языка
class CsMethodUnit : public MethodUnit
{
public:
    CsMethodUnit(const std::string &name, const std::string &returnType, Flags flags): MethodUnit(name, returnType, flags){}

    std:: string compile( unsigned int level = 0) const {

        std::string result = "";

        if (m_flags & STATIC) {
            result += "static ";
        }
        else if (m_flags & VIRTUAL){
            result += "virtual ";
        }

        result += m_returnType + " ";
        result += m_name + "() {\n";

        for (const auto& b: m_body){
            result += b->compile(level + 1);
        }

        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // METHOD_UNIT_H

