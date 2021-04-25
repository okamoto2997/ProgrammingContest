#pragma once

#define LOG_LEVEL_NONE  0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_INFO  3
#define LOG_LEVEL_DEBUG 4

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_DEBUG
#endif

#ifdef NDEBUG
#  ifdef LOG_LEVEL
#    undef  LOG_LEVEL
#  endif
#  define LOG_LEVEL LOG_LEVEL_NONE
#endif

#define ERROR_MSG(fmt, ...) MSG(Error, fmt, __VA_ARGS__)
#define  WARN_MSG(fmt, ...) MSG( Warn, fmt, __VA_ARGS__)
#define  INFO_MSG(fmt, ...) MSG( Info, fmt, __VA_ARGS__)
#define DEBUG_MSG(fmt, ...) MSG(Debug, fmt, __VA_ARGS__)

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define ERROR_TO(dest, fmt, ...) dest << ERROR_MSG(fmt, __VA_ARGS__) << std::endl
#define ERROR(fmt, ...) ERROR_TO(log::_dest.get(), fmt, __VA_ARGS__)
#else
#define ERROR_TO(dest, fmt, ...)
#define ERROR(fmt, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define WARN_TO(dest, fmt, ...) dest << WARN_MSG(fmt, __VA_ARGS__) << std::endl
#define WARN(fmt, ...) WARN_TO(log::_dest.get(), fmt, __VA_ARGS__)
#else
#define WARN_TO(dest, fmt, ...)
#define WARN(fmt, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define INFO_TO(dest, fmt, ...) dest << INFO_MSG(fmt, __VA_ARGS__) << std::endl
#define INFO(fmt, ...) INFO_TO(log::_dest.get(), fmt, __VA_ARGS__)
#else
#define INFO_TO(dest, fmt, ...)
#define INFO(fmt, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define DEBUG_TO(dest, fmt, ...) dest << DEBUG_MSG(fmt, __VA_ARGS__) << std::endl
#define DEBUG(fmt, ...) DEBUG_TO(log::_dest.get(), fmt, __VA_ARGS__)
#else
#define DEBUG_TO(dest, fmt, ...)
#define DEBUG(fmt, ...)
#endif

#if LOG_LEVEL > LOG_LEVEL_NONE
#include <ctime>
#include <filesystem>

namespace log{
  static std::reference_wrapper<std::ostream> _dest = std::ref(std::cerr);
  inline void init(std::ostream& dest){
    _dest = std::ref(dest);
  }
}

[[maybe_unused]] static const char* current_time(){
  static char buf[20] = {};
  time_t t = time(nullptr);
  tm* tp = localtime(&t);
  strftime(buf, 20, "%F %H:%M:%S", tp);
  return buf;
}
#endif

/*
#define MSG(tag, _fmt, ...) \
  fmt::format("{} [{}:{:3}] {:<5}: " _fmt, toolkit::current_time(), \
    std::filesystem::path(__FILE__).filename().c_str(), \
    __LINE__, #tag __VA_OPT__(,) __VA_ARGS__)
*/

#define MSG(tag, _fmt, ...)                                             \
  [&](){                                                                 \
  static char buf[80];                                                  \
  snprintf(buf, 80, "%s [%s:%3d] %-5s: " _fmt,                          \
    current_time(), std::filesystem::path(__FILE__).filename().c_str(), \
    __LINE__, #tag __VA_OPT__(,) __VA_ARGS__);                          \
  return buf;                                                           \
  }()
