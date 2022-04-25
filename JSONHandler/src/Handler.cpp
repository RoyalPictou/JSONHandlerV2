#include "Handler.h"
#include "../include/json.hpp"
#include <iostream>

using nlohmann::json;

Handler::Handler()
{
std::string jsonData = "{ \"happy\": true, \"pi\" : 3.141 }";
parseStringToJson(jsonData);

}

Handler::~Handler()
{
}

void
Handler::parseStringToJson(std::string& data)
{
    json j3 = json::parse(data);
std::cout << j3 << std::endl;
}
