/******************************************************************************
Flex_Sensor_Example.ino
Example sketch for SparkFun's flex sensors
  (https://www.sparkfun.com/products/10264)
Jim Lindblom @ SparkFun Electronics
April 28, 2016

Create a voltage divider circuit combining a flex sensor with a 47k resistor.
- The resistor should connect from A0 to GND.
- The flex sensor should connect from A0 to 3.3V
As the resistance of the flex sensor increases (meaning it's being bent), the
voltage at A0 should decrease.

Development environment specifics:
Arduino 1.6.7
******************************************************************************/
const int thumb_pin = A0; // Pin connected to voltage divider output
const int index_pin = A1;
const int middle_pin = A2;


// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 3.3; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

void setup() 
{
  Serial.begin(115200);
  pinMode(thumb_pin, INPUT);
  pinMode(index_pin, INPUT);
  pinMode(middle_pin, INPUT);
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  // int flexADC = analogRead(thumb_pin);

  int thumb = analogRead(thumb_pin);
  delay(200);
  int index = analogRead(index_pin);
  delay(200);
  int middle = analogRead(middle_pin);
  delay(200);

  Serial.println(String(calcFlex(thumb)) + "," + String(calcFlex(index)) + "," + String(calcFlex(middle)));
  
  // // Use the calculated resistance to estimate the sensor's
  // // bend angle:
  // float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
  //                  0, 90.0);
  // Serial.println("Bend: " + String(angle) + " degrees");
  // Serial.println();
}

float calcFlex(int reading){
  float flexV = reading * VCC / 1023.0;
  float flexR = R_DIV * (VCC / flexV - 1.0);

  //Serial.println("Resistance: " + String(flexR) + " ohms");
  return flexR;
}
