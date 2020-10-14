#include <TimerOne.h>

void setup_timer()
{
  Timer1.initialize(1000); //microseconds
  Timer1.attachInterrupt(cbk_timer); 
}
void cbk_timer(void)
{
  raster();
  //disp();
}
