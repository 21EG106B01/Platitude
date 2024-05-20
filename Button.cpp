#include "Button.h"
#include <iostream>

Button::Button(int bx, int by, int bwidth, int bheight, int btextsize, std::string bbtntype, std::string btext, std::vector<sf::Sprite*>& sprite_elements, std::vector<sf::Text*>& text_elements, sf::Font* bfonttype = nullptr) {
	x = bx;
	y = by;
	width = bwidth;
	height = bheight;
	textsize = btextsize;
	btntype = bbtntype;
	if (bfonttype != nullptr)
		fonttype = *bfonttype;
	set_sprite(btntype);
	background.setScale(width / background.getGlobalBounds().width, height / background.getGlobalBounds().height);
	sprite_elements.push_back(&background);
	if (image_tex.loadFromFile(btext)) {
		image.setTexture(image_tex);
		sprite_elements.push_back(&image);
	}
	else {
		text.setString(btext);
		text.setFont(fonttype);
		text.setCharacterSize(textsize);
		text_elements.push_back(&text);
	}
	setPosition(x, y);
}

std::string Button::getText() {
	return text.getString();
}

sf::FloatRect Button::getGlobalBounds() {
	return background.getGlobalBounds();
}

void Button::set_sprite(std::string path) {
	if (path == "buildingbtn")
		background_tex.loadFromFile("resources/images/Interface/buildingbtn.png");
	else if (path == "buildselectorbtn")
		background_tex.loadFromFile("resources/images/Interface/buildselectbtn.png");
	else if (path == "mainmenubtn")
		background_tex.loadFromFile("resources/images/Interface/mainmenubtn.png");
	else if (path == "menubtn")
		background_tex.loadFromFile("resources/images/Interface/menubtn.png");
	else if (path == "pausemenubtn")
		background_tex.loadFromFile("resources/images/Interface/pausemenubtn.png");
	background.setTexture(background_tex);
}

void Button::setTexture(const sf::Texture& texture) {
		background.setTexture(texture);
}

void Button::setTexture(std::string path) {
	sf::Texture tex;
	tex.loadFromFile(path);
	background.setTexture(tex);
}

void Button::setColor(sf::Color color) {
	background.setColor(color);
	sf::Color textcolor = text.getFillColor();
	if (color.a < 255) textcolor.a = 150;
	else textcolor.a = 255;
	text.setFillColor(textcolor);
}

void Button::setPosition(float bx, float by) {
	x = bx;
	y = by;
	background.setPosition(bx, by);
	if (image.getTexture() != nullptr) {
		sf::FloatRect contentBounds = image.getLocalBounds();
		float offsetX = (background.getGlobalBounds().width - contentBounds.width) / 2.0f;
		float offsetY = (background.getGlobalBounds().height - contentBounds.height) / 2.0f;
		image.setPosition(background.getPosition().x + offsetX, background.getPosition().y + offsetY);
	}
	else {
		text.setOrigin(0, 0);
		sf::FloatRect contentBounds = text.getLocalBounds();
		float offsetX = (background.getGlobalBounds().width - contentBounds.width) / 2.0f;
		float offsetY = (background.getGlobalBounds().height - contentBounds.height) / 2.0f;
		text.setPosition(background.getPosition().x + offsetX - text.getLocalBounds().left, background.getPosition().y + offsetY - text.getLocalBounds().top);
	}
}

void Button::setSize(float bwidth, float bheight) {
	background.setScale(bwidth / width, bheight / height);
	Button::setPosition((width - bwidth) / 2, (height - bheight) / 2);
	width = bwidth;
	height = bheight;
}

bool Button::isClicked(const sf::RenderWindow& window) const {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::FloatRect buttonBounds(x, y, width, height);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonBounds.contains(static_cast<sf::Vector2f>(mousePos))) 
			return true;
	return false;
}

void Button::disp_attr() {
	std::cout << x << '\t' << y << '\t' << width << '\t' << height << '\t' << textsize;
	std::cout << '\n' << btntype;
	std::cout << '\n' << text.getString().toAnsiString();
	std::cout << '\n' << text.getGlobalBounds().getPosition().x << ',' << text.getGlobalBounds().getPosition().y;
	std::cout << '\n' << fonttype.getInfo().family;
	std::cout << '\n' << background.getPosition().x << " " << background.getPosition().y;
}