#pragma once

#if defined(_WIN32) || defined(__WIN32__)
#  if defined(ALGOS_EXPORT)
#    define  API __declspec(dllexport)
#  else
#    define  API __declspec(dllimport)
#  endif
#elif defined(linux) || defined(__linux)
# define API
#endif