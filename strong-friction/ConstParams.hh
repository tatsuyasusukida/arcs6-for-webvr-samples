#ifndef CONSTPARAMS
#define CONSTPARAMS

#include <array>

namespace ARCS
{
  class ConstParams
  {
  public:
    static constexpr unsigned int ACTUATOR_NUM = 5;
    static constexpr unsigned int THREAD_MAX = 3;
    static constexpr std::array<unsigned long, THREAD_MAX> SAMPLING_TIME = {
        100000,
        1000000,
        1000000,
    };

    static constexpr unsigned int INDICVARS_MAX = 16;
    static constexpr unsigned int INDICVARS_NUM = 10;

    static constexpr unsigned int ONLINEVARS_MAX = 16;
    static constexpr unsigned int ONLINEVARS_NUM = 10;

    static constexpr size_t PLOT_MAX = 4;
    static constexpr std::array<unsigned int, PLOT_MAX> PLOT_VAR_NUM = {
        8,
        8,
        8,
        8,
    };
  };
}

#endif
