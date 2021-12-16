//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_TEMPLATECLASS_H
#define PHYSICSFORMULA_TEMPLATECLASS_H
/**
 * @class TemplateClass
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/18/2021
 * @lastEdit 3/21/2021
 */
#include <iostream>


static int objectCount = 0;

template<typename T>
class TemplateClass
{
    T templateVar;
    static auto countIncrease() { objectCount += 1; }
    static auto countDecrease() { objectCount -= 1; }
public:

    TemplateClass()
    {
        templateVar = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    TemplateClass(const TemplateClass& t)
    {
        templateVar = t.templateVar;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    TemplateClass(TemplateClass&& t) noexcept
    {
        templateVar = t.templateVar;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    TemplateClass& operator=(TemplateClass&& t) noexcept
    {
        if (this != &t)
        {
            templateVar = t.templateVar;
            countIncrease();
        }
        return *this;
    }

    TemplateClass& operator=(TemplateClass other)
    {
        std::swap(templateVar, other.templateVar);
        return *this;
    }

    static void show_objectCount() { std::cout << "\n template object count: "
                                               << objectCount << std::endl; }
    static int get_objectCount() { return objectCount; }


    ~TemplateClass() = default;

    auto setTemplateVar(T var) { templateVar = var; }
    [[nodiscard]] auto getTemplateVar() const { return templateVar; }


};
#endif //PHYSICSFORMULA_TEMPLATECLASS_H
