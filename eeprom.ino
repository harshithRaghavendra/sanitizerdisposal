#include <EEPROM.h>

#define begin_address 0
/*struct storage_object {
  int object_dist;
  int san_full;
  int san_low;
  int san_empty;
  int san_delay;
};*/

storage_object san_object; // 

void setup_storage()
{
  EEPROM.get(begin_address, san_object);
}
void write_storage()
{
  EEPROM.put(begin_address, san_object);
}
