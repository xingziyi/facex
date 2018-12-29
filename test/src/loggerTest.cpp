#include "../include/loggerTest.h"
#include <iostream>
namespace facex
{
void loggerTest()
{
    facex::logger *testLogger = new facex::logger(facex::logLevelDebug);
    auto testLevel = facex::logLevelDebug;
    while (testLevel <= facex::logLevelFatal)
    {
        std::cout << testLevel << std::endl;
        testLogger->setLevel(testLevel);
        testLogger->printLog(facex::logLevelDebug, "Test: logLevelDebug!");
        testLogger->printLog(facex::logLevelInfo, "Test: logLevelInfo!");
        testLogger->printLog(facex::logLevelWarn, "Test: logLevelWarn!");
        testLogger->printLog(facex::logLevelError, "Test: logLevelError!");
        testLogger->printLog(facex::logLevelFatal, "Test: logLevelFatal!");
        testLogger->saveLog(facex::logLevelDebug, "Test: logLevelDebug!");
        testLogger->saveLog(facex::logLevelInfo, "Test: logLevelInfo!");
        testLogger->saveLog(facex::logLevelWarn, "Test: logLevelWarn!");
        testLogger->saveLog(facex::logLevelError, "Test: logLevelError!");
        testLogger->saveLog(facex::logLevelFatal, "Test: logLevelFatal!");
        testLevel = static_cast<facex::logLevel>(static_cast<int>(testLevel) + 1);
    }
    return;
}
} // namespace facex