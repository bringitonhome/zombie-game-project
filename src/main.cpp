//************************************************
// main.cpp
//************************************************

//Include SFML dependencies
#include <SFML/Graphics.hpp>

//Include dependencies
#include "character.h"
#include "defines.h"
#include "enemy.h"
#include "entitymanager.h"
#include "inputhandler.h"
#include "pickup.h"
#include "solid.h"
#include <stdlib.h>
#include <time.h>
#include "userinterface.h"

//Make this character reference global for now... :/
Character* g_character = NULL;

int main()
{
    srand(time(NULL));
    //Define core resources
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_CAPTION);
    sf::Mouse mouse;

    EntityManager entitymanager(&window, &mouse);
    InputHandler input_handler(&window);
    input_handler.add_observer(&entitymanager);

    window.setFramerateLimit(FRAMELIMIT);

    //Create some test entities
    entitymanager.new_entity(new Character(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
    entitymanager.new_entity(new UserInterface);
    entitymanager.new_entity(new Solid(100, 100));
    long unsigned int enemy_spawn = 0;
    long unsigned int pickup_spawn = 0;

    //Run the game
    while (window.isOpen())
    {
        //Process input
        input_handler.handle_input();

        //Perform game logic
        entitymanager.update_all();
        //DEBUG
        if (enemy_spawn++ >= 100) {
            entitymanager.new_entity(new Enemy(WINDOW_WIDTH+32,rand()%WINDOW_HEIGHT));
            enemy_spawn = 0;
        }
        if (pickup_spawn++ >= 190) {
            entitymanager.new_entity(new Pickup(rand()%(WINDOW_WIDTH/2),rand()%WINDOW_HEIGHT));
            pickup_spawn = 0;
        }

        //Render
        window.clear(sf::Color(192, 192, 192));
        entitymanager.render();

        window.display();
    }

    return 0;
}

