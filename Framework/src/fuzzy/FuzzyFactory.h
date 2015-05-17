/*
 * FuzzyFactory.h
 *
 *  Created on: 15 mai 2015
 *      Author: scrutch
 */

#ifndef FUZZY_FUZZYFACTORY_H_
#define FUZZY_FUZZYFACTORY_H_
#include "../core/ExpressionFactory.h"
#include "../core/UnaryShadowExpression.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/Operators.h"

namespace fuzzy{

template <class T>
class FuzzyFactory: public core::ExpressionFactory<T>
{
public:
	FuzzyFactory(core::UnaryExpression<T>*, core::BinaryExpression<T>*,core::BinaryExpression<T>*,
			core::BinaryExpression<T>*,core::BinaryExpression<T>*,core::BinaryExpression<T>*);
	virtual ~FuzzyFactory(){}
	virtual core::BinaryExpressionModel<T>* newAnd(core::Expression<T>*, core::Expression<T>* );
	virtual core::BinaryExpressionModel<T>* newOr(core::Expression<T>*, core::Expression<T>*);
	virtual core::BinaryExpressionModel<T>* newThen(core::Expression<T>*, core::Expression<T>* );
	virtual core::BinaryExpressionModel<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
	virtual core::BinaryExpressionModel<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*);
	virtual core::UnaryExpressionModel<T>* newNot(core::Expression<T>*);
	virtual core::UnaryExpressionModel<T>* newIs(core::Is<T>*,core::Expression<T>*);

	virtual void changeAnd(core::And<T>*);
	virtual void changeOr(core::Or<T>*);
	virtual void changeNot(core::Not<T>*);
	virtual void changeThen(core::Then<T>*);
	virtual void changeAgg(core::Agg<T>*);
	virtual void changeDefuzz(core::Defuzz<T>*);
	virtual void changeIs(core::Is<T>*);

private:
	core::BinaryShadowExpression<T>* _and, _or, then, agg, defuzz;
	core::UnaryShadowExpression<T>* _not, is;
};

template <class T>
FuzzyFactory<T>::FuzzyFactory(core::UnaryExpression<T>* not_, core::BinaryExpression<T>* and_,core::BinaryExpression<T>* or_,
		core::BinaryExpression<T>* then_,core::BinaryExpression<T>* agg_,core::BinaryExpression<T>* defuzz_):
		_not(new core::UnaryShadowExpression<T>(not_)),_and(new core::BinaryShadowExpression<T>(and_)),
		_or(new core::BinaryShadowExpression<T>(or_)),then(new core::BinaryShadowExpression<T>(then_)),
		agg(new core::BinaryShadowExpression<T>(agg_)),defuzz(new core::BinaryShadowExpression<T>(defuzz_))
{}

template <class T>
core::BinaryExpressionModel<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(_and, l,r);
}

template <class T>
core::BinaryExpressionModel<T>* FuzzyFactory<T>::newOr(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(_or, l,r);
}

template <class T>
core::BinaryExpressionModel<T>* FuzzyFactory<T>::newThen(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(then, l,r);
}

template <class T>
core::BinaryExpressionModel<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(agg, l,r);
}

template <class T>
core::BinaryExpressionModel<T>* FuzzyFactory<T>::newDefuzz(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(defuzz, l,r);
}

template <class T>
core::UnaryExpressionModel<T>* FuzzyFactory<T>::newNot(core::Expression<T>* o){
	return newUnary(_not, o);
}

template <class T>
core::UnaryExpressionModel<T>* FuzzyFactory<T>::newIs(core::Is<T>* s,core::Expression<T>* o){
	return newUnary(s, o);
}

template <class T>
void FuzzyFactory<T>::changeAnd(core::And<T>* and_){
	_and->setTarget(and_);
}

template <class T>
void FuzzyFactory<T>::changeOr(core::Or<T>* or_){
	_or->setTarget(or_);
}

template <class T>
void FuzzyFactory<T>::changeNot(core::Not<T>* not_){
	_not->setTarget(not_);
}

template <class T>
void FuzzyFactory<T>::changeThen(core::Then<T>* then_){
	then->setTarget(then_);
}

template <class T>
void FuzzyFactory<T>::changeAgg(core::Agg<T>* agg_){
	agg->setTarget(agg_);
}

template <class T>
void FuzzyFactory<T>::changeDefuzz(core::Defuzz<T>* defuzz_){
	defuzz->setTarget(defuzz_);
}

template <class T>
void FuzzyFactory<T>::changeIs(core::Is<T>* is_){
	is->setTarget(is_);
}




}

#endif /* FUZZY_FUZZYFACTORY_H_ */
