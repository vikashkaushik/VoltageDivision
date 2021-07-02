/*
 * Project VoltageDivision
 * Description: Using Lux sensor, based on how much light is shown, it makes the LED light up more or less.
 * Author: Vikash Kaushik
 * Date: 7/1/21
 */
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
uint16_t value; // initallizes a max a nd min value for calabration;
uint16_t maxValue; 
uint16_t minValue; 
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D6, OUTPUT);
  pinMode(A5, INPUT);

  maxValue = max(maxValue, value); //sets a max value
  minValue = min(minValue , value); // sets a min value
  
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  
 
  Serial.begin(9600); 
  value = analogRead(A5); // reads the value that the LUX has
  
  Serial.println(value); 
 
  analogWrite(D6, map(value, minValue, maxValue, 0, 255)); // scale value to the min and max value range
  
}