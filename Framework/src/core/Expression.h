/*
 * Expression.h
 *
 *  Created on: 3 mars 2015
 *      Author: scrutch
 */

#ifndef CORE_EXPRESSION_H_
#define CORE_EXPRESSION_H_

namespace core{

	template <class T>
	class Expression
	{
	public:
			virtual T Evaluate() const=0;
			virtual ~Expression() {};
	};

}

#endif /* EXPRESSION_H_ */
