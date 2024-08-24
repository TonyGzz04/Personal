#include <MPU9250_asukiaaa.h>

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 21
#define SCL_PIN 22
#endif

MPU9250_asukiaaa mySensor;
float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;

float tiempo=0;
float v=0;
float dist=0;
float distA=0;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("started");

#ifdef _ESP32_HAL_I2C_H_ // For ESP32
  Wire.begin(SDA_PIN, SCL_PIN);
  mySensor.setWire(&Wire);
#endif

  mySensor.beginAccel();
  mySensor.beginGyro();
  mySensor.beginMag();

  // You can set your own offset for mag values
  // mySensor.magXOffset = -50;
  // mySensor.magYOffset = -55;
  // mySensor.magZOffset = -10;
}

void loop() {
  uint8_t sensorId;
  int result;

/*
  result = mySensor.readId(&sensorId);
  if (result == 0) {
    Serial.println("sensorId: " + String(sensorId));
  } else {
    Serial.println("Cannot read sensorId " + String(result));
  }
  */

  result = mySensor.accelUpdate();
  if (result == 0) {
    aX = mySensor.accelX();
    aY = mySensor.accelY();
    aZ = mySensor.accelZ();
    aSqrt = mySensor.accelSqrt()*9.81;
    tiempo=millis();
    //Serial.println("accelX: " + String(aX*9.81));
    //Serial.println("accelY: " + String(aY*9.81));
   // Serial.println("accelZ: " + String(aZ*9.81));
    //Serial.println("accelSqrt: " + String(aSqrt*9.81));
    tiempo=(millis()-tiempo)/1000;
    dist=dist+(v*tiempo+0.5*aX*(tiempo*tiempo));
    v=(dist-distA)*tiempo;
    Serial.print("distancia: ");
    Serial.println(dist);
    distA=dist;
  } else {
    Serial.println("Cannod read accel values " + String(result));
  }

/*
  result = mySensor.gyroUpdate();
  if (result == 0) {
    gX = mySensor.gyroX();
    gY = mySensor.gyroY();
    gZ = mySensor.gyroZ();
    Serial.println("gyroX: " + String(gX));
    Serial.println("gyroY: " + String(gY));
    Serial.println("gyroZ: " + String(gZ));
  } else {
    Serial.println("Cannot read gyro values " + String(result));
  }
*/
}
