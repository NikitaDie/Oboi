#include <iostream>
#include "Room.h"
#include "Flat.h"
#include "Calculator.h"

int main()
{
    /*Room room{ "room_a", 2, 2, 3 };

    room.addUseless(1, 1, 1);
    room.addUseless(0, 2, 2);
    room.addUseless(2, 1, 1);

    std::cout << room.getUsefullWallArea();*/

    /*Flat flat{};
    flat.addRoom("room_a", 2, 2, 3);*/


    Roll roll{ "vasia", 1000, 1, 10 };

    Room room{ "room_a", 2, 2, 3 };

    room.addUseless(1, 1, 1);
    room.addUseless(0, 2, 2);
    room.addUseless(2, 1, 1);

    Calculator calc;
    calc.activeRooms.push_back({ &room });
    calc.activeRooms[0].activeWalls.push_back({ &room.walls[0], &roll });
    calc.activeRooms[0].activeWalls.push_back({ &room.walls[1], &roll });
    calc.calculate();



}

// TASK
// Написать программу «Стоимость обоев».Программа запрашивает :
// 1 количество комнат в квартире, в которых планируется клеить обои,
// 2 параметры каждой комнаты,
// 3 параметры каждого вида обоев, которые планируется использовать.
// В результате расчета программа выдает :
// необходимое количество рулонов каждого вида,
// общую стоимость закупки обоев.
//
// Разработать и  использовать в  программе классы :
// «Квартира», «Комната», «РулонОбоев».
// Атрибуты(поля) квартиры : список комнат.
// Атрибуты комнаты : название, размеры, клеить потолок или нет.
// Атрибуты рулона : название, размеры, цена.
