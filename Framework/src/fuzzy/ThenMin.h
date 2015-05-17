#ifndef FUZZY_THENMIN_H_
#define FUZZY_THENMIN_H_

#include "../core/Operators.h"

namespace fuzzy {

	template <class T>
	class ThenMin : public core::Then<T>
	{
	public:
		T Evaluate(core::Expression<T> *, core::Expression<T> *) const;
	};

	template <class T>
	T ThenMin<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
		T l=left->Evaluate();
		T r = right->Evaluate();
		return (l<r)? l:r;
	}

}

#endif
