// A short program to read analog values and send them to the PC every two seconds.
//
// The output signal from the LaJolla riometer is a voltage 0..5V and it is connected
// to the analog A1

// The board in use is an Arduino Nano, so the built-in A/D-converter has only 10-bit resolution.
// If one does not want to use a better external converter, the obvious next step would be to 
// use oversampling followed by averaging. Also, the internal analog reference is actually the 5V 
// power supply line: an external reference would improve the situation. For quick functionality tests, 
// however, these enhancements are not at all critical.

// The input pin protection comprises a simple RC-lowpass filter (3k3 and 100nF -> f0=500Hz)
// followed by clamp diodes to +5V and GND.


// Time between reading the value
const unsigned long INTERVAL = 2000;
unsigned long thistime;
unsigned long lasttime = 0;

// Input pin
const int inputPin = A0;

//--------------------------------------------------------------
// Each analog reading is an average of several measurements.
//
// On Arduino Nano, the conversion takes about 100us, so an average
// of 16 conversion takes about 2ms.

uint16_t readAnalogSensor(int pin)
{
  uint32_t value = 0;
  for (uint8_t i = 0; i < 16; i++) {
    value += analogRead(pin);
  }
  value = value >> 4; // Divide by 2^4=16
  return (uint16_t)value;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  analogReference(DEFAULT);
  Serial.begin(115200);
  while (!Serial) { // Wait for the connection
    delay(1);
  }
}

// =============================================================
// Read the analog input value at regular intervals and
// send the value to the PC.

void loop() {
  thistime = millis();
  if (thistime - lasttime > INTERVAL) {
    lasttime = thistime;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    uint16_t voltage = readAnalogSensor(inputPin);
    Serial.println(voltage);
  }
  delay(1);
}
