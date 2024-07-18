// C++ code

// Declare global variables
int distance = 0;
int i = 0;
int between = 0;
int Light_Sensor = 0;
int pHOTOSENSOR = 0;
int lightsensor = 0;

// Function to read the ultrasonic distance
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);  // Set the trigger pin as an output
  digitalWrite(triggerPin, LOW); // Clear the trigger pin
  delayMicroseconds(2); // Wait for 2 microseconds
  // Set the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); // Wait for 10 microseconds
  digitalWrite(triggerPin, LOW); // Set the trigger pin back to LOW
  pinMode(echoPin, INPUT); // Set the echo pin as an input
  // Read the echo pin and return the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

// Setup function to initialize the pins
void setup() {
  Serial.begin(9600); // Begin serial communication at a baud rate of 9600 bits per second
  pinMode(A1, INPUT); // Set analog pin A1 as an input
  pinMode(12, OUTPUT); // Set digital pin 12 as an output
  pinMode(11, OUTPUT); // Set digital pin 11 as an output
  pinMode(10, OUTPUT); // Set digital pin 10 as an output
  pinMode(9, OUTPUT);  // Set digital pin 9 as an output
}

// Loop function to run repeatedly
void loop() {
  // Read the ultrasonic distance and convert to cm
  distance = 0.01723 * readUltrasonicDistance(A0, A0);
  Serial.println(distance); // Print the distance to the serial monitor
  lightsensor = analogRead(A1); // Read the value from the light sensor
  if (distance <= 330) { // If the distance is less than or equal to 330 cm
    digitalWrite(12, HIGH); // Turn on the LED connected to pin 12
  } else {
    delay(500); // Wait for 500 milliseconds
    digitalWrite(12, LOW); // Turn off the LED connected to pin 12
  }
  if (distance <= 120) { // If the distance is less than or equal to 120 cm
    digitalWrite(11, HIGH); // Turn on the LED connected to pin 11
    // Set the brightness of the LED connected to pin 11 based on the light sensor value
    analogWrite(11, map(lightsensor, 0, 1023, 0, 255));
    delay(100); // Wait for 100 milliseconds
  } else {
    delay(500); // Wait for 500 milliseconds
    digitalWrite(11, LOW); // Turn off the LED connected to pin 11
  }
}











---------------------------------------------------------------------------------------------------------------------------------------------
// C++ code
//
int distance = 0;

int i = 0;

int between = 0;

int Light_Sensor = 0;

int pHOTOSENSOR = 0;

int lightsensor = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(A0, A0);
  Serial.println(distance);
  lightsensor = analogRead(A1);
  if (distance <= 330) {
    digitalWrite(12, HIGH);
  } else {
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(12, LOW);
  }
  if (distance <= 120) {
    digitalWrite(11, HIGH);
    analogWrite(11, map(lightsensor, 0, 1023, 0, 255));
    delay(100); // Wait for 100 millisecond(s)
  } else {
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(11, LOW);
  }

}
