/*
 * BinaryShadowExpression.h
 *
 *  Created on: 2 avr. 2015
 *      Author: scrutch
 */

#ifndef CORE_BINARYSHADOWEXPRESSION_H_
#define CORE_BINARYSHADOWEXPRESSION_H_
#include "BinaryExpression.h"

namespace core {

template <class T>
class BinaryShadowExpression: public BinaryExpression<T>{
public:
	BinaryShadowExpression(BinaryExpression<T>* target = NULL);
	virtual T Evaluate(Expression<T>*, Expression<T>*) const;
	virtual ~BinaryShadowExpression(){};
	virtual void setTarget(BinaryExpression<T>*);

private:
	BinaryExpression<T>* target;
};

template <class T>
BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target):
target(_target)
{
}

template <class T>
T BinaryShadowExpression<T>::Evaluate(Expression<T>* l, Expression<T>* r) const {
	if (target != NULL)
		return target->Evaluate(l,r);
}

template <class T>
void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* _target){
	target = _target;
}




}
#endif /* CORE_BINARYSHADOWEXPRESSION_H_ */
