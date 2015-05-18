/*
 * Evaluator.h
 *
 *  Created on: 18 mai 2015
 *      Author: gael
 *
 *      D'après le .pdf du cours page 36 à 37
 */

#ifndef CORE_EVALUATOR_H_
#define CORE_EVALUATOR_H_

#include <vector>

namespace core {
	template <class T>
	class Evaluator {
	public:
		typedef std::pair< std::vector<T>, std::vector<T> > Shape;

		static Shape BuildShape(const T& min, const T& max, const T& step, ValueModel<T>*, Expression<T>*);
		static std::ostream& PrintShape(std::ostream& o, const Shape& s);

	};

	/*
	 * Construit la forme finale suivant la méthode choisi (min-max)
	 * 	v : la sortie
	 *  e : le système de règle
	 */
	template <class T>
	typename Evaluator<T>::Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step, ValueModel<T>* v, Expression<T>* e) {
		std::vector<T> x , y;
		T mem = v-> Evaluate();

		for(T i = min ; i<= max ; i += step) {
			v->setValue(i);
			x.push_back(i);
			y.push_back(e->Evaluate());
		}
		v->setValue(mem);	// on rend sa valeur init à v
		return Shape(x, y);
	}

	/*
	 * Gestion de l'affichage
	 */
	template <class T>
	std::ostream& Evaluator<T>::PrintShape(std::ostream& os, const Shape& s) {
		os << '[';
		typename std::vector<T>::const_iterator it = s.first.begin();
		for(; it!=s.first.end(); ++it) {
			os << *it << ' ';
		}
		os << ']';
		os << std::endl;
		os << '[';
		it = s.second.begin();
		for(; it!=s.second.end(); ++it) {
			os << *it << ' ';
		}
		os << ']';
		return os;
	}
}

#endif /* CORE_EVALUATOR_H_ */
