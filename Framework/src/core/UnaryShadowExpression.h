/*
 * UnaryShadowExpression.h
 *
 *  Created on: 30 mars 2015
 *      Author: scrutch
 */

#ifndef CORE_UNARYSHADOWEXPRESSION_H_
#define CORE_UNARYSHADOWEXPRESSION_H_
#include "UnaryExpression.h"

namespace core {

template <class T>
class UnaryShadowExpression: public UnaryExpression<T>{
public:
	UnaryShadowExpression(UnaryExpression<T>* target = NULL);
	virtual T Evaluate(Expression<T>*) const;
	virtual ~UnaryShadowExpression(){}
	virtual void setTarget(UnaryExpression<T>*);

private:
	UnaryExpression<T>* target;
};

template <class T>
UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* _target):
target(_target)
{
}

template <class T>
T UnaryShadowExpression<T>::Evaluate(Expression<T>* o) const{
	if(target != NULL)
		return target->Evaluate(o);
	//else throw (std::exception); //exception qui fait tout
}

template <class T>
void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* _target){
	target = _target;
}

}
#endif /* CORE_UNARYSHADOWEXPRESSION_H_ */
