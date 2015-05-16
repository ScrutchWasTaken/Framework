/*
 * BinaryExpressionModel.h
 *
 *  Created on: 17 mars 2015
 *      Author: scrutch
 */

#ifndef CORE_BINARYEXPRESSIONMODEL_H_
#define CORE_BINARYEXPRESSIONMODEL_H_
#include "BinaryExpression.h"
#include "Expression.h"

namespace core{

	template <class T>
	class BinaryExpressionModel: public Expression<T>, public BinaryExpression<T>
	{
	public:
		BinaryExpressionModel(BinaryExpression<T>* operat = NULL, Expression<T>* left = NULL, Expression<T>* right = NULL);
		virtual ~BinaryExpressionModel(){}
		virtual T Evaluate() const;
		virtual T Evaluate(Expression<T>*, Expression<T>*) const;

		//get & set to do

	private:
		BinaryExpression<T>* operat;
		Expression<T>* left;
		Expression<T>* right;
	};

	template <class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _operat, Expression<T>* _left, Expression<T>* _right):
	operat(_operat),left(_left),right(_right)
	{
	}

	template <class T>
	T BinaryExpressionModel<T>::Evaluate() const{
		/*
		if(left==NULL)
			throw(NullExpressionException("left missing"));
		if(right==NULL)
			throw(NullExpressionException("right missing"));
		*/
		if(left!=NULL && right!=NULL)
			return Evaluate(left,right);
	}

	template <class T>
	T BinaryExpressionModel<T>::Evaluate(Expression<T>* l, Expression<T>* r) const{
		if(operat != NULL)
			return operat->Evaluate(l,r);
	}


}

#endif /* BINARYEXPRESSIONMODEL_H_ */

//faire les throws
//throw(NullExpressionException("left missing")
//BinaryExpression
