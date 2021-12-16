//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_LINEARALGEBRA_H
#define PHYSICSFORMULA_LINEARALGEBRA_H
template<typename VECTOR>
auto dot_product(VECTOR& v, VECTOR& u)
{
    return v.dot_product(u);
}

template<typename VECTOR>
VECTOR cross_product(VECTOR& v, VECTOR& u)
{
    return v.cross_product(u);
}
#endif //PHYSICSFORMULA_LINEARALGEBRA_H
