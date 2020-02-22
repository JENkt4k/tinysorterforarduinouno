//int cnt = 0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
 Serial.begin(9600); // initialize serial communications
}
 
void loop() {
  
 int potentiometer = 10;// analogRead(A0);                  // read the input pin
 int mappedPot = map(potentiometer, 0, 1023, 0, 255); // remap the pot value to fit in 1 byte
 Serial.println(mappedPot);                           // print it out the serial port
 delay(100);// slight delay to stabilize the ADC
 /*cnt = cnt +100;
 if(cnt ==100){
  digitalWrite(LED_BUILTIN, HIGH);
 }else if(cnt == 200){
  digitalWrite(LED_BUILTIN, LOW);
  cnt=0;
 }*/
}
