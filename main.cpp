#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Leader.hpp"
#include "Follower.hpp"

using namespace std;
using namespace sf;


int main() {
	// Fenêtre
	const Vector2u WINDOW_SIZE(800, 600);
	
	RenderWindow app(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y, 32), "My Camera");

	// Frames Per Second (FPS)
	app.setFramerateLimit(60); // limite la fenêtre à 60 images par seconde

	Texture backgroundImage;
	Sprite backgroundSprite;
	if (!backgroundImage.loadFromFile("../img/background.png")) {
	 	cerr << "Cannot load image file : " << "../img/background.png" << endl;
	 	return EXIT_FAILURE; // On ferme le programme
	}
	
	backgroundSprite.setTexture(backgroundImage);



	// Fond d'écran
	// Texture backgroundImage, carImage, runnerImage, circleImage;
	// Sprite backgroundSprite, carSprite, runnerSprite, circleSprite;

	// if (!backgroundImage.loadFromFile("../img/background.png") ||
	// 	!carImage.loadFromFile("../img/car.png") ||
	// 	!runnerImage.loadFromFile("../img/runner.png")||
	// 	!circleImage.loadFromFile("../img/sprites_final.png")) {
	// 	cerr << "Erreur pendant le chargement des images" << endl;
	// 	return EXIT_FAILURE; // On ferme le programme
	// }

	// backgroundSprite.setTexture(backgroundImage);
	// carSprite.setTexture(carImage);
	// carSprite.setPosition(sf::Vector2f(20, 34));
	// carSprite.setScale(sf::Vector2f(0.5, 0.5));
	// Car car(790, 1215, 0, 0);

/********************************/
	sf::IntRect rect_runner;


	int runner_initial_pos_x = 204;
 	int runner_final_pos_x = 1024;
	int runner_incr_x = 102;

	Animation_setting animation_runner = {204, 1024, 102 };

	Follower runner("../img/runner.png", animation_runner, 50, 10,	102, 115, 0.3f);
/********************************/
/********************************/
	sf::IntRect rect_circle;

	int circle_initial_pos_x = 0;
 	int circle_final_pos_x = 7500;
	int circle_incr_x = 300;

	Animation_setting animation_circle = {0, 7500, 300};

	rect_circle.top = 0;
	rect_circle.left = 0;

	rect_circle.width = 300;
	rect_circle.height = 300;

	constexpr int shift_x_circle = 100;
	constexpr int shift_y_circle = 10;

	Follower circle("../img/sprites_final.png", animation_circle, 
	100, 10, 300, 300, 0.15f);

/********************************/

	Leader car("../img/car.png", 790, 1215);

	Vector2f center(car.getX(), car.getY());

	Vector2f halfSize(WINDOW_SIZE.x / 2.f, WINDOW_SIZE.y / 2.f);

	View view(center, halfSize);

	app.setView(view);
	
	while (app.isOpen()) // Boucle principale
	{
		Event event;
		while (app.pollEvent(event)) // Boucle des évènements de la partie pause
		{
			if ((event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == Event::Closed)
			{
				app.close();
			}
		}

		car.move();
		view.setCenter(car.getX(), car.getY());

		app.setView(view);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	{
			car.turnLeft();
			// carSprite.setRotation(car.getAngle());
			// runnerSprite.setRotation(car.getAngle());
			// circleSprite.setRotation(car.getAngle());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			car.turnRight();
			// carSprite.setRotation(car.getAngle());
			// runnerSprite.setRotation(car.getAngle());
			// circleSprite.setRotation(car.getAngle());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			car.speedUp();
			// runner.speedUp();
			// circle.speedUp();
		}
		else
		{
			car.speedDown();
			// runner.speedDown();
			// circle.speedDown();
		}

		// Affichages
		app.clear();
		app.draw(backgroundSprite);

		car.draw(app);

		// carSprite.setPosition(car.getX(), car.getY());
		// runnerSprite.setPosition(runner.getX(), runner.getY());
		// runnerSprite.setTextureRect(rect_runner);
		// circleSprite.setPosition(circle.getX(), circle.getY());
		// circleSprite.setTextureRect(rect_circle);
		// app.draw(carSprite);
		// app.draw(runnerSprite);
		// app.draw(circleSprite);

		app.display();
	}

	return EXIT_SUCCESS;
}
