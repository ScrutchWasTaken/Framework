#include "biblio.h"

using namespace core;
using namespace fuzzy;

void testValueModel(){
	//test de ValueModel
	ValueModel<int> v1;
	v1.setValue(3);
	ValueModel<int> v2(2);
	std::cout << v1.Evaluate() << std::endl ;
	std::cout << v2.Evaluate() << std::endl ;
}

void testNotMinus(){
	ValueModel<double> v1(0.7);
	NotMinus1<double> nm;
	UnaryExpressionModel<double> ue(&nm,&v1);
	std::cout << ue.Evaluate() << std::endl;

}

void testAndMult(){
	ValueModel<double> v1(2);
	ValueModel<double> v2(3);
	AndMult<double> am;
	BinaryExpressionModel<double> be(&am,&v1,&v2);
	std::cout << be.Evaluate() << std::endl;
}

void testAndMin(){
	ValueModel<double> v1(2);
	ValueModel<double> v2(3);
	AndMin<double> am;
	BinaryExpressionModel<double> be(&am,&v1,&v2);
	std::cout << be.Evaluate() << std::endl;
}

void testOrMax(){
	ValueModel<double> v1(2);
	ValueModel<double> v2(3);
	OrMax<double> am;
	BinaryExpressionModel<double> om(&am,&v1,&v2);
	std::cout << om.Evaluate() << std::endl;
}

void testOrPlus(){
	ValueModel<double> v1(2);
	ValueModel<double> v2(3);
	OrPlus<double> am;
	BinaryExpressionModel<double> op(&am,&v1,&v2);
	std::cout << op.Evaluate() << std::endl;
}

void testBinaryShadow(){	//use factories
	ValueModel<double> v1(2);
	ValueModel<double> v2(3);
	AndMin<double> am;
	BinaryShadowExpression<double> bse(&am);
	std::cout << bse.Evaluate(&v1,&v2) << std::endl;
}

void testUnaryShadow(){	//use factories
	ValueModel<double> v1(0.7);
	NotMinus1<double> nm;
	UnaryShadowExpression<double> use(&nm);
	std::cout << use.Evaluate(&v1) << std::endl;
}



void testFactory(){
	ValueModel<double> v1(2);
	ValueModel<double> v2(3);
	NotMinus1<double> opNot;
	AndMin<double> opAnd;
	OrMax<double> opOr;
	ThenMin<double> opThen;
	AggMax<double> opAgg;
	//CogDefuzz<double> opDefuzz(0,40,1);


	FuzzyFactory<double> fifou(&opNot,&opAnd,&opOr, &opThen, &opAgg, NULL);


	double minMauvais=0;
	double midMauvais=10;
	double maxMauvais=20;
	IsTriangle<double> mauvais(minMauvais,midMauvais,maxMauvais);

	double minMoyen=10;
	double midMoyen=20;
	double maxMoyen=30;
	IsTriangle<double> moyen(minMoyen,midMoyen,maxMoyen);

	double minBon=20;
	double midBon=30;
	double maxBon=40;
	IsTriangle<double> bon(minBon,midBon,maxBon);

	double minMauvaises=0;
	double midMauvaises=10;
	double maxMauvaises=20;
	IsTriangle<double> mauvaises(minMauvaises,midMauvaises,maxMauvaises);

	double minMoyennes=10;
	double midMoyennes=20;
	double maxMoyennes=30;
	IsTriangle<double> moyennes(minMoyennes,midMoyennes,maxMoyennes);

	double minBonnes=20;
	double midBonnes=30;
	double maxBonnes=40;
	IsTriangle<double> bonnes(minBonnes,midBonnes,maxBonnes);

	ValueModel<double> scenario(0);
	ValueModel<double> critiques(0);

}
void testCours(){
	NotMinus1<double> opNot;
	AndMin<double> opAnd;
	OrMax<double> opOr;
	ThenMin<double> opThen;
	AggMax<double> opAgg;
	CogDefuzz<double> opDefuzz(0,25,1);

	FuzzyFactory<double> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	double min1=-5, min2=0, min3=5, min4=0, min5=10, min6=20;
	double mid1=0, mid2=5, mid3=10, mid4=5, mid5=15, mid6=25;
	double max1=5, max2=10, max3=15, max4=10, max5=20, max6=30;

	IsTriangle<double> poor(min1,mid1,max1);
	IsTriangle<double> good(min2,mid2,max2);
	IsTriangle<double> excellent(min3,mid3,max3);

	IsTriangle<double> cheap(min4,mid4,max4);
	IsTriangle<double> average(min5,mid5,max5);
	IsTriangle<double> generous(min6,mid6,max6);

	ValueModel<double> service(0);
	ValueModel<double> tips(0);

	Expression<double> *r = f.newAgg(f.newAgg(f.newThen(f.newIs(&poor,&service),f.newIs(&cheap,&tips)),
	f.newThen(f.newIs(&good,&service),f.newIs(&average,&tips))),f.newThen(f.newIs(&excellent,&service),f.newIs(&generous,&tips)));

	//defuzzification
	Expression<double> *system = f.newDefuzz(&tips, r);

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
