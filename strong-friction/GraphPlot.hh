#ifndef GRAPHPLOT
#define GRAPHPLOT

#include <stddef.h>
#include "ConstParams.hh"
#include "WebVR.hh"

namespace ARCS
{
  class GraphPlot
  {
  public:
    GraphPlot();

    void SetTime(const double T, const double t) {}

    template <typename T1, typename... T2>
    void SetVars(const T1 &u1, const T2 &...u2)
    {
      if (VarsCount == 0)
      {
        PlotNumBuf = (size_t)u1;
      }
      else
      {
        if (VarsCount <= ConstParams::PLOT_VAR_NUM[PlotNumBuf])
        {
          setPlot(PlotNumBuf + 1, VarsCount, u1);
        }
      }

      ++VarsCount;
      SetVars(u2...);
    }

    void SetVars()
    {
      VarsCount = 0;
    }

  private:
    size_t PlotNumBuf;
    size_t VarsCount;
  };
}

#endif
