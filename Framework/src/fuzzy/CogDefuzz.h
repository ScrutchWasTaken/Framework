/*
 * CogDefuzz.h
 *
 *  Created on: 17 mai 2015
 *      Author: gael
 */

#ifndef FUZZY_COGDEFUZZ_H_
#define FUZZY_COGDEFUZZ_H_
#include "../core/Evaluator.h"
#include "MandaniDefuzz.h"

/*
 * Défuzzifi !
 */

namespace fuzzy {

	template <class T>
	class CogDefuzz:public MandaniDefuzz<T>
	{
	public :
		CogDefuzz(const T&,const T&,const T&);
		T defuzz(const typename core::Evaluator<T>::Shape&)const;
	};

	template <class T>
	CogDefuzz<T>::CogDefuzz(const T& _min,const T& _max,const T& _step):
	MandaniDefuzz<T>(_min,_max,_step) {

	}

	/*
	 * Propre à la méthode du centre de gravité
	 *					 C'EST LA SOLUTION !
	 */
	template <class T>
	T CogDefuzz<T>::defuzz(const typename core::Evaluator<T>::Shape &s)const {

		T x,y,num=0,den=0;
		/* parcours de la forme finale et calcule le centre
		 * de gravité : Somme(xy)/Sommme(y)
		 */
		for(unsigned int i=0; i<(s.first.size()-1); i++) {
			x=s.first.at(i);
			y=s.second.at(i);
			num+=x*y;
			den+=y;
		}
		if(den==0)
			throw std::exception();
		return num/den;
	}
}

#endif /* FUZZY_COGDEFUZZ_H_ */
