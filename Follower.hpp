#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Follower.hpp"

constexpr float sliced_time = 0.08;
constexpr float one_degree  = M_PI / 180.;

struct Animation_setting {
	int initial_pos_x_;
	int final_pos_x_;
	int incr_x_;
};

class Follower {
private:
	sf::Clock clock;
	sf::IntRect rect_;
	const int shift_x_from_leader_;
	const int shift_y_from_leader_;
	const Animation_setting animation_setting_;
	sf::Texture image_;
	sf::Sprite  sprite_;

public:
	Follower(const std::string &path, const Animation_setting &animation_seting, 
	const int &shift_x_from_leader, const int &shift_y_from_leader,
	const int &width, const int &height,
	const float &scale);

	void speedUp();
	void speedDown();

	float get_dx(const float &angle) const;
	float get_dy(const float &angle) const;

	const sf::Sprite &get_sprite() const;

	void turn(const float &angle);

	void move(const float &x, const float &y, const float &angle);
	
	void draw(sf::RenderWindow &app);

};