/*
 * AndMult.h
 *
 *  Created on: 30 mars 2015
 *      Author: scrutch
 */

#ifndef FUZZY_ANDMULT_H_
#define FUZZY_ANDMULT_H_
# include "../core/Operators.h"


namespace fuzzy {

template <class T>
class AndMult: public core::And<T>
{
	T Evaluate(core::Expression<T> *, core::Expression<T> *) const;
};

template <class T>
T AndMult<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	T l = left->Evaluate();
	T r = right->Evaluate();
	return l*r; //evaluate before to have it from l to r
}


}
#endif /* FUZZY_ANDMULT_H_ */

