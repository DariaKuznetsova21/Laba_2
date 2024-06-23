#ifndef CS_PRINT_OPERATOR_UNIT_H
#define CS_PRINT_OPERATOR_UNIT_H

#include "../print_operator_unit.h"

// конкретная языковая конструкция оператора вывода некоторого языка
class CsPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CsPrintOperatorUnit(const std::string &text) : PrintOperatorUnit(text){}
    virtual ~CsPrintOperatorUnit() = default;

    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
    }
};
#endif // PRINT_OPERATOR_UNIT_H
