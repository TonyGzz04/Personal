// Pin connections
const int encoderPinA = 5;    // Encoder signal pin A
const int encoderPinB = 5;    // Encoder signal pin B

// Constants
const float encoderResolution = 20.0;   // Number of encoder pulses per revolution
const unsigned long updateInterval = 1000;   // Interval (in milliseconds) to calculate RPM

// Variables
volatile unsigned int encoderCount = 0;    // Keeps track of the encoder count
unsigned long previousMillis = 0;          // Previous time for RPM calculation

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set encoder pin modes
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  // Attach interrupts to encoder pins
  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoderInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), handleEncoderInterrupt, CHANGE);
}

void loop() {
  // Calculate RPM at regular intervals
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= updateInterval) {
    float rotations = encoderCount / encoderResolution;
    float rpm = (rotations / (updateInterval / 1000.0)) * 60.0;

    // Print RPM
    Serial.println(rpm);

    // Reset encoder count
    encoderCount = 0;

    // Update previous time
    previousMillis = currentMillis;
  }

  // Do other tasks if needed
}

void handleEncoderInterrupt() {
  // Read the current state of the encoder pins
  int currentEncoderState = (digitalRead(encoderPinA) << 1) | digitalRead(encoderPinB);

  // Determine the direction of rotation based on the previous and current states
  if (currentEncoderState == 0b01 || currentEncoderState == 0b10) {
    encoderCount++;
  } else {
    encoderCount--;
  }
}