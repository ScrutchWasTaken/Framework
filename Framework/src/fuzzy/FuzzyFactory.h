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

namespace fuzzy {

	template <class T>
	class FuzzyFactory: public core::ExpressionFactory<T>
	{
	public:
		FuzzyFactory(core::UnaryExpression<T>*, core::BinaryExpression<T>*,core::BinaryExpression<T>*,
				core::BinaryExpression<T>*,core::BinaryExpression<T>*,core::BinaryExpression<T>*);
		virtual ~FuzzyFactory(){}
		virtual core::Expression<T>* newAnd(core::Expression<T>*, core::Expression<T>* );
		virtual core::Expression<T>* newOr(core::Expression<T>*, core::Expression<T>*);
		virtual core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>* );
		virtual core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
		virtual core::Expression<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*);
		virtual core::Expression<T>* newNot(core::Expression<T>*);
		virtual core::Expression<T>* newIs(core::Is<T>*,core::Expression<T>*);

		virtual void changeAnd(core::And<T>*);
		virtual void changeOr(core::Or<T>*);
		virtual void changeNot(core::Not<T>*);
		virtual void changeThen(core::Then<T>*);
		virtual void changeAgg(core::Agg<T>*);
		virtual void changeDefuzz(core::Defuzz<T>*);
		virtual void changeIs(core::Is<T>*);

	private:
		core::BinaryShadowExpression<T>* opAnd;
		core::BinaryShadowExpression<T>* opOr;
		core::BinaryShadowExpression<T>* then;
		core::BinaryShadowExpression<T>* agg;
		core::BinaryShadowExpression<T>* defuzz;
		core::UnaryShadowExpression<T>* opNot;
		core::UnaryShadowExpression<T>* is;
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(core::UnaryExpression<T>* not_, core::BinaryExpression<T>* and_,core::BinaryExpression<T>* or_,
			core::BinaryExpression<T>* then_,core::BinaryExpression<T>* agg_,core::BinaryExpression<T>* defuzz_):
			opNot(new core::UnaryShadowExpression<T>(not_)),opAnd(new core::BinaryShadowExpression<T>(and_)),
			opOr(new core::BinaryShadowExpression<T>(or_)),then(new core::BinaryShadowExpression<T>(then_)),
			agg(new core::BinaryShadowExpression<T>(agg_)),defuzz(new core::BinaryShadowExpression<T>(defuzz_))
	{}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* l, core::Expression<T>* r){
		return core::ExpressionFactory<T>::newBinary(opAnd, l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newOr(core::Expression<T>* l, core::Expression<T>* r){
		return core::ExpressionFactory<T>::newBinary(opOr, l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newThen(core::Expression<T>* l, core::Expression<T>* r){
		return core::ExpressionFactory<T>::newBinary(then, l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* l, core::Expression<T>* r){
		return core::ExpressionFactory<T>::newBinary(agg, l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newDefuzz(core::Expression<T>* l, core::Expression<T>* r){
		return core::ExpressionFactory<T>::newBinary(defuzz, l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newNot(core::Expression<T>* o){
		return core::ExpressionFactory<T>::newUnary(opNot, o);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newIs(core::Is<T>* s,core::Expression<T>* o){
		return core::ExpressionFactory<T>::newUnary(s, o);
	}

	template <class T>
	void FuzzyFactory<T>::changeAnd(core::And<T>* and_){
		opAnd->setTarget(and_);
	}

	template <class T>
	void FuzzyFactory<T>::changeOr(core::Or<T>* or_){
		opOr->setTarget(or_);
	}

	template <class T>
	void FuzzyFactory<T>::changeNot(core::Not<T>* not_){
		opNot->setTarget(not_);
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
