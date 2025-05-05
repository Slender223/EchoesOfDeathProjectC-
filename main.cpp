#include "Intro.h"
#include "GameLoader.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "shadowStrikes.h"
#include "MourningSky.h"
#include <SFML/Audio.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1600,1600), "Murder Mystery!!!");
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;
    sf::Music music;
    Player player;


    if (!music.openFromFile("Ghost-Story(chosic.com).wav")) {
    cerr << "Error: Could not load music file!" << std::endl;
    return -1;
    }
    music.setLoop(true);
    music.play();
    //Create instance of GameLoader 
    GameLoader loader(window, texture, sprite, text);
    if(loader.Load(window, texture, sprite,text) == -1){
        cout << "Error loading Game..." << endl;
        return -1;
    }

    Intro intro(window, texture, sprite);
    if (intro.StartIntro(window, texture, sprite) == -1) {
        cout << "Error loading Intro..." << endl;
        return -1;
    }
    
    Level1 lvl1(window, texture, sprite, text, player);
    if (lvl1.play(window, texture, sprite, text)) {
        cout << "Error loading Level1..." << endl;
        return -1;
    }
    

    Level2 level2(window, texture, sprite, text, player);
    if (level2.play(window, texture, sprite, text) == -1) {
        cout << "Error loading Level2..." << endl;
       return -1;
    }

    Level3 level3(window, sprite, texture, player);
    if (level3.start(window, sprite, texture) == -1) {
        cout << "Error loading Level3..." << endl;
        return -1;
    }

}

