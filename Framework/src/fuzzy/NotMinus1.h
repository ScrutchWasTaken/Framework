/*
 * NotMinus1.h
 *
 *  Created on: 24 mars 2015
 *      Author: scrutch
 */

#ifndef FUZZY_NOTMINUS1_H_
#define FUZZY_NOTMINUS1_H_
#include "../core/Operators.h"

namespace fuzzy {

	template <class T>
	class NotMinus1 : public core::Not<T>
	{
	public:
		T Evaluate(core::Expression<T> *) const;
	};

	template <class T>
	T NotMinus1<T>::Evaluate(core::Expression<T> *o) const {
		T res = o->Evaluate();
		res = 1 - res;
		return res;
	}

};
#endif /* FUZZY_NOTMINUS1_H_ */
