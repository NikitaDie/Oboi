#include <iostream>
#include <vector>
#include "Room.h"
#include "Flat.h"
#include "Calculator.h"
#include "Conversation.h"


int main()
{

    Flat flat{};
    std::vector<Roll> rolls;
    Conversation dialog;

    int temp_number{ 0 };
    float temp_a{ 0 };
    float temp_b{ 0 };

    std::cout << "Hali, halo! " << "\n";
    std::cout << "Wie vile rooms hast du, Bruder?>: ";
    std::cin >> temp_number;
    temp_number = dialog.checkValue(temp_number, 1);

    for (int i{ 0 }; i < temp_number; ++i) {
        dialog.addRoomText(flat);
    }

    flat.printRooms();

    std::cout << "\n" << "Bruder, du bist sehr Süß" << "\n";
    std::cout << "Aber ich denke du hast auch Windows and Doors. Verstehst du?" << "\n";
    std::cout << "In wie viele Rooms hast du dieses Problem?: ";
    std::cin >> temp_number;
    temp_number = dialog.checkValue(temp_number, 0);

    if(temp_number != 0){
        std::cout << "\n" << "Ok, In welchen Rooms ?" << "\n";
    }

    for (int i{ 0 }; i < temp_number; ++i) {
        dialog.addUselessText(flat);
    }


    std::cout << "\n" << "Great Job! Aber ich auch brauche also your papers" << "\n";
    std::cout << "How many different kinds of them you want to use: ";
    std::cin >> temp_number;
    temp_number = dialog.checkValue(temp_number, 1);

    

    for (int i{ 0 }; i < temp_number; ++i) {
        dialog.addPapersText(rolls);
    }

    Calculator calc;

    dialog.chooseWand(flat, calc, rolls);

    calc.calculate(rolls);



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
