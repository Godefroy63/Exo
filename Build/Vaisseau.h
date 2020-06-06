#ifndef VAISSEAU_H
#define VAISSEAU_H

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "Input.h"


const float PI{ 3.14159265358979323846 };


class Vaisseau
{
	public :

	//Constructeur
		Vaisseau(sf::RenderWindow& window);

	//Accesseur

	//Mutateur

	//Methode
	void drawVaisseau(sf::RenderWindow& window);
	void deplacement(Input input);

	private:

	//Atribut
	sf::Texture mVaisseauTexture;
	sf::Texture mPropulseurTexture;
	sf::Sprite mVaisseauSprite;
	sf::Sprite mPropulseurSprite;

	sf::Vector2f mPostionVaisseau;
	sf::Vector2f mPostionPropulseur;
	sf::Vector2f mVelocite;
	float mAngle,mVitesse;
	bool mPropulseur;

	



};













#endif // !VAISSEAU_H




