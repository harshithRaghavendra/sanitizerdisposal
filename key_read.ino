char read_key()
{
  char k = get_key();
  for(int i =0; i<20; i++)
  {
    if(k != get_key())
    {
      return 'N';
    }
  }
  return k;
}

char get_key()
{
  int key_read = 0;
  for(int i =0; i<10; i++)
  {
    key_read = analogRead(A0);
  }
  //key_read = analogRead(A0);
  for(int i =0; i<5; i++)
  {
    key_read = (analogRead(A0)+key_read)/2;
  }
  //return key_read;
  //disp(key_read);
  if((key_read < 260) && (key_read >20))
  {
    return 'R';
  }
  if((key_read < 341) && (key_read >280))
  {
    return 'L';
  }
  if((key_read < 590) && (key_read > 350))
  {
    return 'D';
  }
  if((key_read < 1024) && (key_read > 800))
  {
    return 'U';
  }
  return 'N';
}
