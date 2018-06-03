#include <iostream>
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(600, 300), "Doom 7 alpha");


    // --- Setting up circle settings (all can be applied to rectangle too) ---
    sf::CircleShape circle(10, 10); // radius, sides (30 sides default)
    circle.setPosition(100, 100);
    circle.setRadius(50);
    circle.setPointCount(30); // 3 makes circle triangle
//    circle.setFillColor(sf::Color(255,0,0));
//    circle.setOutlineColor(sf::Color(0,255,0));
//    circle.setOutlineThickness(-1);

    
    // --- Setting up circle texture ---
    sf::Texture texture;
    if (!texture.loadFromFile("texture.png")) // On Mac file needs to be in same folder as "Products/shapes executable" (on Windows, relative to main.cpp)
    {
        std::cout << "texture load fail" << std::endl;
        return EXIT_FAILURE;
    }
    circle.setTexture(&texture);
    circle.setTextureRect(sf::IntRect(0,0,700,700)); // x,y start and end

    
    // --- Rectangle ---
    sf::RectangleShape rectangle(sf::Vector2f(100,100));
    rectangle.setSize(sf::Vector2f(200,100));
    sf::Texture texture2;
    texture2.loadFromFile("texture2.png");
    rectangle.setTextureRect(sf::IntRect(0,0,600,300)); // x,y start and end
    rectangle.setTexture(&texture2);
    rectangle.setPosition(200, 100);
    
    
    // --- Convex polygon ---
    // set points in clockwise/anticw order to get normal shape
    sf::ConvexShape convex(4);
//    convex.setPointCount(10);
    convex.setPoint(0, sf::Vector2f(420,200));
    convex.setPoint(1, sf::Vector2f(480,100));
    convex.setPoint(2, sf::Vector2f(500,200));
    convex.setPoint(3, sf::Vector2f(450,250));
    convex.setTexture(&texture2);
    
    
    // --- Line ---
    sf:: Vertex line[] // Array of vertexes
    {
        sf::Vertex(sf::Vector2f(100,220)), // x,y of a point or vertex
        sf::Vertex(sf::Vector2f(400,250))
    };
    line[0].color = sf::Color::Cyan;
    line[1].color = sf::Color::Red;
    line[1].position = sf::Vector2f(380,280);
    
    // --- Window and update loop ---
    while (window.isOpen())
    {
//        window.setFramerateLimit(60);
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed: // Window close event triggered
                    window.close();
                    break;
                default:
                    break;
            }
        }
        window.clear();

        
        // Draw stuff here, between clear and display
        window.draw(circle);
        window.draw(rectangle);
        window.draw(convex);
        window.draw(line, 2, sf::Lines); // number of vertexes = 2
        
        
        window.display();
    }
    return 0;
}
