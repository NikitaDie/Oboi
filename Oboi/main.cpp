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

    Flat flat{};
    int temp_number{ 0 };
    float temp_a{ 0 };
    float temp_b{ 0 };

    std::cout << "Hali, halo! " << "\n";
    std::cout << "Wie vile rooms hast du, Bruder?>: ";
    std::cin >> temp_number;

    for (int i{ 0 }; i < temp_number; ++i) {
        std::string name;
        float h{0};
        std::cout << "\n" << "Bro, Ich brauche den Name von dein Room: ";
        std::cin >> name;
        std::cout << "Jetzt, size of es (a, b, height): ";
        std::cin >> temp_a >> temp_b >> h;
        flat.addRoom(name, temp_a, temp_b, h);
    }

    std::cout << "\n" << "Bruder, du bist sehr Süß" << "\n";
    std::cout << "Aber ich denke du hast auch Windows and Doors. Verstehst du? <<" << "\n";
    std::cout << "In wie viele Rooms hast du dieses Problem?: ";
    std::cin >> temp_number;
    std::cout << "\n" << "Ok, In welchen Rooms ?" << "\n";

    for (int i{ 0 }; i < temp_number; ++i) {
        int tmp_num_r{ 0 };
        int temp_num_uslss{ 0 };
        int temp_w_num{ 0 };

        flat.printRooms();
        std::cout << "Number of room: ";
        std::cin >> tmp_num_r;
        std::cout << "\n" << flat.getRoom(tmp_num_r).getTitle() << ": " << "\n";
        std::cout << "\t" << "Wie viele Windows und Doors sind in diesem Room?: ";
        std::cin >> temp_num_uslss;

        for (int j{ 0 }; j < temp_num_uslss; ++j) {
            int temp_w_num{ 0 };

            std::cout << "\t\t" << "Wandnummer: ";
            std::cin >> temp_w_num;
            std::cout << "\t\t" << "Size (a, b): ";
            std::cin >> temp_a >> temp_b;
            flat.getRoom(i).addUseless(temp_w_num - 1, temp_a, temp_b);
        }
    }




    Roll roll{ "vasia", 1000, 1, 10 };

    Calculator calc;
    calc.pushRoom(flat.getRoom(0));
    calc.pushWall(0, 0, roll);
    calc.pushWall(0, 1, roll);

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
