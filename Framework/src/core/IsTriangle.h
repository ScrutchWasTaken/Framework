/*
 * IsTriangle.h
 *
 *  Created on: 17 mai 2015
 *      Author: gael
 */

#ifndef CORE_ISTRIANGLE_H_
#define CORE_ISTRIANGLE_H_

#include "Operators.h"

namespace core {

	template <class T>
	class IsTriangle : public Is<T> {
	private:
		T min;
		T mid;
		T max;
	public:
		IsTriangle(T&, T&, T&);

		T Evaluate(Expression<T>*) const;
	};

	template <class T>
	IsTriangle<T>::IsTriangle(T& _min, T& _mid, T& _max):
		min(_min), mid(_mid), max(_max) { }

	template <class T>
	T IsTriangle<T>::Evaluate(Expression<T>* e) const {
		T sol = e -> Evaluate();

		if(sol<= min || sol >= max){	// Hors du triangle
			return 0 ;
		} else {			// % d'appartennance
			if(sol<=mid)
				return (sol-min)/(mid-min);
			else
				return (max-sol)/(max-mid);
		}
	}

}



#endif /* CORE_ISTRIANGLE_H_ */
