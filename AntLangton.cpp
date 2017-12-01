#include "AntLangton.hpp"

AntLangton::AntLangton(const Config &config) {
	cellular_t *cellulars = config.getCellulars();
	_height = config.getYNb();
	_width = config.getXNb();
	//Init matrice.
	_matrice = (bool **)malloc(_height*sizeof(bool *));
	for (int i=0; i < _height; ++i) {
		_matrice[i] = (bool *)malloc(_width*sizeof(bool));
	}
	for (int i=0; i < _height; ++i) {
		for (int j=0; j < _width; ++j) {
			_matrice[i][j] = true;
		}
	}
	//Init cellulars's positions.
	for (int i=0; i < config.getSize(); ++i) {
		_matrice[cellulars[i].y][cellulars[i].x] = cellulars[i].dead;	
	}
	//Init ant position.
	_antOrientation = 0;
	_xAnt = config.getXAnt();
	_yAnt = config.getYAnt();
}

AntLangton::~AntLangton() {
	for (int i=0; i < _height; ++i) {
		free(_matrice[i]);
	}
	free(_matrice);
}

void AntLangton::iterate() {
	//If Ant's orientation is up.
	if (_antOrientation == O_UP) {
		int x = _xAnt;
		//If ant is in black cell, she move to left.
		if (_matrice[_xAnt][_yAnt]) {
			x = (x-1 < 0) ? _width-1 : x-1;
			_antOrientation = O_LEFT;
			//If ant is in black cell, she move to right.
		} else {
			x = (x+1 > _width-1) ? 0 : x+1;
			_antOrientation = O_RIGHT;
		}
		_xAnt = x;
		_matrice[x][_yAnt] = !_matrice[x][_yAnt];
	//If Ant's orientation is right.
	} else if (_antOrientation == O_RIGHT) {
		int y = _yAnt;
		//If ant is in black cell, she move to left.
		if (_matrice[_xAnt][_yAnt]) {
			y = (y-1 < 0) ? _height-1 : y-1;
			_antOrientation = O_UP;
		//If ant is in black cell, she move to right.
		} else {
			y = (y+1 > _height-1) ? 0 : y+1;
			_antOrientation = O_DOWN;
		}
		_yAnt = y;
		_matrice[_xAnt][y] = !_matrice[_xAnt][y];
	//If Ant's orientation is bottom.
	} else if (_antOrientation == 2) {
		int x = _xAnt;
		//If ant is in black cell, she move to left.
		if (_matrice[_xAnt][_yAnt]) {
			x = (x+1 > _width-1) ? 0 : x+1;
			_antOrientation = O_RIGHT;
		//If ant is in black cell, she move to right.
		} else {
			x = (x-1 < 0) ? _width-1 : x-1;
			_antOrientation = O_LEFT;
		}
		_xAnt = x;
		_matrice[x][_yAnt] = !_matrice[x][_yAnt];
	//If Ant's orientation is left.
	} else {
		int y = _yAnt;
		//If ant is in black cell, she move to left.
		if (_matrice[_xAnt][_yAnt]) {
			y = (y+1 > _height-1) ? 0 : y+1;
			_antOrientation = O_DOWN;
		//If ant is in black cell, she move to right.
		} else {
			y = (y-1 < 0) ? _height-1 : y-1;
			_antOrientation = O_UP;
		}
		_yAnt = y;
		_matrice[_xAnt][y] = !_matrice[_xAnt][y];
	}
}

int AntLangton::getXAnt() const {
	return _xAnt;
}

int AntLangton::getYAnt() const {
	return _yAnt;
}

bool **AntLangton::getMatrice() const {
	return _matrice;
}
