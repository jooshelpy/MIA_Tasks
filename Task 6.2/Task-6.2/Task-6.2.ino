#define encoderPinA 2
#define encoderPinB 3
#define dt 0.01
#define PI 3.14159
#define fc 1.0 // Define the cutoff frequency for the low-pass filter

const int alpha = dt / (dt + 1.0 / (2.0 * 3.0 * PI * fc));

long long count = 0;
long long filteredCount = 0;

void setup() {
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoder, RISING);
  // Attach interrupts for both A and B channels
  attachInterrupt(digitalPinToInterrupt(encoderPinB), updateEncoder, RISING);
  Serial.begin(9600);
}

void loop() {
  // Read filtered count
  noInterrupts();
  int currentCount = filteredCount;
  interrupts();

  // Do something with the filtered count
  Serial.println(currentCount);

  // Add your control algorithm here

  delay(100); // Adjust as needed
}

void updateEncoder() {
  static int previousA = LOW;
  static int previousB = LOW;

  int newA = digitalRead(encoderPinA);
  int newB = digitalRead(encoderPinB);

  if ((previousA == LOW && newA == HIGH) || (previousB == LOW && newB == HIGH)) {
    count++;
  } else {
    count--;
  }

  // Apply the LPF
  filteredCount = alpha * count + (1 - alpha) * filteredCount;

  previousA = newA;
  previousB = newB;
}
