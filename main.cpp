#include "main.h"


int main()
{
    //création de la fenerte
    sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "lender");
    
    //Limite les fps à 60 images / seconde
    window.setFramerateLimit(60);
    //On active la synchro verticale
    window.setVerticalSyncEnabled(true);

    //instance 
    Vaisseau lender(window);
    Input input;

    //Game loop
    while (window.isOpen())
    {
        //Gestion des input
        input.getInput(window);
        lender.deplacement(input);

        window.clear(sf::Color(0, 0, 0));

        //Affichage du vaisseau
        lender.drawVaisseau(window);
        
        window.display();
    }

    return 0;
}



