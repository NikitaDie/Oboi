#include "Calculator.h"

Calculator::Calculator()
{
}

void Calculator::pushRoom(Room& r)
{
    this->activeRooms.push_back({ &r });
}

void Calculator::pushWall(int id_room, int wall, Roll& roll)
{
    if (this->activeRooms[id_room].activeWalls.size() > wall) { //check if already exsist
        this->activeRooms[id_room].activeWalls[wall].roll = &roll;
    }
    else {
        this->activeRooms[id_room].activeWalls.push_back({ wall, &roll });
    }
}

void Calculator::calculate(std::vector<Roll>& rolls)
{
    std::map<std::string, float> map;

    for (ActiveRoom& aRoom : activeRooms)
    {
        for (ActiveWall& aWall : aRoom.activeWalls)
        {
            std::string rollTitle = aWall.roll->getTitle();
            float usefulArea = aRoom.room->getWall(aWall.wall).getUsefulArea();

            if (map.find(rollTitle) == map.end())
            {
                map[rollTitle] = usefulArea;
            }
            else
            {
                map[rollTitle] += usefulArea;
            }
        }
    }

    std::map <std::string, float> ::iterator it = map.begin();

    std::cout << "\n";

    for (int i{ 0 }; i < rolls.size(); ++i) {
        it = map.find(rolls[i].getTitle());
        if (it == map.end()) {
            continue;
        }
        int amount = it->second / rolls[i].getArea();
        std::cout << it->first << " - rolls: " << amount << ", " << amount * rolls[i].getPrice() << "$" << "\n";
    }

}
