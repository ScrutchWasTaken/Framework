/*
 * OrPlus.h
 *
 *  Created on: 30 mars 2015
 *      Author: scrutch
 */

#ifndef FUZZY_ORPLUS_H_
#define FUZZY_ORPLUS_H_
#include "../core/Operators.h"

namespace fuzzy {

	template <class T>
	class OrPlus : public core::Or<T>
	{
	public:
		T Evaluate(core::Expression<T> *, core::Expression<T> *) const;
	};

	template <class T>
	T OrPlus<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right)const{
		T l=left->Evaluate();
		T r=right->Evaluate();
		return l+r;
	}

}

#endif /* FUZZY_ORPLUS_H_ */
