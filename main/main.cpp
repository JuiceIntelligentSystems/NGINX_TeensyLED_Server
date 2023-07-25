#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <filesystem>
#include <mutex>
#include <jsoncpp/json/json.h>
#include "wiringPiI2C.h"

#define TEENSY_ID 0x4b

int main(int argc, char **argv)
{
    int fd = wiringPiI2CSetup(TEENSY_ID);
    if (fd == -1)
    {
        std::cout << "Error Connecting to Teensy\n";
        return -1;
    }
    std::cout << "Teensy Connected Successfully\n";

    std::string jsonFile = "/var/www/html/control.json";
    std::filesystem::file_time_type previous_time = std::filesystem::last_write_time(jsonFile);

    int last_num = 0, current_num = 0;
    while (true)
    {
        if (std::filesystem::last_write_time(jsonFile) != previous_time)
        {
            std::ifstream ifs(jsonFile);

            try
            {
                Json::Value obj;
                ifs >> obj;

                std::string string = obj["brightness"].asString();
                int data = std::stoi(string);

                current_num = data;
                if (last_num != current_num)
                {
                    std::cout << data << std::endl;

                    wiringPiI2CWrite(fd, data);
                    last_num = current_num;
                }
            }
            catch (Json::RuntimeError &e)
            {
                e.what();
                std::cout << "Error Parsing\n";
            }

            previous_time = std::filesystem::last_write_time(jsonFile);
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    return 0;
}