#include <iostream>
using namespace std;

class ILogger{
    public:
    virtual void log(const std::string &msg) = 0;
};

class DebugLogger: public ILogger{
    void log(const std::string &msg) {
        cout<< "DUBUG: "<< msg << endl;
    }


};

class InfoLogger: public ILogger{
    void log(const std::string &msg){
        cout<< "INFO: "<< msg << endl;
    }


};

enum LoggerType {
    INFO, ERROR, DEBUG
};

class ILoggerFactory {
    public:
    virtual ILogger* createLogger()= 0;

};

class DebugLoggerFactory: public ILoggerFactory{
    ILogger* createLogger() {

        return new DebugLogger();
    }
};

class InfoLoggerFactory: public ILoggerFactory{
    ILogger* createLogger(){

        return new InfoLogger();
    }
};


int main(){
    ILoggerFactory* infoLoggerFactory = new InfoLoggerFactory();
    ILogger* infoLogger = infoLoggerFactory->createLogger();
    infoLogger->log("This is just info!");

    ILoggerFactory* debugLoggerFactory = new DebugLoggerFactory();
    ILogger* debugLogger = debugLoggerFactory->createLogger();
    debugLogger->log("This is debug text!");





    return 0;
}