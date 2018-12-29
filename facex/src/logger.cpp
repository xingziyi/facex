#include "../include/logger.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include <limits.h>
#include <iostream>

namespace facex
{
facex::logger::logger(logLevel level)
{
    controlLevel = level;
}

facex::logger::~logger()
{
    if (logFile.is_open())
        logFile.close();
}

void facex::logger::printLog(logLevel level, std::string message)
{
    if (level < controlLevel)
        return;
    else
    {
        if (consoleIndex == ULLONG_MAX - 1)
        {
            auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cerr << std::ctime(&timeNow) << " "
                      << "LogLevel:" << logLevelWarn << " "
                      << "Max console log index!" << std::endl;
        }
        else
        {
            auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cerr << consoleIndex << " " << std::ctime(&timeNow) << " "
                      << "LogLevel:" << level << " " << message << std::endl;
            ++consoleIndex;
        }
    }
}

void facex::logger::setLevel(logLevel level)
{
    controlLevel = level;
}

void facex::logger::saveLog(logLevel level, std::string message)
{
    if (level < controlLevel)
        return;
    else
    {
        if (fileIndex == ULLONG_MAX - 1)
        {
            auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cerr << std::ctime(&timeNow) << " "
                      << "LogLevel:" << logLevelWarn << " "
                      << "Max file log index!" << std::endl;
        }
        else
        {
            if (!logFile.is_open())
            {
                if (fileIndex != 0)
                {
                    auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                    std::cerr << std::ctime(&timeNow) << " "
                              << "LogLevel:" << logLevelWarn << " "
                              << "Logfile stream error!" << std::endl;
                }
                logFile.open("./facex_log.log");
            }
            else
            {
                auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                logFile << fileIndex << " " << std::ctime(&timeNow) << " "
                        << "LogLevel:" << logLevelWarn << " "
                        << message << std::endl;
                ++fileIndex;
            }
        }
    }
}
} // namespace facex