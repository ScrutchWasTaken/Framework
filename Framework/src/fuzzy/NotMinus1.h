/*
 * NotMinus1.h
 *
 *  Created on: 24 mars 2015
 *      Author: scrutch
 */

#ifndef FUZZY_NOTMINUS1_H_
#define FUZZY_NOTMINUS1_H_
#include "../core/Operators.h"

namespace fuzzy {

template <class T>
class NotMinus1: public core::Not<T>
{
	T Evaluate(core::Expression<T> *) const;
};

template <class T>
T NotMinus1<T>::Evaluate(core::Expression<T> *o) const {
	T res = o->Evaluate();
	res = 1 - res;
	return res;
}

};
#endif /* FUZZY_NOTMINUS1_H_ */

//MAMDANIDEFUZZ:


//MamdaniDefuzz -> binaire car:
//systeme de regles et variable de sortie
//1 construire une forme de maniere recursive sur l'univers de discours
//2 centre de gravite/max des max/ min des max....
// mamdani defuzz: evaluate et defuzz
//defuzz prend en parametre une forme => shape
//evaluate appelle defeuzz
//CogDefuzz redefinit defuzz(shape)

//comment tester les fonctions d'apartenance?
//

//class Evaluator //nom de OUF
//definir ce qu'est une forme
//on prend une collection dynamique
//couple de vecteurs de T::

//typedef pair<std::vector<T>,std::vector<T>> Shape
////2 trucs:
//static Shape buildShape(const T& min, same max,s step, left, right)
//static ostream& printShape(const Shape& ,ostream&)
//comportement de class

//[.........]
//[.........]

//quand il y a du typedef, il faut mettre du typename pour l'appeler.
//accumulate => lib standard


//

