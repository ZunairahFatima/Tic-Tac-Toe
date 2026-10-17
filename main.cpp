#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
int main(){
    RenderWindow window(VideoMode({800,600}),"Tic Tac Toe");
    window.setFramerateLimit(60);

    Texture backgroundtexture;
    if(backgroundtexture.loadFromFile("assets/WelcomeScreen.png")==false){
        cout<<"no";
        return 1;
    }

    Sprite background(backgroundtexture);
    background.setPosition({0.f,0.f});
    background.setScale({
        800.f/backgroundtexture.getSize().x,
        600.f/backgroundtexture.getSize().y
     });

    Font font;
    if(font.openFromFile("assets/font.ttf")==false){
        return 1;
    }
    Text title(font,"Tic Tac Toe");
    title.setCharacterSize(70);
    title.setFillColor(Color(255,211,0));
    title.setPosition({210.f,90.f});
    title.setStyle(Text::Bold);

    Text pvpText(font, "Player vs Player");
    pvpText.setCharacterSize(30);
    pvpText.setFillColor(Color::White);
    pvpText.setPosition({260.f,230.f});
    pvpText.setStyle(Text::Bold);

    Text cvpText(font, "Computer vs Player");
    cvpText.setCharacterSize(30);
    cvpText.setFillColor(Color::White);
    cvpText.setPosition({240.f,320.f});
    cvpText.setStyle(Text::Bold);

    RectangleShape pvp;
    pvp.setSize({310,60});
    pvp.setPosition({240,220});
    pvp.setFillColor(Color(252,240,167));

     RectangleShape cvp;
    cvp.setSize({320,60});
    cvp.setPosition({240,310});
    cvp.setFillColor(Color(252,240,167));
    
    while(window.isOpen()){
         while(const optional event = window.pollEvent()){
            if(event->is<Event::Closed>()){
                window.close();
            }
            if (const auto* mouseEvent =
                    event->getIf<Event::MouseButtonPressed>())
            {
                if (mouseEvent->button == Mouse::Button::Left)
                {
                    Vector2f mousePosition({
                        static_cast<float>(mouseEvent->position.x),
                        static_cast<float>(mouseEvent->position.y)
                    });
                    if (pvp.getGlobalBounds().contains(mousePosition)){
                        continue;
                    }
                    if (cvp.getGlobalBounds().contains(mousePosition)){
                        continue;
                    }
                           
                }

                
            }
         }
         window.clear(Color::Black);
         window.draw(background);
         window.draw(title);
         window.draw(pvp);
         window.draw(cvp);
         window.draw(pvpText);
         window.draw(cvpText);
         window.display();
    }
    return 0;
}