// Flex Sensor Pins
const int flexPin1 = A0;
const int flexPin2 = A1;
const int flexPin3 = A2;
const int flexPin4 = A3;

void setup() {
  Serial.begin(9600);

  pinMode(flexPin1,INPUT);
  pinMode(flexPin2,INPUT);
  pinMode(flexPin3,INPUT);
  pinMode(flexPin4,INPUT);
}

void loop() {
  // Read the analog values from the flex sensors
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);
  int flexValue3 = analogRead(flexPin3);
  int flexValue4 = analogRead(flexPin4);

  // Print the received values for testing

  // Serial.print("Flex Sensor 1: ");
  Serial.println(flexValue1);
  // Serial.print("Flex Sensor 2: ");
  Serial.println(flexValue2);
  // Serial.print("Flex Sensor 3: ");
  Serial.println(flexValue3);
  // Serial.print("Flex Sensor 4: ");
  Serial.println(flexValue4);

  delay(5000);
}
