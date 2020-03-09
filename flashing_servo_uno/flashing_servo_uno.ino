#include <SoftwareSerial.h>

#include <Servo.h>
Servo myservo;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
int pos = 0;

int color[3];
int colorIndex;
bool resetColorIndex = false;
char temp[20];
SoftwareSerial mySerial(2, 3);

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(9);
  myservo.write(60);
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  colorIndex = 0;
}

void loop()
{
  if (resetColorIndex)
  {
    //colorIndex = 0;
    Serial.write("Reset: colorIndex = 0.\r\n");
  }
  if (Serial.available())
  {
    Serial.write("Serial.available()\r\n");
  }
  if (Serial.available() && Serial)
  {
    Serial.write("Serial.available()&& Serial.dtr()\r\n");
  }
  if (Serial.available() > 0 && Serial)
  { // || colorIndex != 0) {//Serial &&
    Serial.println("Hi there, new serial monitor session");
    //char ch = Serial.read();
    //Serial.print(ch, HEX);
    color[colorIndex++] = Serial.parseInt(); //ch;//Serial.read();

    sprintf(temp, "cindex=,%i,%i\r", colorIndex, color[0]);
    Serial.println(temp);
    if (colorIndex == 1)
    { //1

      //       Serial.flush();
      //      analogWrite(redPin, color[0]);
      if (color[0] == 1)
      {
        myservo.write(0);
        delay(2000);
        for (pos = 0; pos <= 75; pos += 1)
        { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos); // tell servo to go to position in variable 'pos'
          delay(5);           // waits 15ms for the servo to reach the position
        }
        delay(1000);
        Serial.write("ceral detected.\r\n");
      }

      else if (color[0] == 2)
      {
        myservo.write(180);
        delay(2000);
        for (pos = 180; pos <= 75; pos -= 1)
        { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos); // tell servo to go to position in variable 'pos'
          delay(20);          // waits 15ms for the servo to reach the position
        }
        delay(1000);
        Serial.write("mallow detected.\r\n");
      }

      else if (color[0] == 9)
      {
        myservo.write(90);
        //freeze90 = true;
        Serial.write("RESET.\r\n");
        delay(10000);
        Serial.write("Starting Up.\r\n");
        delay(1000);
      }

      else if (color[0] > 9 || color[0] < 1 && color[0] != 0)
      {
        int mod180 = color[0] % 181;
        myservo.write(mod180);
        //freeze90 = true;
        delay(1000);
        Serial.write(mod180);
      }

      while (Serial.available() > 1)
      {
        int throwaway = Serial.read();
        Serial.write("Throwing away.\r\n");
        /*if( throwaway == 1 || throwaway == 2 ){
          color[colorIndex++] = throwaway;//Serial.read();
        }
        else {
          resetColorIndex = true;
          colorIndex = 0;
        }*/
        Serial.write("Throwing away.\r\n");
      }

      Serial.flush();
      colorIndex = 0;
    }
  }
  else
  {
    //Serial.println("asdf");
    for (pos = 60; pos <= 90; pos += 1)
    { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(3);           // waits 15ms for the servo to reach the position
    }
    for (pos = 90; pos >= 60; pos -= 1)
    {                     // goes from 180 degrees to 0 degrees
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(3);           // waits 15ms for the servo to reach the position
    }
    delay(20);
  }
}

void old_loop()
{
  myservo.write(pos);
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  move_servo();
  digitalWrite(LED_BUILTIN, LOW);
  pos = 0;
  colorIndex = 0;
  myservo.write(pos);
}

void move_servo()
{
  if (pos == 0)
  {
    myservo.write(0);
    delay(2000);
    for (pos = 0; pos <= 75; pos += 1)
    { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(5);           // waits 15ms for the servo to reach the position
    }
    myservo.write(180);
    delay(2000);
    delay(1000);
  }
  else
  {
    for (pos = 180; pos <= 75; pos -= 1)
    { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(20);          // waits 15ms for the servo to reach the position
    }
    delay(1000);
  }
}
