/*
QMC5883LCompass.h Library Calibration Example Sketch
Learn more at [https://github.com/mprograms/QMC5883LCompass]

Upload this calibration sketch onto your Arduino to provide calibration for your QMC5883L chip.
After upload, run the serial monitor and follow the directions.
When prompted, copy the last line into your project's actual sketch.

===============================================================================================================
Release under the GNU General Public License v3
[https://www.gnu.org/licenses/gpl-3.0.en.html]
===============================================================================================================











                                          UTILITY SKETCH
                                    NO SERVICABLE PARTS BELOW












*/
#include <QMC5883LCompass.h>
#include <SoftwareSerial.h>   //incluye librería 

QMC5883LCompass compass;

SoftwareSerial miBT(10,11);

int calibrationData[3][2];
bool changed = false;
bool done = false;
int t = 0;
int c = 0;

int motor_i_adelante = 5;
int motor_i_atras = 6;

// Motor derecho
int motor_d_adelante = 3;
int motor_d_atras = 4;

char dato;            //variable que guardará el dato que manda el teléfono al módulo bluetooth
String mensaje;       //variable que junta los caracteres de la variable anterior

void setup() {
  Serial.begin(9600);
   miBT.begin(9600);

   pinMode(motor_i_adelante, OUTPUT);
  pinMode(motor_i_atras, OUTPUT);
  pinMode(motor_d_adelante, OUTPUT);
  pinMode(motor_d_atras, OUTPUT);
  
  compass.init();
  
  Serial.println("This will provide calibration settings for your QMC5883L chip. When prompted, move the magnetometer in all directions until the calibration is complete.");
  Serial.println("Calibration will begin in 5 seconds.");
  delay(5000);
  
}

void loop() {
  int x, y, z;

  

  
  // Read compass values
  compass.read();

  // Return XYZ readings
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  changed = false;

  if(x < calibrationData[0][0]) {
    calibrationData[0][0] = x;
    changed = true;
  }
  if(x > calibrationData[0][1]) {
    calibrationData[0][1] = x;
    changed = true;
  }

  if(y < calibrationData[1][0]) {
    calibrationData[1][0] = y;
    changed = true;
  }
  if(y > calibrationData[1][1]) {
    calibrationData[1][1] = y;
    changed = true;
  }

  if(z < calibrationData[2][0]) {
    calibrationData[2][0] = z;
    changed = true;
  }
  if(z > calibrationData[2][1]) {
    calibrationData[2][1] = z;
    changed = true;
  }

  if (changed && !done) {
    Serial.println("CALIBRATING... Keep moving your sensor around.");
    c = millis();
  }
    t = millis();

    derecha();
  
  
  if ( (t - c > 5000) && !done) {
    done = true;
    alto();
    Serial.println("DONE. Copy the line below and paste it into your projects sketch.);");
    Serial.println();

    
      
    Serial.print("compass.setCalibration(");
    Serial.print(calibrationData[0][0]);
    Serial.print(", ");
    Serial.print(calibrationData[0][1]);
    Serial.print(", ");
    Serial.print(calibrationData[1][0]);
    Serial.print(", ");
    Serial.print(calibrationData[1][1]);
    Serial.print(", ");
    Serial.print(calibrationData[2][0]);
    Serial.print(", ");
    Serial.print(calibrationData[2][1]);
    Serial.println(");");
  
    delay(1000);
  
    miBT.write(calibrationData[0][0]);
    delay(100);
    miBT.write(calibrationData[0][1]);
    delay(100);
    miBT.write(calibrationData[1][0]);
    delay(100);
    miBT.write(calibrationData[1][1]);
    delay(100);
    miBT.write(calibrationData[2][0]);
    delay(100);
    miBT.write(calibrationData[2][1]);


  while(1){}

    
    }
  


 
}


void derecha()
{
  // Girar a la izquierda (predefinido)
  digitalWrite(motor_i_adelante, HIGH);
  digitalWrite(motor_i_atras, LOW);
  digitalWrite(motor_d_adelante, LOW);
  digitalWrite(motor_d_atras, HIGH);
}


void alto()
{
  digitalWrite(motor_i_adelante, LOW);
  digitalWrite(motor_i_atras, LOW);
  digitalWrite(motor_d_adelante, LOW);
  digitalWrite(motor_d_atras, LOW);
}
