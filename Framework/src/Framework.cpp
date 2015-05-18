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
#include "core/Evaluator.h"

#include "core/ExpressionFactory.h"
#include "fuzzy/FuzzyFactory.h"

#include "fuzzy/AggMax.h"
#include "fuzzy/AggPlus.h"
#include "fuzzy/AndMult.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/CogDefuzz.h"
#include "core/IsTriangle.h"
#include "core/IsTrapeze.h"
#include "core/IsTrapezeLeft.h"
#include "core/IsTrapezeRight.h"
#include "fuzzy/MandaniDefuzz.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/ThenMult.h"

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



void testFactory(){
	core::ValueModel<double> v1(2);
	core::ValueModel<double> v2(3);
	fuzzy::NotMinus1<double> opNot;
	fuzzy::AndMin<double> opAnd;
	fuzzy::OrMax<double> opOr;
	fuzzy::ThenMin<double> opThen;
	fuzzy::AggMax<double> opAgg;
	//fuzzy::CogDefuzz<double> opDefuzz(0,40,1);


	fuzzy::FuzzyFactory<double> fifou(&opNot,&opAnd,&opOr, &opThen, &opAgg, NULL);


	double minMauvais=0;
	double midMauvais=10;
	double maxMauvais=20;
	core::IsTriangle<double> mauvais(minMauvais,midMauvais,maxMauvais);

	double minMoyen=10;
	double midMoyen=20;
	double maxMoyen=30;
	core::IsTriangle<double> moyen(minMoyen,midMoyen,maxMoyen);

	double minBon=20;
	double midBon=30;
	double maxBon=40;
	core::IsTriangle<double> bon(minBon,midBon,maxBon);

	double minMauvaises=0;
	double midMauvaises=10;
	double maxMauvaises=20;
	core::IsTriangle<double> mauvaises(minMauvaises,midMauvaises,maxMauvaises);

	double minMoyennes=10;
	double midMoyennes=20;
	double maxMoyennes=30;
	core::IsTriangle<double> moyennes(minMoyennes,midMoyennes,maxMoyennes);

	double minBonnes=20;
	double midBonnes=30;
	double maxBonnes=40;
	core::IsTriangle<double> bonnes(minBonnes,midBonnes,maxBonnes);

	core::ValueModel<double> scenario(0);
	core::ValueModel<double> critiques(0);

}
void testCours(){
	fuzzy::NotMinus1<double> opNot;
	fuzzy::AndMin<double> opAnd;
	fuzzy::OrMax<double> opOr;
	fuzzy::ThenMin<double> opThen;
	fuzzy::AggMax<double> opAgg;
	fuzzy::CogDefuzz<double> opDefuzz(0,25,1);

	fuzzy::FuzzyFactory<double> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	double min1=-5, min2=0, min3=5, min4=0, min5=10, min6=20;
	double mid1=0, mid2=5, mid3=10, mid4=5, mid5=15, mid6=25;
	double max1=5, max2=10, max3=15, max4=10, max5=20, max6=30;

	core::IsTriangle<double> poor(min1,mid1,max1);
	core::IsTriangle<double> good(min2,mid2,max2);
	core::IsTriangle<double> excellent(min3,mid3,max3);

	core::IsTriangle<double> cheap(min4,mid4,max4);
	core::IsTriangle<double> average(min5,mid5,max5);
	core::IsTriangle<double> generous(min6,mid6,max6);

	core::ValueModel<double> service(0);
	core::ValueModel<double> tips(0);

	core::Expression<double> *r = f.newAgg(f.newAgg(f.newThen(f.newIs(&poor,&service),f.newIs(&cheap,&tips)),
	f.newThen(f.newIs(&good,&service),f.newIs(&average,&tips))),f.newThen(f.newIs(&excellent,&service),f.newIs(&generous,&tips)));

	//defuzzification
	core::Expression<double> *system = f.newDefuzz(&tips, r);

	//apply input
	float s;
	while(true)
	{
	std::cout << "service : ";
	std::cin >> s;
	service.setValue(s);
	std::cout << "tips -> " << system->Evaluate() << std::endl;
	}
}
void testYOLO(){
	fuzzy::NotMinus1<double> opNot;
	fuzzy::AndMin<double> opAnd;
	fuzzy::OrMax<double> opOr;
	fuzzy::ThenMin<double> opThen;
	fuzzy::AggMax<double> opAgg;
	fuzzy::CogDefuzz<double> opDefuzz(0,40,1);

	fuzzy::FuzzyFactory<double> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

		double minMauvais=0;
		double midMauvais=10;
		double maxMauvais=20;
		core::IsTriangle<double> mauvais(minMauvais,midMauvais,maxMauvais);

		double minMoyen=10;
		double midMoyen=20;
		double maxMoyen=30;
		core::IsTriangle<double> moyen(minMoyen,midMoyen,maxMoyen);

		double minBon=20;
		double midBon=30;
		double maxBon=40;
		core::IsTriangle<double> bon(minBon,midBon,maxBon);

		double minMauvaises=0;
		double midMauvaises=10;
		double maxMauvaises=20;
		core::IsTriangle<double> mauvaises(minMauvaises,midMauvaises,maxMauvaises);

		double minMoyennes=10;
		double midMoyennes=20;
		double maxMoyennes=30;
		core::IsTriangle<double> moyennes(minMoyennes,midMoyennes,maxMoyennes);

		double minBonnes=20;
		double midBonnes=30;
		double maxBonnes=40;
		core::IsTriangle<double> bonnes(minBonnes,midBonnes,maxBonnes);


		core::ValueModel<double> scenario(0);
		core::ValueModel<double> critiques(0);



		core::Expression<double>* r=
			f.newAgg(
				f.newAgg(
					f.newThen(
						f.newIs(&mauvais,&scenario),
						f.newIs(&mauvaises,&critiques)
					),
					f.newThen(
						f.newIs(&moyen,&scenario),
						f.newIs(&moyennes,&critiques)
					)
				),
				f.newThen(
					f.newIs(&bon,&scenario),
					f.newIs(&bonnes,&critiques)
				)
			);

		core::Expression<double>* system=f.newDefuzz(&critiques,r);

		double s;
		while(true){
			std::cout<<"scenario :";
			std::cin>>s;
			scenario.setValue(s);
			std::cout<<"critiques ->"<<system->Evaluate()<<std::endl;
		}

		std::cin.ignore();

}

int main() {
/*
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


	//tests à écrire pour les then, agg, defuzz

	std::cout << "Test BinaryShadow" << std::endl;
	testBinaryShadow();
	std::cout << "Test UnaryShadow" << std::endl;
	testUnaryShadow();
	std::cout << "Test Factory" << std::endl;*/
	//testFactory();
	//testYOLO();
	testCours();

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
