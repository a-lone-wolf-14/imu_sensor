//also work on tilt componsated compass

#include<Wire.h>
#include<Adafruit_Sensor.h>
#include<Adafruit_BNO055.h>
#include<utility/imumaths.h>
#include<math.h>
#define PI 3.14159265358979323846

Adafruit_BNO055 imu_sensor= Adafruit_BNO055();
// float a_theta, a_theta_n, a_theta_f, a_phi, a_phi_n, a_phi_f;
// float g_theta=0, g_phi=0;
// float theta, phi;
// float psi;
// float dt;
// unsigned long milli;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  imu_sensor.begin();
  delay(1000);
  imu_sensor.setExtCrystalUse(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t system, accel_cal, gyro_cal, mag_cal=0;
  imu_sensor.getCalibration(&system, &gyro_cal, &accel_cal, &mag_cal);
  imu::Vector<3> accel=imu_sensor.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  imu::Vector<3> gyro=imu_sensor.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  imu::Vector<3> mag=imu_sensor.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);

  Serial.print("[");
  Serial.print(accel.x()/9.8);
  Serial.print(",");
  Serial.print(accel.y()/9.8);
  Serial.print(",");
  Serial.print(accel.z()/9.8);
  Serial.print("]");

  Serial.print("[");
  Serial.print(gyro.x());
  Serial.print(",");
  Serial.print(gyro.y());
  Serial.print(",");
  Serial.print(gyro.z());
  Serial.print("]");

  Serial.print("[");
  Serial.print(mag.x());
  Serial.print(",");
  Serial.print(mag.y());
  Serial.print(",");
  Serial.print(mag.z());
  Serial.print("]");
  
  Serial.print("[");
  Serial.print(gyro_cal);
  Serial.print(",");
  Serial.print(accel_cal);
  Serial.print(",");
  Serial.print(mag_cal);
  Serial.print("]");
  Serial.print(system);

  // a_theta=atan2(accel.x(),accel.z())/PI*180; //pitch angle
  // a_phi=atan2(accel.y(),accel.z())/PI*180; //roll angle
  // a_phi_n=.9*a_phi_f+.1*a_phi;

  // Serial.print("[");
  // Serial.print(a_theta);
  // Serial.print(",");
  // Serial.print(a_phi);
  // Serial.println("]");

  // theta_f=theta_;
  // phi_f=phi_;

  // dt=(millis()-milli)/1000.;
  // milli=millis();

  // g_theta=g_theta+(gyro.y()*dt);
  // g_phi=g_phi+(gyro.x()*dt);

  // theta=.95*g_theta+.05*a_theta;
  // phi=.95*g_phi+.05*g_theta;

  // psi=atan2(mag.y(),mag.x())/PI*180; //compass angle
}
