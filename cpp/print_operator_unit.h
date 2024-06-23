#ifndef CPP_PRINT_OPERATOR_UNIT_H
#define CPP_PRINT_OPERATOR_UNIT_H

#include "../print_operator_unit.h"
// конкретная языковая конструкция оператора вывода некоторого языка
class CppPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CppPrintOperatorUnit(const std::string &text): PrintOperatorUnit(text){}

    std::string compile(unsigned int level = 0) const {
        return generateShift(level)+ "std::cout << \"" + m_text + "\" << endl;\n";
    }
};
#endif // PRINT_OPERATOR_UNIT_H
