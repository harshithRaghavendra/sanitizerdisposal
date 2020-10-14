#define CPL_NO 6
/* charlieplex algorithm*/

char CPX_array[] = {16,17,18};
char LED_LUT[][2]={
  {1,3},//3
  {3,1},//4
  {2,3},//5
  {3,2},//6
  {1,2},//1
  {2,1},//2
  };
char rast_array[CPL_NO]={0};

void clear_all_led()
{
    for(int i = 0; i< 7;i++)
    {
      pinMode(CPX_array[i],INPUT);
    }
}
void set_led(char l, char val)
{
  rast_array[l] = val;
}
void raster()
{
  static int i = 0;
  if (rast_array[i] > 0)
  {
    led_glow(i);
  }
  else
  {
    clear_all_led();
  }
  i++;
  if (i>CPL_NO)
  {
    i = 0;
  }
  
}
void setup_leds()
{
  clear_all_led();
  for(int j = 0; j<2000;j++)
  {
  for(int i = 0; i<CPL_NO;i++)
  {
    
      pinMode(CPX_array[LED_LUT[i][0]-1],OUTPUT);
      pinMode(CPX_array[LED_LUT[i][1]-1],OUTPUT);
      digitalWrite(CPX_array[LED_LUT[i][0]-1],LOW);
      digitalWrite(CPX_array[LED_LUT[i][1]-1],HIGH);
  }
  }
  clear_all_led(); // switchoff all leds
  //led_glow(1);
}
void led_glow(unsigned char led_pin_no)
{
    if (led_pin_no >= CPL_NO)
    {
      clear_all_led();
    }
    else
    {
      clear_all_led();
      pinMode(CPX_array[LED_LUT[led_pin_no][0]-1],OUTPUT);
      pinMode(CPX_array[LED_LUT[led_pin_no][1]-1],OUTPUT);
      digitalWrite(CPX_array[LED_LUT[led_pin_no][0]-1],LOW);
      digitalWrite(CPX_array[LED_LUT[led_pin_no][1]-1],HIGH);
    }
}
