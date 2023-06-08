#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "BinaryTree.h"

void createShapes(BinaryTree& t, std::vector<sf::CircleShape>& circles, std::vector<sf::Text>& strings, sf::Font& font, sf::VertexArray& vertex, int width)
{
    circles.clear();
    strings.clear();
    vertex.clear();

    std::function<void(Node*, int, int)> l = [&](Node* n, int lvl, int i) {
        auto posX = width * i / pow(2, lvl + 1);
        auto posY = 70 + lvl * 95;

        if (n != t.root)
            vertex.append(sf::Vertex(sf::Vector2f(posX, posY)));

        sf::Text text(n->value, font, 21);
        text.setFillColor(sf::Color(0, 0, 0));
        auto textBox = text.getLocalBounds();
        text.setOrigin(textBox.width / 2 + 4, textBox.height / 2 + 7);
        text.setPosition(posX, posY);

        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color(255, 255, 255));
        auto circleBox = circle.getLocalBounds();
        circle.setOrigin(circleBox.width / 2, circleBox.height / 2);
        circle.setPosition(posX, posY);

        circles.push_back(circle);
        strings.push_back(text);

        if (n->nodes[0])
        {
            vertex.append(sf::Vertex(sf::Vector2f(posX, posY)));
            l(n->nodes[0], lvl + 1, i * 2 - 1);
        }
        if (n->nodes[1])
        {
            vertex.append(sf::Vertex(sf::Vector2f(posX, posY)));
            l(n->nodes[1], lvl + 1, i * 2 + 1);
        }
    };

    l(t.root, 0, 1);
}

int main()
{
    int wWidth = 1310;
    int wHeight = 630;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Binary Trees from arithmetic expressions");
    window.setFramerateLimit(60);

    //Создадим дерево
    //BinaryTree t("((12+5)*7-6*11+3)*8");
    BinaryTree t("(12 + 5) * 7 - 6 * (11 + 3) * 8");

    std::vector<sf::CircleShape> circles;
    std::vector<sf::Text> strings;
    sf::Font font;
    font.loadFromFile("Xolonium-Regular.ttf");
    sf::VertexArray vertex(sf::Lines);

    createShapes(t, circles, strings, font, vertex, wWidth);

    sf::Text postOrder(t.POString(), font, 30);
    postOrder.setPosition(sf::Vector2f(0, 0));

    bool keyboardMode = false;

    sf::Text inputText("Press space to change the expression", font, 30);
    inputText.setPosition(sf::Vector2f(0, wHeight - 40));

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
          
            if (event.type == sf::Event::Closed)
                window.close();

           
            if (event.type == sf::Event::KeyPressed)
            {
                
                if (event.key.code == sf::Keyboard::Space)
                {
                    keyboardMode = true;
                    inputText.setString("");
                }
                if (event.key.code == sf::Keyboard::Enter)
                {
                    keyboardMode = false;
                    t.Update(inputText.getString());
                    createShapes(t, circles, strings, font, vertex, wWidth);
                    postOrder.setString(t.POString());
                }
            }

            if (keyboardMode && event.type == sf::Event::TextEntered)
            {
                if (40 <= event.text.unicode && event.text.unicode <= 57 && event.text.unicode != 46 && event.text.unicode != 44)
                    inputText.setString(inputText.getString() + static_cast<char>(event.text.unicode));
                else if (event.text.unicode == 8)
                {
                    auto s = inputText.getString();
                    inputText.setString(s.substring(0, s.getSize() - 1));
                }
            }
        }

        
        window.clear();                 
        
        window.draw(postOrder);

        window.draw(vertex);

        for (auto circle : circles)
        {
           
            window.draw(circle);
        }
        for (auto string : strings)
        {
            
            window.draw(string);
        }

        window.draw(inputText);

        
        window.display();
    }
  
    return 0;
}
