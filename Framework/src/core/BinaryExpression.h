/*
 * BinaryExpression.h
 *
 *  Created on: 17 mars 2015
 *      Author: scrutch
 */

#ifndef CORE_BINARYEXPRESSION_H_
#define CORE_BINARYEXPRESSION_H_
#include "Expression.h"


namespace core{

	template <class T>
	class BinaryExpression
	{
	public:
			virtual T Evaluate(Expression<T>*, Expression<T>*) const=0;
			virtual ~BinaryExpression(){};
	};
}

#endif /* BINARYEXPRESSION_H_ */
