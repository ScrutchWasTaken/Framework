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
 * Permet de calculer le résultat final (centre de gravité, moyenne, max ect.
 *
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
	MandaniDefuzz<T>(_min,_max,_step)
	{}


	template <class T>
	T CogDefuzz<T>::defuzz(const typename core::Evaluator<T>::Shape &s)const
	{
		T x,y,num=0,den=0;
		for(unsigned int i=0; i<(s.first.size()-1); i++)
		{
			x=s.first.at(i);
			y=s.second.at(i);
			num+=x*y;
			den+=y;
		}
		return num/den;
	}
}

#endif /* FUZZY_COGDEFUZZ_H_ */
