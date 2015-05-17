#ifndef CORE_ISTRAPEZELEFT_H_
#define CORE_ISTRAPEZELEFT_H_

#include "Operators.h"

namespace core {

/*	 	________
 *    	  		\
 *    		  	 \
 *   	 	  	  \
 *
 */

	template <class T>
	class IsTrapezeLeft : public Is<T> {

	private:
		T mid;
		T max;

	public:
		IsTrapezeLeft(T&, T&);

		T Evaluate(Expression<T>*) const;
	};

	template <class T>
	IsTrapezeLeft<T>::IsTrapezeLeft(T& _mid, T& _max):
		mid(_mid), max(_max) { }

	template <class T>
	T IsTrapezeLeft<T>::Evaluate(Expression<T>* e) const {
		T sol = e -> Evaluate();

		if(sol<= mid) {
			return 1 ;
		} else {			// % d'appartennance
			return (max-sol)/(max-mid);
		}
	}


}

#endif
