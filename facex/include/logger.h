#pragma once
#include <string>
#include <fstream>
namespace facex
{
enum logLevel
{
    logLevelDebug = 0,
    logLevelInfo = 1,
    logLevelWarn = 2,
    logLevelError = 3,
    logLevelFatal = 4
};
class logger
{
  public:
    logger(logLevel level);
    void printLog(logLevel level, std::string message);
    void setLevel(logLevel level);
    void saveLog(logLevel level, std::string message);

  private:
    ~logger();
    unsigned long long fileIndex = 0;
    unsigned long long consoleIndex = 0;
    logLevel controlLevel = logLevelDebug;
    std::ofstream logFile;
};
} // namespace facex