/*
 * AndMin.h
 *
 *  Created on: 30 mars 2015
 *      Author: scrutch
 */

#ifndef FUZZY_ANDMIN_H_
#define FUZZY_ANDMIN_H_

#include "../core/Operators.h"

namespace fuzzy {

	template <class T>
	class AndMin : public core::And<T>
	{
	public:
		T Evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AndMin<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
		T l = left->Evaluate();
		T r = right->Evaluate();
		return (l<r)? l:r;
	}

}
#endif /* FUZZY_ANDMIN_H_ */
