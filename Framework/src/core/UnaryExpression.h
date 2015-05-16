/*
 * UnaryExpression.h
 *
 *  Created on: 17 mars 2015
 *      Author: scrutch
 */

#ifndef CORE_UNARYEXPRESSION_H_
#define CORE_UNARYEXPRESSION_H_
#include "Expression.h"

namespace core {

	template <class T>
	class UnaryExpression{
		public:
			virtual T Evaluate(Expression<T>*) const=0;	//semantique de pointeurs: on bosse sur des elements abstraits
			virtual ~UnaryExpression(){}
	};
}

#endif /* UNARYEXPRESSION_H_ */
//virtual void SetValue(const T&);
//virtual T Evaluate() const;
