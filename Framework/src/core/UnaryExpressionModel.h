/*
 * UnaryExpressionModel.h
 *
 *  Created on: 17 mars 2015
 *      Author: scrutch
 */

#ifndef CORE_UNARYEXPRESSIONMODEL_H_
#define CORE_UNARYEXPRESSIONMODEL_H_
#include "UnaryExpression.h"

namespace core{

	template <class T>
	class UnaryExpressionModel: public Expression<T>, public UnaryExpression<T>
	{
	public:
		UnaryExpressionModel(UnaryExpression<T>* operat = NULL, Expression<T>* operan = NULL);	//YOUHOU!!!
		virtual ~UnaryExpressionModel(){}
		virtual T Evaluate() const;
		virtual T Evaluate(Expression<T>*) const;
		//get set si voulus

	private:
		core::UnaryExpression<T>* operat;
		core::Expression<T>* operan;

	};

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* _operat, Expression<T>* _operan):
	operat(_operat),operan(_operan)
	{
	}

	template <class T>
	T UnaryExpressionModel<T>::Evaluate() const{
		if (operan != NULL) {
			throw (std::exception());//nullptr -> c++ 2011
		}
		return Evaluate(operan);
	}

	template <class T>
	T UnaryExpressionModel<T>::Evaluate(Expression<T>* o) const{
		if(operat != NULL) {
			throw (std::exception());
		}
		return operat->Evaluate(o);	// La fleche sert comme un point mais pour un pointeur
	}
}

#endif /* UNARYEXPRESSIONMODEL_H_ */
