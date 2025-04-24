/**============================================================================
Name        : main.cpp
Created on  : 24.28.2024
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : Json benchmarks
============================================================================**/

#include <iostream>
#include <string_view>
#include <vector>

#include <nlohmann/json.hpp>

#include "simdjson.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/ostreamwrapper.h"

#include "PerfUtilities.h"

namespace
{
    const std::string json { R"( {"data":{"A":"0.08737000","B":"0.10420000","C":1745472821988,"E":1745472822004,
        "F":1798873,"L":1893166,"O":1745386421988,"P":"-0.886","Q":"0.00026000","a":"92671.21000000",
        "b":"92671.20000000","c":"92671.20000000","e":"24hrTicker","h":"120000.00000000","l":"22009.80000000",
        "n":94294,"o":"93499.99000000","p":"-828.79000000","q":"216672881.48598570","s":"BTCUSDT","v":"2319.45099000",
        "w":"93415.58947360","x":"93499.99000000"},"stream":"btcusdt@ticker"})"
    };
}


namespace Benchmarks::Parse
{
    constexpr int iterCount { 1'000'000 };

    void nlohmann()
    {
        PerfUtilities::ScopedTimer timer { "nlohmann"};
        for (int i = 0; i < iterCount; ++i)
        {
            auto dict = nlohmann::json::parse(json.data());
            // std::cout << dict["data"] << std::endl;
            // std::cout << dict["data"]["s"] << std::endl;
        }
    }

    void rapidjson()
    {
        PerfUtilities::ScopedTimer timer { "rapidjson"};
        for (int i = 0; i < iterCount; ++i)
        {
            rapidjson::Document document;
            document.Parse(json.data());


            /*
            rapidjson::StringBuffer strBuf;
            rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);

            strBuf.Clear();
            document.Accept(writer);

            //auto data = document.Get("data");
            auto data = document["data"]["s"].GetString();
            std::cout << data << std::endl;*/
        }
    }

    void simdjson()
    {
        PerfUtilities::ScopedTimer timer { "simdjson"};
        for (int i = 0; i < iterCount; ++i) {
            simdjson::dom::parser parser;
            simdjson::dom::element doc;
            auto error = parser.parse(json).get(doc);
            // auto value = doc["data"]["s"].get_string();
        }
    }

    void nlohmann_1()
    {
        PerfUtilities::ScopedTimer timer { "nlohmann"};
        nlohmann::json dict;
        for (int i = 0; i < iterCount; ++i) {
            dict = nlohmann::json::parse(json.data());
        }
    }

    void rapidjson_1()
    {
        PerfUtilities::ScopedTimer timer { "rapidjson"};
        rapidjson::Document document;
        for (int i = 0; i < iterCount; ++i)
        {
            document.Parse(json.data());
        }
    }

    void benchmark()
    {
        nlohmann();
        rapidjson();
        simdjson();

        std::cout << std::endl;

        // nlohmann_1();
        // rapidjson_1();
    }
}



int main([[maybe_unused]] const int argc,
         [[maybe_unused]] char** argv)
{
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    Benchmarks::Parse::benchmark();


    return EXIT_SUCCESS;
}
