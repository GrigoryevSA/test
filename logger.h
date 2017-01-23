class LogAppender;

class Logger
{
  public:
    enum LogLevel
    {
      LOG_LEVEL_DEFAULT = 0
      , LOG_LEVEL_ERROR
    };
  public:
    static Logger *getInstance();

  public:
    virtual bool setLogLevel(LogLevel lvl) = 0;
    virtual bool addAppender(LogAppender *appender) = 0;
    virtual void LogMessage(Logger::LogLevel level, const std::string &msg) = 0;
};

class LogAppender
{
  public:
    virtual void LogMessage(Logger::LogLevel level, const std::string &msg) = 0;
};

class FileLogAppender : public LogAppender
{
  
}

class StdLogAppender : public LogAppender
{
  
}

#define LOG_DEF(msg) Logger::getInstance()->LogMessage(Logger::LogLevel::LOG_LEVEL_DEFAULT, msg)
#define LOG_ERR(msg) Logger::getInstance()->LogMessage(Logger::LogLevel::LOG_LEVEL_ERROR, msg)

void main()
{
  Logger *loginst = Logger::getInstance();
  
  FileLogAppender *fileAppender = new FileLogAppender;
  fileAppender.setFilename("qweqwe.log");
  loginst->addAppender(fileAppender);
  loginst->addAppender(new StdLogAppender);
  
  loginst->setLogLevel(Logger::LogLevel::LOG_LEVEL_ERROR); // Log only if LogLevel > LOG_LEVEL_ERROR
 
  LOG_DEF("Logger init def"); // ===>> NOTHIHNG
  LOG_ERR("Logger init successfully"); //  ====>> std:: ""Logger init successfully""
  // file qweqwe.log ====>>> "Logger init successfully"
  
  return 0;
}