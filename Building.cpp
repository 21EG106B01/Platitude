#pragma once
#include "Building.h"

void Building::show_stats() {
	 std::cout << buildName << std::endl;
	 std::cout << "Dimensions: " << width << " x " << length << std::endl;
	 std::cout << "Building Type: " << buildType << std::endl;
	 std::cout << "Production Type: " << std::endl;
	 for (const auto& production : productions) {
		 std::cout << "\t" << production.first << " : " << production.second << std::endl;
	 }
	 std::cout << std::endl;
}

void Building::set_icon() {
	std::cout << "Icon set";
}

std::vector<Building> Building::createBuildingStore() {

    std::vector<Building> allBuildings;

    std::map<std::string, int> woodProductionTypes = { {"Rod", 2}, {"Plank", 5}, {"Wheel", 8} };
    std::map<std::string, int> stoneProductionTypes = { {"Gravel", 3}, {"Block", 5}, {"Tool Head", 10}, {"Weapon Head", 10} };
    std::map<std::string, int> ironProductionTypes = { {"Rod", 3}, {"Ingot", 5}, {"Tool Head", 15}, {"Weapon Head", 15} };
    std::map<std::string, int> goldProductionTypes = { {"Coin", 1 }, {"Ingot", 5} };
    std::map<std::string, int> foodProductionTypes = { {"Berries", 5}, {"Potato", 10}, {"Wheat", 20} };
    std::map<std::string, int> fishProductionTypes = { {"Sardines", 1}, {"Tuna", 5}, {"Tropical Fish", 10}, {"Lobster", 35} };
    std::map<std::string, int> leatherProductionTypes = { {"Sheep Skin", 5}, {"Goat Skin", 5}, {"Cow Leather", 10}, {"Bear Fur", 40} };

    Building woodcutterLodge(2, 2, "Woodcutter's Lodge", "Wood", woodProductionTypes);
    allBuildings.push_back(woodcutterLodge);
    Building stoneQuarry(3, 3, "Stone Quarry", "Mine", stoneProductionTypes);
    allBuildings.push_back(stoneQuarry);
    Building ironMine(2, 2, "Iron Mine", "Mine", ironProductionTypes);
    allBuildings.push_back(ironMine);
    Building goldMine(2, 2, "Gold Mine", "Mine", goldProductionTypes);
    allBuildings.push_back(goldMine);
    Building farm(1, 1, "Farm", "Food", foodProductionTypes);
    allBuildings.push_back(farm);
    Building fishingLodge(2, 2, "Fishing Lodge", "Food", fishProductionTypes);
    allBuildings.push_back(fishingLodge);
    Building leatherHut(1, 1, "Leather Hut", "Cloth", leatherProductionTypes);
    allBuildings.push_back(leatherHut);

    return allBuildings;
}
