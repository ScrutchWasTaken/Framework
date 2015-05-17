#ifndef CORE_ISTRAPEZERIGHT_H_
#define CORE_ISTRAPEZERIGHT_H_

#include "Operators.h"

namespace core {

/*	 	   _________
 *    	  /
 *  	 /
 * 		/
 */

	template <class T>
	class IsTrapezeRight : public Is<T> {

	private:
		T min;
		T mmid;

	public:
		IsTrapezeRight(T&, T&);

		T Evaluate(Expression<T>*) const;
	};

	template <class T>
	IsTrapezeRight<T>::IsTrapezeRight(T& _min, T& _mid):
		min(_min), mid(_mid) { }

	template <class T>
	T IsTrapezeLeft<T>::Evaluate(Expression<T>* e) const {
		T sol = e -> Evaluate();

		if(sol>= mid) {
			return 1 ;
		} else {			// % d'appartennance
			return (sol-min)/(mid-min);
		}
	}


}

#endif
