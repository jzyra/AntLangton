/*!
	* \file AntLangton.hpp
	* \brief Class for represent ant langton.
	* \author Jeremy ZYRA
	* \version 1.0
*/
#ifndef ANTLANGTON_H
#define ANTLANGTON_H

#include <iostream>
#include "Config.hpp"

//Possible directions of the ant.
#define O_UP     0
#define O_RIGHT  1
#define O_DOWN   2
#define O_LEFT   3
using namespace std;

class AntLangton {

	public:
	/*!
		* \brief AntLangton Constructor.
		Config class's constructor.
		* \param configuration object.
	*/
	AntLangton(const Config &config);
	/*!
		* \brief AntLangton Destructor.
		Config class's destructor.
	*/
	~AntLangton();
	/*!
		* \brief Update next cellulars's positions.
	*/
	void iterate();
	/*!
		* \brief Accessor on cellulars's matrice.
		* \return Stat matrice.
	*/
	bool **getMatrice() const;
	/*!
		* \brief Accessor on ant's position in x axis.
		* \return Ant's position in x axis.
	*/
	int getXAnt() const;
	/*!
		* \brief Accessor on ant's position in y axis.
		* \return Ant's position in y axis.
	*/
	int getYAnt() const;

	private:
	bool **_matrice;
	int _height;
	int _width;
	int _antOrientation;
	int _xAnt;
	int _yAnt;

};

#endif
