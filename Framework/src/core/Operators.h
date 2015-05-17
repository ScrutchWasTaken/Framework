/*
 * Operators.h
 *
 *  Created on: 19 mars 2015
 *      Author: scrutch
 */

#ifndef CORE_OPERATORS_H_
#define CORE_OPERATORS_H_
#include "BinaryExpressionModel.h"
#include "UnaryExpressionModel.h"
#include "Expression.h"

namespace core{

	template <class T>
	class And : public core::BinaryExpression<T>
	{
	public :
		virtual T Evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

	template <class T>
	class Or : public core::BinaryExpression<T>
	{
	public:
		virtual T Evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

	template <class T>
	class Then : public core::BinaryExpression<T>
	{
	public:
		virtual T Evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

	template <class T>
	class Agg : public core::BinaryExpression<T>
	{
	public:
		virtual T Evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

	template <class T>
	class Defuzz : public core::BinaryExpression<T>
	{
	public:
		virtual T Evaluate(Expression<T>*,Expression<T>*) const = 0;
	};

	template <class T>
	class Not : public core::UnaryExpression<T>
	{
	public:
		virtual T Evaluate(Expression<T>*) const = 0;
	};

	template <class T>
	class Is : public core::UnaryExpression<T>
	{
	public:
		virtual T Evaluate(Expression<T>*) const = 0;
	};


}
#endif /* OPERATORS_H_ */
