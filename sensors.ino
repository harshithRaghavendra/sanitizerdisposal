
#define T1 4
#define E1 5
#define T2 6
#define E2 7
extern storage_object san_object; // 
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void sense_setup()
{
  //below is for object/hand sensing
  pinMode(T1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(E1, INPUT); // Sets the echoPin as an INPUT
  // below is for level sensing
  pinMode(T2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(E2, INPUT); // Sets the echoPin as an INPUT
}
char s2_sense()
{
    // Clears the trigPin condition
  digitalWrite(T2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(T2, HIGH);
  delayMicroseconds(10);
  digitalWrite(T2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(E2, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if(distance <= san_object.san_full && distance < san_object.san_low)
  return 0xFF;
  if(distance >= san_object.san_low && distance < san_object.san_empty)
  return 0xCC;
  if(distance >= san_object.san_empty)
  return 0xAA;
  return distance;
}
char s1_sense()
{
  // Clears the trigPin condition
  digitalWrite(T1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(T1, HIGH);
  delayMicroseconds(10);
  digitalWrite(T1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(E1, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if(distance <= san_object.object_dist )
  return true;
  else
  return false;
}

