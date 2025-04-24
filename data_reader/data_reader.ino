//*
data_reader.ino
Vineeth Kirandumkara
*/
const int thumb_pin = A0; // Pin connected to voltage divider output
const int index_pin = A1;
const int middle_pin = A2;


// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 3.3; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

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
  
}

float calcFlex(int reading){
  float flexV = reading * VCC / 1023.0;
  float flexR = R_DIV * (VCC / flexV - 1.0);

  //Serial.println("Resistance: " + String(flexR) + " ohms");
  return flexR;
}
