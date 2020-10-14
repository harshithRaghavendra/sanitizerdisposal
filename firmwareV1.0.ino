#define R1 2
#define R2 3
#define BUZZ 15
int sflag;
struct storage_object {
  int object_dist;
  int san_full;
  int san_low;
  int san_empty;
  int san_delay;
};
extern storage_object san_object;
typedef enum
{
  OBJECT = 0,
  TANK_EMPTY,
  TANK_FULL,
  TANK_LOW,
  TEMP_HIGH,
  TEMP_LOW
}LEDS;

typedef enum
{
  STBY = 0,
  SET_OBJECT,
  SET_TANK_FULL,
  SET_TANK_LOW,
  SET_TANK_EMPTY,
  SET_DELAY,
  DISP_SAN_FULL,
  DISP_SAN_LOW,
  DISP_SAN_EMPTY,
}MENU;
MENU menu = STBY;
void setup() {
  // put your setup code here, to run once:
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(BUZZ,OUTPUT);
  setup_leds();
  setup_lcd();
  setup_timer();
  setup_storage();
  sense_setup();
  welcome_screen();
  delay(5000);
  set_led(OBJECT,1);
  set_led(TANK_FULL,1);
  set_led(TANK_LOW,1);
  set_led(TANK_EMPTY,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int key = 0;
  unsigned char obj = 0;
  unsigned char level = 0;
  switch(menu)
  {
    case STBY:
    level = s2_sense();
    switch(level)
    {
      case 0xFF:
      stby(); // screen
      set_led(TANK_FULL,1);
      set_led(TANK_LOW,0);
      set_led(TANK_EMPTY,0);
      if(true == s1_sense())
    {
        if(sflag==0){
        object();
        digitalWrite(R1, HIGH);
        set_led(OBJECT,1);
        delay(san_object.san_delay);
        digitalWrite(R1, LOW);
        set_led(OBJECT,0);
        delay(san_object.san_delay);
        sflag=1;}
      else
      sflag=0;
    }
      break;
      case 0xCC:
      set_led(TANK_FULL,0);
      set_led(TANK_LOW,1);
      set_led(TANK_EMPTY,0);
      tank_low();
      if(true == s1_sense())
      {
      if(sflag==0){
        object();
        digitalWrite(R1, HIGH);
        set_led(OBJECT,1);
        delay(san_delay);
        digitalWrite(R1, LOW);
        set_led(OBJECT,0);
        delay(san_delay);
        sflag=1;}
      else
        sflag=0;
      }
      digitalWrite(BUZZ,HIGH);
      delay(50);
      digitalWrite(BUZZ,LOW);
      delay(500);
      break;
      case 0xAA:
      set_led(TANK_FULL,0);
      set_led(TANK_LOW,0);
      set_led(TANK_EMPTY,1);
      tank_empty();
      digitalWrite(BUZZ,HIGH);
      delay(100);
      digitalWrite(BUZZ,LOW);
      delay(500);
      break;
      default:
      break;
    }
  
    key = read_key();
    if(key == 'R')
    {
      menu = menu + 1;
      delay(300);
    }
    if(key == 'L')
    {
      menu = SET_DELAY;
      delay(300);
    }
    break;
    case SET_OBJECT:
    obj_set();
    break;
    case SET_TANK_FULL:
    san_full();
    break;
    case SET_TANK_LOW:
    san_low();
    break;
    case SET_TANK_EMPTY:
    san_empty();
    break;
    case SET_DELAY:
    san_delay();
    break;
    default:
    break;
  }
  


  
}
