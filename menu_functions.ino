extern storage_object san_object;

void obj_set()
{
  char key;
  set_object();
  disp_param(san_object.object_dist);
  delay(300);
  key = read_key();
  if(key == 'U')
  {
    if(san_object.object_dist < 50)
    {
      san_object.object_dist++;
    }
  }
  if(key == 'D')
  {
    if(san_object.object_dist > 0)
    {
      san_object.object_dist--;
    }
  }
  if(key == 'R')
  {
    write_storage();
    menu = SET_TANK_FULL;
  }
  if(key == 'L')
  {
    write_storage();
    menu = STBY;
  }
}

void san_full()
{
  char key;
  set_san_full();
  disp_param(san_object.san_full);
  delay(300);
  key = read_key();
  if(key == 'U')
  {
    if(san_object.san_full < 50)
    {
      san_object.san_full++;
    }
  }
  if(key == 'D')
  {
    if(san_object.san_full > 0)
    {
      san_object.san_full--;
    }
  }
  if(key == 'R')
  {
    write_storage();
    menu = SET_TANK_LOW;
  }
  if(key == 'L')
  {
    write_storage();
    menu = SET_OBJECT;
  }
}

void san_low()
{
  char key;
  set_san_low();
  disp_param(san_object.san_low);
  delay(300);
  key = read_key();
  if(key == 'U')
  {
    if(san_object.san_low < 50)
    {
      san_object.san_low++;
    }
  }
  if(key == 'D')
  {
    if(san_object.san_low > 0)
    {
      san_object.san_low--;
    }
  }
  if(key == 'R')
  {
    write_storage();
    menu = SET_TANK_EMPTY;
  }
  if(key == 'L')
  {
    write_storage();
    menu = SET_TANK_FULL;
  }
}

void san_empty()
{
  char key;
  set_san_empty();
  disp_param(san_object.san_empty);
  delay(300);
  key = read_key();
  if(key == 'U')
  {
    if(san_object.san_empty < 50)
    {
      san_object.san_empty++;
    }
  }
  if(key == 'D')
  {
    if(san_object.san_empty > 0)
    {
      san_object.san_empty--;
    }
  }
  if(key == 'R')
  {
    write_storage();
    menu = SET_DELAY;
  }
  if(key == 'L')
  {
    write_storage();
    menu = SET_TANK_LOW;
  }
}
void san_delay()
{
  char key;
  set_delay();
  disp_param1(san_object.san_delay);
  delay(300);
  key = read_key();
  if(key == 'U')
  {
    if(san_object.san_delay < 500)
    {
      san_object.san_delay+=10;
    }
  }
  if(key == 'D')
  {
    if(san_object.san_delay > 0)
    {
      san_object.san_delay-=10;
    }
  }
  if(key == 'R')
  {
    write_storage();
    menu = STBY;
  }
  if(key == 'L')
  {
    write_storage();
    menu = SET_TANK_EMPTY;
  }
}
