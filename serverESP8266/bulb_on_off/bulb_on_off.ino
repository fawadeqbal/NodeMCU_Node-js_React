
const int relayPin = 4; // Pin connected to the relay

// Variables
bool isBulbOn = false; // Flag to track bulb state

void setup() {
  // Set relay pin as an output
  pinMode(relayPin, OUTPUT);
  
  // Initially turn off the bulb
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Toggle the bulb state
  if (isBulbOn) {
    digitalWrite(relayPin, LOW); // Turn off the bulb
    isBulbOn = false;
    delay(2000); // Delay for 1 second
  } else {
    digitalWrite(relayPin, HIGH); // Turn on the bulb
    isBulbOn = true;
    delay(2000); // Delay for 1 second
  }
}
