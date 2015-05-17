#ifndef FUZZY_THENMULT_H_
#define FUZZY_THENMULT_H_

#include "../core/Operators.h"

namespace fuzzy {

	template <class T>
	class ThenMult : public core::Then<T>
	{
	public:
		T Evaluate(core::Expression<T> *, core::Expression<T> *) const;
	};

	template <class T>
	T ThenMult<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
		T l=left->Evaluate();
		T r = right->Evaluate();
		return l*r;
	}

}

#endif
