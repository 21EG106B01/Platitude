#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Button
{
private:
	int x, y, width, height, textsize;
	std::string btntype;
	sf::Font fonttype;
	sf::Text text;
	sf::Sprite background, image;
	sf::Texture background_tex, image_tex;
public:
	bool selected;
	Button(int bx, int by, int bwidth, int bheight, int btextsize, std::string bbtntype, std::string btext, std::vector<sf::Sprite*>& sprite_elements, std::vector<sf::Text*>& text_elements, sf::Font* bfonttype);
	std::string getText();
	sf::FloatRect getGlobalBounds();
	void set_sprite(std::string path);
	void setTexture(const sf::Texture& texture);
	void setTexture(std::string path);
	void setColor(sf::Color color);
	void setPosition(float bx, float by);
	void setSize(float bwidth, float bheight);
	bool isClicked(const sf::RenderWindow& window) const;
	void disp_attr();
};

