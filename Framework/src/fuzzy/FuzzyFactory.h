/*
 * FuzzyFactory.h
 *
 *  Created on: 15 mai 2015
 *      Author: scrutch
 */

#ifndef FUZZY_FUZZYFACTORY_H_
#define FUZZY_FUZZYFACTORY_H_
#include "../core/ExpressionFactory.h"

namespace fuzzy{

template <class T>
class FuzzyFactory: public core::ExpressionFactory<T>
{
public:
	FuzzyFactory();
	virtual ~FuzzyFactory(){}
	virtual core::Expression<T> newAnd(core::Expression<T>*, core::Expression<T>* );
	virtual core::Expression<T> newOr(core::Expression<T>*, core::Expression<T>*);
	virtual core::Expression<T> newThen(core::Expression<T>*, core::Expression<T>* );
	virtual core::Expression<T> newAgg(core::Expression<T>*, core::Expression<T>*);
	virtual core::Expression<T> newDefuzz(core::Expression<T>*, core::Expression<T>*);
	virtual core::Expression<T> newNot(core::Expression<T>*);
	virtual core::Expression<T> newIs(Is,core::Expression<T>*);

	virtual void changeAnd(And<T>*);
	virtual void changeOr(Or<T>*);
	virtual void changeNot(Not<T>*);
	virtual void changeThen(Then<T>*);
	virtual void changeAgg(Agg<T>*);
	virtual void changeDefuzz(Defuzz<T>*);
	virtual void changeIs(Is<T>*);

private:
	core::BinaryShadowExpression<T> _and, _or, then, agg, defuzz;
	core::UnaryShadowExpression<T> _not;
};

template <class T>
FuzzyFactory<T>::FuzzyFactory()	//operateurs par defauts pour and? or? then? ?
{}

template <class T>
core::Expression<T> FuzzyFactory<T>::newAnd(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(_and, l,r);
}

template <class T>
core::Expression<T> FuzzyFactory<T>::newOr(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(_or, l,r);
}

template <class T>
core::Expression<T> FuzzyFactory<T>::newThen(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(then, l,r);
}

template <class T>
core::Expression<T> FuzzyFactory<T>::newAgg(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(agg, l,r);
}

template <class T>
core::Expression<T> FuzzyFactory<T>::newDefuzz(core::Expression<T>* l, core::Expression<T>* r){
	return newBinary(defuzz, l,r);
}

template <class T>
core::Expression<T> FuzzyFactory<T>::newNot(core::Expression<T>* o){
	return newBinary(_not, o);
}

template <class T>
core::Expression<T> FuzzyFactory<T>::newNot(core::Expression<T>* o){
	return newBinary(defuzz, o);
}

template <class T>
core::Expression<T> FuzzyFactory<T>::newIs(Is,core::Expression<T>* o){
	return newBinary(Is, o);
}

template <class T>
void FuzzyFactory<T>::changeAnd(And<T>* and_){
	_and.setTarget(and_);
}

template <class T>
void FuzzyFactory<T>::changeOr(Or<T>* or_){
	_or.setTarget(or_);
}

template <class T>
void FuzzyFactory<T>::changeNot(Not<T>* not_){
	_not.setTarget(not_);
}

template <class T>
void FuzzyFactory<T>::changeThen(Then<T>* then_){
	then.setTarget(then_);
}

template <class T>
void FuzzyFactory<T>::changeAgg(Agg<T>* agg_){
	agg.setTarget(agg_);
}

template <class T>
void FuzzyFactory<T>::changeDefuzz(Defuzz<T>* defuzz_){
	defuzz.setTarget(defuzz_);
}

template <class T>
void FuzzyFactory<T>::changeIs(Is<T>* is_){
	is.setTarget(is_);
}




}

#endif /* FUZZY_FUZZYFACTORY_H_ */
