#ifndef PRINT_OPERATOR_UNIT_H
#define PRINT_OPERATOR_UNIT_H
#include <string>
#include <vector>
#include <memory>
// конкретная языковая конструкция оператора вывода некоторого языка
class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit(const std::string &text)
        : m_text(text)
    {

    }

    std::string compile(unsigned int level = 0) const {
        return generateShift(level)+ "printf(\"" + m_text + "\" );\n";
    }
private:
    std::string m_text; // текст, который должен вывести данный оператор
};
#endif // PRINT_OPERATOR_UNIT_H
