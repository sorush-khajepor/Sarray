/*
Exposes D and SASSERT function when is defined.
Usage: define it at the top of the file which should be debugged:
#define SDEBUG

*/

#ifdef SDEBUG

  // NDEBUG switches assertion off. For safety, it is undefined.
  #undef NDEBUG
  #include <cassert>

  // Commands which are run only in debug mode.
  #define D(x) x

  // SASSERT function 
  #define SASSERT(condition, message)                                             \
  {                                                                              \
      if(!(condition))                                                           \
      {                                                                          \
          std::cerr << message<<std::endl;                                            \
          std::cerr << "Assertion failed at " << __FILE__ << ":" << __LINE__;    \
          std::cerr << " inside " << __FUNCTION__ << std::endl;                  \
          std::cerr << "Condition: " << #condition;                              \
          abort();                                                               \
      }                                                                          \
  }
#else

  // Do none of above in release mode.
  #define D(x) 
  #define SASSERT(condition, message) 
#endif

