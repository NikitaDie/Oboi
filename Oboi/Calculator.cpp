#include "Calculator.h"

Calculator::Calculator()
{
}

float Calculator::calculate()
{
    std::map<std::string, float> map;

    for (ActiveRoom& aRoom : activeRooms)
    {
        for (ActiveWall& aWall : aRoom.activeWalls)
        {
            std::string rollTitle = aWall.roll->getTitle();
            float usefulArea = aWall.wall->getUsefulArea();

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

    std::cout << "test";




    return 0;

    /*float fullPrice{};

    for (ActiveRoom& aRoom : activeRooms)
    {
        for (ActiveWall& aWall : aRoom.activeWalls)
        {
            float usefulArea = aWall.wall->getUsefulArea();
            float rollArea = aWall.roll->getArea();

            float fullCount = usefulArea / rollArea;


            fullPrice += aWall.
        }
    }*/
   


}
