#include <Wire.h>

#define MPU 0x68 // MPU6050 I2C address
#define PWR_MGMT_1 0x6B

// Variables for sensor data and yaw angle calculation
float AccZ;         // Accelerometer Z-axis reading
float GyroZ;        // Gyroscope Z-axis reading
float gyroAngleZ;   // Gyroscope angle estimate (not used in this code)
float yaw;          // Yaw angle in degrees
float elapsedTime, currentTime, previousTime;

void setup() {
  Serial.begin(9600);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(PWR_MGMT_1);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission

  delay(20);
}
void loop() {
  // === Read acceleromter data === //
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers

  //For a range of +-2g, we need to divide the raw values by 16384, according to the datasheet
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value

  // === Read gyroscope data === //
  previousTime = currentTime;        // Previous time is stored before the actual time read
  currentTime = millis();            // Current time actual time read
  elapsedTime = (currentTime - previousTime) / 1000; // Divide by 1000 to get seconds
  Wire.beginTransmission(MPU);
  Wire.write(0x43); // Gyro data first register address 0x43
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 4 registers total, each axis value is stored in 2 registers

  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0; // For a 250deg/s range we have to divide first the raw value by 131.0, according to the datasheet

  // Correct the outputs with the calculated error values
  GyroZ = GyroZ + 0.79; // GyroErrorZ ~ (-0.8)
  
  // Currently the raw values are in degrees per seconds, deg/s, so we need to multiply by seconds (s) to get the angle in degrees
  yaw =  yaw + GyroZ * elapsedTime;
  
  // Print the values on the serial monitor
  Serial.print("Yaw: ");
  Serial.println(yaw);
 
}
