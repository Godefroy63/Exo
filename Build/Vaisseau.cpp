#include "Vaisseau.h"

//Constructeur
Vaisseau::Vaisseau(sf::RenderWindow& window)
{
	//Chargement du png vaisseau dans un sprite
	if (!this->mVaisseauTexture.loadFromFile("Image/vaisseau.png"))
	{
		//Message d'erreur
		std::cout << "Erreur dans le chargement du vaisseau " << std::endl;
	}
	else
	{
		this->mVaisseauSprite.setTexture(this->mVaisseauTexture);
		this->mVaisseauSprite.setOrigin(this->mVaisseauTexture.getSize().x / 2, this->mVaisseauTexture.getSize().y / 2);

	}

	//Chargement du png propulseur dans un sprite
	if (!this->mPropulseurTexture.loadFromFile("Image/propulseur.png"))
	{
		//Message d'erreur
		std::cout << "Erreur du propulseur " << std::endl;
	}
	else
	{
		this->mPropulseurSprite.setTexture(this->mPropulseurTexture);
		this->mPropulseurSprite.setOrigin(this->mVaisseauTexture.getSize().x / 2 , this->mVaisseauTexture.getSize().y / 2);

	}


	//Placement du vaisseau au milieu de l'ecran
	this->mPostionVaisseau.x =  window.getSize().x / 2;
	this->mPostionVaisseau.y =  window.getSize().y / 2;

	//Placement du propulseur
	this->mPostionVaisseau.x ; 
	this->mPostionVaisseau.y ;

	this->mAngle = -90.f;
	this->mVelocite.x = 3.0f;
	this->mVelocite.y = 3.0f;
	this->mVitesse = 0.1f;
	this->mPropulseur = false;

}

//Methode
void Vaisseau::drawVaisseau(sf::RenderWindow& window)
{
	//postionnement du sprite
	this->mVaisseauSprite.setPosition(sf::Vector2f(this->mPostionVaisseau.x, this->mPostionVaisseau.y));
	this->mVaisseauSprite.setRotation(this->mAngle);
	//Dessin du sprite sur le l'ecran
	window.draw(this->mVaisseauSprite);

	//si propulseur est activé
	if (this->mPropulseur == true)
	{
		//postionnement du sprite
		this->mPropulseurSprite.setPosition(sf::Vector2f(this->mPostionVaisseau.x, this->mPostionVaisseau.y));
		this->mPropulseurSprite.setRotation(this->mAngle);
		//Dessin du sprite sur le l'ecran
		window.draw(this->mPropulseurSprite);
	}
	
}

void Vaisseau::deplacement(Input input)
{
	float AngleRadian;
	sf::Vector2f force;


	this->mVitesse += 0.1f;

	if(this->mVitesse > 3.0f)
		this->mVitesse = 3.0f;

	AngleRadian = (this->mAngle * PI) / 180;
	force.x = cos(AngleRadian) * this->mVitesse;
	force.y = sin(AngleRadian) * this->mVitesse;

	
	/*if (this->mVelocite.y >= 1.5f)
		this->mVelocite.y = 1.5f;

	if (this->mVelocite.y <= -1.5f)
		this->mVelocite.y = -1.5f;*/

	if (input.getButton().up == false)
	{
		this->mVitesse = 0.0f;
		this->mPropulseur = false;
		this->mVelocite.y += 0.06;
		this->mPostionVaisseau.y += this->mVelocite.y;
	}

	if (input.getButton().up == true)
	{
		
		this->mVelocite.y = force.y;
		this->mVelocite.x = force.x;

		this->mPropulseur = true;
		this->mPostionVaisseau.y += this->mVelocite.y;
		this->mPostionVaisseau.x += this->mVelocite.x;
		
	}

	if (input.getButton().right == true)
	{
		this->mAngle += 2.0f;
	}

	if (input.getButton().left == true)
	{
		this->mAngle -= 2.0f;
	}
}