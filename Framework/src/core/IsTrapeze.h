/*
 * IsTrapeze.h
 *
 *  Created on: 17 mai 2015
 *      Author: gael
 */

#ifndef CORE_ISTRAPEZE_H_
#define CORE_ISTRAPEZE_H_

#include "Operators.h"

namespace core {

	template <class T>
	class IsTrapeze : public Is<T> {

	private:
		T min;
		T mid1;
		T mid2;
		T max;

	public:
		IsTrapeze(T&, T&, T&, T&);

		T Evaluate(Expression<T>*) const;
	};

	template <class T>
	IsTrapeze<T>::IsTrapeze(T& _min, T& _mid1, T& _mid2, T& _max):
		min(_min), mid1(_mid1), mid2(_mid2), max(_max) { }

	template <class T>
	T IsTrapeze<T>::Evaluate(Expression<T>* e) const {
		T sol = e -> Evaluate();

		if(sol<= min || sol >= max){
			return 0 ;
		} else if (sol >= mid1 && sold <= mid2) {
			return 1 ;

		} else{			// % d'appartennance
			if(sol<=mid1)
				return (sol-min)/(mid1-min);
			else
				return (max-sol)/(max-mid2);
		}
	}


}

#endif /* CORE_ISTRAPEZE_H_ */
