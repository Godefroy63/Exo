#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>


class Input
{
	//Attribus
	struct Button { bool up, down, left, right; };


public:

	//Constructeur
	Input();

	//Acesseur
	Button getButton() const;

	//Mutateur
	void setButton(int Button, bool etat);

	//Methode

	//void gestionInputs(sf::RenderWindow& window);
	void getInput(sf::RenderWindow& window);


private:

	//Attribut
	sf::Event event;
	Button button;
	

	const enum { up, down, left, right};

};

#endif // !INPUT_H

