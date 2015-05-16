/*
 * ValueModel.h
 *
 *  Created on: 17 mars 2015
 *      Author: scrutch
 */

#ifndef CORE_VALUEMODEL_H_
#define CORE_VALUEMODEL_H_
#include "Expression.h"

namespace core {

	template <class T>
	class ValueModel: public Expression<T>
	{
	public:
		ValueModel();
		ValueModel(const T&);	//T& car c'est peut être un objet
		virtual ~ValueModel();
		virtual T Evaluate() const;
		virtual void setValue(const T);

	private:
		T value;
	};

	template <class T>
	ValueModel<T>::ValueModel():value(0){

	}

	template<class T>
	ValueModel<T>::ValueModel(const T& val):value(val){

	}

	template <class T>
	ValueModel<T>::~ValueModel(){

	}

	template <class T>
	void ValueModel<T>::setValue(const T val){
		value = val;
	}

	template <class T>
	T ValueModel<T>::Evaluate() const{
		return value;
	}

}
#endif /* VALUEMODEL_H_ */
