#include "Input.h"

//constructeur
Input::Input()
{
	this->button.left = this->button.right = this->button.up = this->button.down = false;
}

//Acceseurs

Input::Button Input::getButton() const
{
	return this->button;
}


//Methode

void Input::getInput(sf::RenderWindow& window)
{
    // Tant qu'il y a des �v�nements � traiter...
    while (window.pollEvent(event))
    {
        // on regarde le type de l'�v�nement...
        switch (event.type)
        {
            // On ferme la fen�tre
        case sf::Event::Closed:
            window.close();
            break;

            // Touche press�e
        case sf::Event::KeyPressed:
            switch (this->event.key.code) // La touche qui a �t� press�e
            {
            case sf::Keyboard::Escape: // Echap
                window.close();
                break;

            case sf::Keyboard::Left:
                this->button.left = true;
                break;

            case sf::Keyboard::Right:
                this->button.right = true;
                break;

            case sf::Keyboard::Down:
                this->button.down = true;
                break;

            case sf::Keyboard::Up:
                this->button.up = true;
                break;

            default:
                break;
            }
        break;

            // Touche rel�ch�e
        case sf::Event::KeyReleased:
            switch (this->event.key.code)
            {

            case sf::Keyboard::Left:
                this->button.left = false;
                break;

            case sf::Keyboard::Right:
                this->button.right = false;
                break;

            case sf::Keyboard::Down:
                this->button.down = false;
                break;

            case sf::Keyboard::Up:
                this->button.up = false;
                break;

            default:
                break;
            }
        break;

        default:
            break;
        }
    }
}