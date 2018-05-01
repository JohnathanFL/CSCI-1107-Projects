/*--- Timer.h ----------------------------------------------------------- 
  This header file defines a simple, platform-independent interval 
  timer that measures CPU usage in (fractional) seconds. 
   
  Author: Joel Adams, for Hands On C++.
  Date:   November 1997
  Modification history:
       March 1998: ANSI compliance, interface improvements by J. Adams
       February 1998: seconds() added by K. Vander Linden
       November, 2004: function names updated and documentation added 
                       by L. Nyhoff
 -----------------------------------------------------------------------*/

#ifndef TIMER
#define TIMER

#include <iostream>   // ostream
#include <ctime>      // C time library: clock_t, clock(), CLOCKS_PER_SEC
using namespace std;

class Timer
{
 public:
  Timer();
  /*--------------------------------------------------------------------
    Timer constructor.
    Precondition:  None
    Postcondition: myStartTime == 0 && myRunTime == 0 &&
                   running == false.
 ----------------------------------------------------------------------*/

  void start();
  /*--------------------------------------------------------------------
    Start timing.
    Precondition:  None
    Postcondition: myStartTime == the current clock value &&
                   running == true.
    Note:  start() while running restarts this Timer object.
 ----------------------------------------------------------------------*/

  void stop();
  /*--------------------------------------------------------------------
    Stop timing.
    Precondition:  running == true.
    Postcondition: myRunTime has been updated with time interval
                   since the Timer was started && running == true.
    Note:  stop() only has an effect while this Timer object is 
           running.
 ----------------------------------------------------------------------*/

  void reset();
  /*--------------------------------------------------------------------
    Reset this Timer object.
    Precondition:  None
    Postcondition: myStartTime is the current clock value &&
                   myRunTime == 0 
 ----------------------------------------------------------------------*/

  double seconds() const;
  /*--------------------------------------------------------------------
    Convert current time value to seconds.
    Precondition:  None
    Postcondition: Elapsed time since startup is returned.
    Note:  If not running:
             Repeated calls to seconds() return the same value.
           Otherwise:
             Repeated calls to seconds() return different values.
 ----------------------------------------------------------------------*/

  void print(ostream & out) const;
  /*--------------------------------------------------------------------
    Display time elapsed in seconds on ostream out.
    Precondition:  ostream out is open
    Postcondition: Elapsed time (in seconds) since startup is output 
                   to out.
    Note:  If not running:
             Repeated calls to print() display the same value.
           Otherwise:
             Repeated calls to print() display different values.
 ----------------------------------------------------------------------*/

 private:
  clock_t myStartTime;
  clock_t myRunTime;
  bool running;
};

inline Timer::Timer()
{
  myStartTime = myRunTime = 0;
  running = false;
}

inline void Timer::start()
{
  running = true;
  myStartTime = clock();
}

inline void Timer::stop()
{
  if (running)
  {
    myRunTime += clock() - myStartTime;
    running = false;
  }
}

inline void Timer::reset()
{
  myRunTime = 0;
  myStartTime = clock();
}

inline double Timer::seconds() const
{
  if (running)
    return double(clock() - myStartTime) / double(CLOCKS_PER_SEC);
  else
    return double(myRunTime) / double(CLOCKS_PER_SEC);
}

inline void Timer::print(ostream & out) const
{
  out << seconds();
}

inline ostream & operator<< (ostream & out, const Timer & aTimer)
  /*--------------------------------------------------------------------
    Display time elapsed in seconds on ostream out via <<.
    Precondition:  ostream out is open
    Postcondition: Elapsed time (in seconds) since startup of aTimer
                   is output to out.
    Note:  If not running:
             Repeated calls to << display the same value.
           Otherwise:
             Repeated calls to << display different values.
 ----------------------------------------------------------------------*/
{
  aTimer.print(out);
  return out;
}

#endif
