const int MQ2_pin = A5; // Analog pin connected to MQ2 sensor
const int buzzerPin = 8; // Digital pin connected to the buzzer
const int ledPin = 9; // Digital pin connected to the LED
int threshold = 100; // Threshold value for smoke detection

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  int sensorValue = analogRead(MQ2_pin); // Read analog value from sensor
  Serial.println(sensorValue); // Print the sensor value to serial monitor
  
  if (sensorValue > threshold) {
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(ledPin, HIGH); // Turn on the LED
    delay(1000); // Wait for 1 second
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    digitalWrite(ledPin, LOW); // Turn off the LED
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    digitalWrite(ledPin, LOW); // Turn off the LED
  }

  /*if(sensorValue > 200){
    tone(buzzerPin,1000,1000);
    digitalWrite(ledPin, HIGH);
  }
  else{
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  } */
  delay(100); // Delay for 100 milliseconds
}
