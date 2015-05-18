#include "biblio.h"

using namespace core;
using namespace fuzzy;

//void testValueModel(){
//	//test de ValueModel
//	ValueModel<int> v1;
//	v1.setValue(3);
//	ValueModel<int> v2(2);
//	std::cout << v1.Evaluate() << std::endl ;
//	std::cout << v2.Evaluate() << std::endl ;
//}
//
//void testNotMinus(){
//	ValueModel<double> v1(0.7);
//	NotMinus1<double> nm;
//	UnaryExpressionModel<double> ue(&nm,&v1);
//	std::cout << ue.Evaluate() << std::endl;
//
//}
//
//void testAndMult(){
//	ValueModel<double> v1(2);
//	ValueModel<double> v2(3);
//	AndMult<double> am;
//	BinaryExpressionModel<double> be(&am,&v1,&v2);
//	std::cout << be.Evaluate() << std::endl;
//}
//
//void testAndMin(){
//	ValueModel<double> v1(2);
//	ValueModel<double> v2(3);
//	AndMin<double> am;
//	BinaryExpressionModel<double> be(&am,&v1,&v2);
//	std::cout << be.Evaluate() << std::endl;
//}
//
//void testOrMax(){
//	ValueModel<double> v1(2);
//	ValueModel<double> v2(3);
//	OrMax<double> am;
//	BinaryExpressionModel<double> om(&am,&v1,&v2);
//	std::cout << om.Evaluate() << std::endl;
//}
//
//void testOrPlus(){
//	ValueModel<double> v1(2);
//	ValueModel<double> v2(3);
//	OrPlus<double> am;
//	BinaryExpressionModel<double> op(&am,&v1,&v2);
//	std::cout << op.Evaluate() << std::endl;
//}
//
//void testBinaryShadow(){	//use factories
//	ValueModel<double> v1(2);
//	ValueModel<double> v2(3);
//	AndMin<double> am;
//	BinaryShadowExpression<double> bse(&am);
//	std::cout << bse.Evaluate(&v1,&v2) << std::endl;
//}
//
//void testUnaryShadow(){	//use factories
//	ValueModel<double> v1(0.7);
//	NotMinus1<double> nm;
//	UnaryShadowExpression<double> use(&nm);
//	std::cout << use.Evaluate(&v1) << std::endl;
//}



void application(){
	NotMinus1<double> opNot;
	AndMin<double> opAnd;
	OrMax<double> opOr;
	ThenMin<double> opThen;
	AggMax<double> opAgg;
	CogDefuzz<double> opDefuzz(0,25,1);

	FuzzyFactory<double> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	//		poor	good	excelent 	cheap	average	generous
	double min1=0, min2=5, min3=10, 	min4=0, min5=10, min6=20;
	double mid1=5, mid2=10, mid3=15, 	mid4=5, mid5=15, mid6=25;
	double max1=10, max2=15, max3=20, 	max4=10, max5=20, max6=30;

	/* Service */
	IsTriangle<double> poor(min1,mid1,max1);
	IsTriangle<double> good(min2,mid2,max2);
	IsTriangle<double> excellent(min3,mid3,max3);

	/* Miamiam */
	IsTriangle<double> fpoor(min1,mid1,max1);
	IsTriangle<double> fgood(min2,mid2,max2);
	IsTriangle<double> fexcellent(min3,mid3,max3);

	/* Tips */
	IsTriangle<double> cheap(min4,mid4,max4);
	IsTriangle<double> average(min5,mid5,max5);
	IsTriangle<double> generous(min6,mid6,max6);

	ValueModel<double> service(0);
	ValueModel<double> food(0);
	ValueModel<double> tips(0);

	Expression<double> *r =
			f.newAgg(
				f.newAgg( //3
					f.newAgg(// 2
						f.newAgg(	// 1
							f.newThen(
								f.newAnd(
									f.newIs(&poor, &service),
									f.newIs(&fpoor, &food)
								),
								f.newIs(&cheap,&tips)
							),
							f.newThen(
								f.newAnd(
									f.newIs(&good, &service),
									f.newIs(&fpoor, &food)
								),
								f.newIs(&average, &tips)
							)
						),	// fin 1

						f.newAgg(	// 1 bis
							f.newThen(
								f.newAnd(
									f.newIs(&excellent, &service),
									f.newIs(&fpoor, &food)
								),
								f.newIs(&average,&tips)
							),
							f.newThen(
								f.newAnd(
									f.newIs(&poor, &service),
									f.newIs(&fgood, &food)
								),
								f.newIs(&average, &tips)
							)
						)	// fin 1 bis
					)
				,
				f.newAgg(// 2 bis
					f.newAgg(
						f.newThen(
							f.newAnd(
								f.newIs(&good, &service),
								f.newIs(&fgood, &food)
							),
							f.newIs(&average,&tips)
						),
						f.newThen(
							f.newAnd(
								f.newIs(&excellent, &service),
								f.newIs(&fgood, &food)
							),
							f.newIs(&generous, &tips)
						)
					),	// fin 1

					f.newAgg(	// 1 bis
						f.newThen(
							f.newAnd(
								f.newIs(&poor, &service),
								f.newIs(&fexcellent, &food)
							),
							f.newIs(&average,&tips)
						),
						f.newThen(
							f.newAnd(
								f.newIs(&good, &service),
								f.newIs(&fexcellent, &food)
							),
						f.newIs(&generous, &tips)
					)
				)	// fin 1 bis
			)
		),
		f.newThen(
			f.newAnd(
				f.newIs(&excellent, &service),
				f.newIs(&fexcellent, &food)
			),
			f.newIs(&generous,&tips)
			)
		);

	//defuzzification
	Expression<double> *system = f.newDefuzz(&tips, r);

	//apply input
	float s, b;
	while(true)
	{
	std::cout << "***** TIPS CALCULATOR *****" << std::endl;

	std::cout << "service (out of 20) : ";
	std::cin >> s;
	service.setValue(s);

	std::cout << "food (out of 20) : ";
	std::cin >> b;
	food.setValue(b);
	std::cout << "Give this tip : " << system->Evaluate() << " € " << std::endl << std::endl ;
	}
}



int main() {
	application();
	return 0;
}
