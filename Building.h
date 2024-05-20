#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

using std::map;
class Building
{

private:
	int width, length;
	std::string buildName;
	std::string buildType;
	map<std::string, int> productions;
	sf::Sprite buildingIcon;

public:
	Building(int bwidth, int blength, std::string bbuildName, std::string bbuildType, const map<std::string, int>& bproductions) : width(bwidth), length(blength),buildName(bbuildName), buildType(bbuildType), productions(bproductions){}
	void set_icon(std::string path);
	void show_stats();
	static std::vector<Building*> createBuildingStore();

};

