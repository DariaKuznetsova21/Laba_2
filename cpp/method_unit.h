#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H
#include <string>
#include <vector>
#include <memory>
// конкретная языковая конструкция метода некоторого языка
class CppMethodUnit : public MethodUnit
{
public:
    CppMethodUnit(const std::string &name, const std::string &returnType, Flags flags): MethodUnit(name, returnType, flags){}
    {}

    std:: string compile( unsigned int level = 0) const {
        std:: string result = generateShift(level);
        if (m_flags & STATIC) {
            result += "static";
        }
        else if (m_flags & VIRTUAL){
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
};

#endif // METHOD_UNIT_H

