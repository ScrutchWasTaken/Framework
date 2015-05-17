/*
 * AndMin.h
 *
 *  Created on: 30 mars 2015
 *      Author: scrutch
 */

#ifndef FUZZY_AGGPLUS_H_
#define FUZZY_AGGPLUS_H_

#include "../core/Operators.h"

namespace fuzzy {

	template <class T>
	class AggPlus : public core::Agg<T>
	{
	public:
		T Evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AggPlus<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
		T l = left->Evaluate();
		T r = right->Evaluate();
		return l+r;
	}

}
#endif /* FUZZY_AGGPLUS_H_ */
