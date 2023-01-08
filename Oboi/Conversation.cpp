#include "Conversation.h"



void Conversation::addRoomTextSizes(Flat& flat, std::string name) {
    float h{ 0 };
    std::cout << "Jetzt, size of es (a, b, height): ";
    std::cin >> temp_a >> temp_b >> h;
    if (temp_a <= 0 or temp_b <= 0 or h <= 0) {
        std::cout << "\n" << "Bro, Nicht gut :(" << "\n";
        std::cout << "Put a correct size" << "\n\n";
        addRoomTextSizes(flat, name);
    }
    else {
        flat.addRoom(name, temp_a, temp_b, h);
    }
}

void Conversation::addRoomText(Flat& flat)
{
    std::string name;
    std::cout << "\n" << "Bro, Ich brauche den Name von dein Room: ";
    std::cin >> name;
    addRoomTextSizes(flat, name);
    
}

void Conversation::printRolls(std::vector<Roll>& rolls)
{
    for (int i{ 0 }; i < rolls.size(); ++i) {
        std::cout << i << " - " << rolls[i].getTitle() << " - " << rolls[i].getPrice() << " - Area(" << rolls[i].getArea() << ")" << "\n";
    }

}

int Conversation::checkValue(int value, int min_d, int max_d) {
    if (value > max_d or value < min_d) {
        std::cout << "\n" << "Bro, Nicht gut :(" << "\n";
        std::cout << "Try again: " << "\n\n";
        std::cin >> value;
        checkValue(value, min_d, max_d);
    } else {
        return value;
    }
}

void Conversation::checkValue(float& value1, float& value2, int min_d1, int max_d1, int min_d2, int max_d2) {
    if (value1 > max_d1 or value1 < min_d1 or value2 > max_d2 or value2 < min_d2) {
        std::cout << "\n" << "Bro, Nicht gut :(" << "\n";
        std::cout << "Try again: " << "\n\n";
        std::cin >> value1 >> value2;
        checkValue(value1, value2, min_d1, max_d1, min_d2, max_d2);
    }
    else {
        return;
    }
}

float Conversation::checkValue(float value, int min_d, int max_d) {
    if (value > max_d or value < min_d) {
        std::cout << "\n" << "Bro, Nicht gut :(" << "\n";
        std::cout << "Try again: " << "\n\n";
        std::cin >> value;
        checkValue(value, min_d, max_d);
    }
    else {
        return value;
    }
}

void Conversation::addUselessText(Flat& flat)
{
    int tmp_num_r{ 0 };
    int temp_num_uslss{ 0 };
    int temp_w_num{ 0 };

    flat.printRooms();
    std::cout << "Number of room: ";
    std::cin >> tmp_num_r;
    tmp_num_r = checkValue(tmp_num_r, 0, flat.numberOfRooms() - 1);

    std::cout << "\n" << flat.getRoom(tmp_num_r).getTitle() << ": " << "\n";
    std::cout << "\t" << "Wie viele Windows und Doors sind in diesem Room?: ";
    std::cin >> temp_num_uslss;
    temp_num_uslss = checkValue(temp_num_uslss, 0);


    for (int j{ 0 }; j < temp_num_uslss; ++j) {
        int temp_w_num{ 0 };

        std::cout << "\t\t" << "Wandnummer: ";
        std::cin >> temp_w_num;
        temp_w_num = checkValue(temp_w_num, 0, 5);

        std::cout << "\t\t" << "Size (a, b): "; 
        std::cin >> temp_a >> temp_b;
        checkValue(temp_a, temp_b, 0, flat.getRoom(tmp_num_r).getWall(temp_w_num - 1).getHeight(), 0, flat.getRoom(tmp_num_r).getWall(temp_w_num - 1).getWidth());

        flat.getRoom(tmp_num_r).addUseless(temp_w_num - 1, temp_a, temp_b);
    }
}

void Conversation::addPapersText(std::vector<Roll>& rolls)
{
    std::string name;
    float price{ 0 };
    std::cout << "\n" << "Bro, Ich brauche den Name von deine papers: ";
    std::cin >> name;
    std::cout << "\n" << "Price per roll: ";
    std::cin >> price;
    price = checkValue(price, 0, MAX_ROLL_PRICE);

    std::cout << "Jetzt, size of es (weidth and height): ";
    std::cin >> temp_a >> temp_b;
    checkValue(temp_a, temp_b, MIN_ROLL_SIZE, MAX_ROLL_PRICE, MIN_ROLL_SIZE, MAX_ROLL_PRICE);

    rolls.push_back({ name, price, temp_a, temp_b });
}

void  Conversation::chooseWand(Flat& flat, Calculator& calc, std::vector<Roll>& rolls) {
    int tmp_r;
    int tmp_w;
    int tmp_ob;
    int i{ 0 };

    std::cout << "Good, jetzt you should to choose 'was und wo'" << "\n";

    while (true) {
        flat.printRooms();
        std::cout << "\n" << "Welchen Room ? ((-1) - exit)" << "\n";
        std::cout << "id: ";
        std::cin >> tmp_r;
       
        if (tmp_r == -1) {
            return;
        }
        else {
            tmp_r = checkValue(tmp_r, 0, flat.numberOfRooms() - 1); //room id check
            calc.pushRoom(flat.getRoom(tmp_r));

            while (true) {
                std::cout << "\n" << "Welchen Wall? ((-1) - exit)" << "\n";
                std::cout << "id: ";
                std::cin >> tmp_w;

                if (tmp_w == -1) {
                    break;
                }
                else {
                    tmp_w = checkValue(tmp_w, 1, 4); //wall id check

                    printRolls(rolls);
                    std::cout << "\n" << "Welchen Papers?" << "\n";
                    std::cout << "id: ";
                    std::cin >> tmp_ob;
                    tmp_ob = checkValue(tmp_ob, 0, rolls.size() - 1); //papers id check 
                    calc.pushWall(i, tmp_w - 1, rolls[tmp_ob]);
                }
            }
        }

        ++i;
    }

}