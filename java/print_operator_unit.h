#ifndef JAVA_PRINT_OPERATOR_UNIT_H
#define JAVA_PRINT_OPERATOR_UNIT_H

#include "../print_operator_unit.h"
// конкретная языковая конструкция оператора вывода некоторого языка
class JavaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperatorUnit(const std::string &text): PrintOperatorUnit(text){}

    std::string compile(unsigned int level = 0) const {
        return generateShift(level)+ "System.out.println(\"" + m_text + "\");\n";
    }
};
#endif // PRINT_OPERATOR_UNIT_H
