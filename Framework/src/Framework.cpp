//============================================================================
// Name        : Framework.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "core/Expression.h"
#include "core/ValueModel.h"
#include "core/UnaryExpressionModel.h"
#include "core/BinaryExpressionModel.h"
#include "core/BinaryShadowExpression.h"
#include "core/UnaryShadowExpression.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/AndMult.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"

void testValueModel(){
	//test de ValueModel
	core::ValueModel<int> v1;
	v1.setValue(3);
	core::ValueModel<int> v2(2);
	std::cout << v1.Evaluate() << std::endl ;
	std::cout << v2.Evaluate() << std::endl ;
}

void testNotMinus(){
	core::ValueModel<double> v1(0.7);
	fuzzy::NotMinus1<double> nm;
	core::UnaryExpressionModel<double> ue(&nm,&v1);
	std::cout << ue.Evaluate() << std::endl;

}

void testAndMult(){
	core::ValueModel<double> v1(2);
	core::ValueModel<double> v2(3);
	fuzzy::AndMult<double> am;
	core::BinaryExpressionModel<double> be(&am,&v1,&v2);
	std::cout << be.Evaluate() << std::endl;
}

void testAndMin(){
	core::ValueModel<double> v1(2);
	core::ValueModel<double> v2(3);
	fuzzy::AndMin<double> am;
	core::BinaryExpressionModel<double> be(&am,&v1,&v2);
	std::cout << be.Evaluate() << std::endl;
}

void testOrMax(){
	core::ValueModel<double> v1(2);
	core::ValueModel<double> v2(3);
	fuzzy::OrMax<double> am;
	core::BinaryExpressionModel<double> om(&am,&v1,&v2);
	std::cout << om.Evaluate() << std::endl;
}

void testOrPlus(){
	core::ValueModel<double> v1(2);
	core::ValueModel<double> v2(3);
	fuzzy::OrPlus<double> am;
	core::BinaryExpressionModel<double> op(&am,&v1,&v2);
	std::cout << op.Evaluate() << std::endl;
}

void testBinaryShadow(){	//use factories
	core::ValueModel<double> v1(2);
	core::ValueModel<double> v2(3);
	fuzzy::AndMin<double> am;
	core::BinaryShadowExpression<double> bse(&am);
	std::cout << bse.Evaluate(&v1,&v2) << std::endl;
}

void testUnaryShadow(){	//use factories
	core::ValueModel<double> v1(0.7);
	fuzzy::NotMinus1<double> nm;
	core::UnaryShadowExpression<double> use(&nm);
	std::cout << use.Evaluate(&v1) << std::endl;
}

int main() {

	std::cout << "Test ValueModel" << std::endl;
	testValueModel();
	std::cout << "Test NotMinus" << std::endl;
	testNotMinus();
	std::cout << "Test AndMult" << std::endl;
	testAndMult();
	std::cout << "Test AndMin" << std::endl;
	testAndMin();
	std::cout << "Test OrMax" << std::endl;
	testOrMax();
	std::cout << "Test OrPlus" << std::endl;
	testOrPlus();


	//tests à écrire pour les shadows et les factories
	std::cout << "Test BinaryShadow" << std::endl;
	testBinaryShadow();
	std::cout << "Test UnaryShadow" << std::endl;
	testUnaryShadow();


	return 0;
}

//andprod
//virtual T Evaluate(core::Expression<T>*, core::Expression <T>*)

//operators.h :
//template <class T>
//class And : public core::BinaryExpression<T> {};
//pareil pour: Or, Then, Agg en bin
//pareil en unary pour:Not,

//pour andprod.h, including "oprators.h"
//template<class T>
//T AndProd::Evaluate(core::Expression<T>* left, same righ) const{
//T l = left->Evaluate
//T r = right->Evaluate
//return l*r; //evaluate before to have it from l to r
//}

//IsTriangle
//public:
//IsTriangle<T>

//Memory: un set suffit... WHAT?


//TIP
//typedef fuzzy::AndMin<NUMERIC> AndMin; => fuzzy.h
//fuzzy.cpp
//void tips(){
//AndMin opAnd;
//}
