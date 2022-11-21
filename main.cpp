#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace sf;

void bubbleSort(std::vector<RectangleShape> &rectangleShapes){

    for (int i = 0; i < rectangleShapes.size()-1; ++i) {
//        sleep(microseconds(1000));


        for (int j = 0; j < rectangleShapes.size()-i-1; ++j) {
            sleep(microseconds(1000));


            rectangleShapes.at(j).setFillColor(Color(rectangleShapes.at(j).getSize().y, 0, 110));
            rectangleShapes.at(j+1).setFillColor(Color(rectangleShapes.at(j+1).getSize().y, 0, 110));



//              std::this_thread::sleep_for(std::chrono::microseconds(1000));
            if (rectangleShapes.at(j).getSize().y > rectangleShapes.at(j+1).getSize().y) {

                Vector2f tmpPos = rectangleShapes.at(j).getPosition();
                rectangleShapes.at(j).setPosition(rectangleShapes.at(j + 1).getPosition());
                rectangleShapes.at(j + 1).setPosition(tmpPos);

                RectangleShape tmpRect = rectangleShapes.at(j);
                rectangleShapes.at(j) = rectangleShapes.at(j+1);
                rectangleShapes.at(j+1) = tmpRect;

            }
            rectangleShapes.at(j).setFillColor(Color::White);


        }
    }

}

void shuffle(std::vector<RectangleShape> &rectangleShapes){

    for (int i = 0; i < rectangleShapes.size(); ++i) {
//        rectangleShapes.at(i).setFillColor(Color(rectangleShapes.at(i).getSize().y, 0, 110));
    }
    int s = rectangleShapes.size()-1;
    for (int i = 0; i < s; ++i) {
        int r = rand()%s;

        Vector2f tmpPos = rectangleShapes.at(i).getPosition();
        rectangleShapes.at(i).setPosition(rectangleShapes.at(r).getPosition());
        rectangleShapes.at(r).setPosition(tmpPos);

        RectangleShape tmpRect = rectangleShapes.at(i);
        rectangleShapes.at(i) = rectangleShapes.at(r);
        rectangleShapes.at(r) = tmpRect;
    }
}

int main() {
    RenderWindow window(VideoMode(800,400),"Sort");
    std::vector<RectangleShape> rectangleShapes;

    for (double i = 0; i < window.getSize().x; i+=4) {
        // tu zmienic i+= na 1 i ponizej Vector2f x na 1 albo cos takiego
        RectangleShape rectangleShape(Vector2f(3, (int)i%255));
//        RectangleShape rectangleShape(Vector2f(2, rand()%255));
        rectangleShape.setOrigin(0,rectangleShape.getSize().y);
        rectangleShape.setPosition(i, window.getSize().y);
        rectangleShapes.push_back(rectangleShape);
    }

    shuffle(rectangleShapes);

    while (window.isOpen()){
        Event e;

        while (window.pollEvent(e)){
            if (e.type == Event::MouseButtonPressed) {
                if (e.mouseButton.button == Mouse::Left) {

                    std::thread th { [&rectangleShapes](){
                        bubbleSort(rectangleShapes);
                    }};

                    th.detach();
//                    sort(rectangleShapes);
                    for (auto& rectangle : rectangleShapes)
                        std::cout << rectangle.getSize().x << " " << rectangle.getSize().y << std::endl;
                }
            }

            if (e.type == Event::Closed){
                window.close();
            }
        }
        window.clear(Color::Black);

        for (auto& rect : rectangleShapes)
            window.draw(rect);

        window.display();
    }
    return 0;
}
