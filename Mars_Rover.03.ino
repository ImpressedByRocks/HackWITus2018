/*
Team Curiouser Rover
Most of this code is functional, but not implemented on the rover.
  - Due to sizing problems with the solenoids, a proper proactive shock was not implemented.
  - The code below shows how we would implement the system on an arduino, given a power switching relay to control a large solenoid
  - The distance sensor is an HC-SR05 ultrasonic sensor.  it is literally the sensor i use at every single hackathon. -tr
  - It also shows various calculations as to how we would extrapolate data such as velocity, obstacle height, and bounce time

  - some future functionality might be soft-force from the solenoids via a pwm algorithm mapped to obstacle height data
  - another future possibility is the integration of various metal materials into the tire design, or use a more advanced 3d printing process.


*/

int trigPin1 = 2;
int echoPin1 = 3;
int trigPin2 = 4;
int echoPin2 = 5;
int solenoidPin1 = 12;
int solenoidPin2 = 13;
long duration1, duration2, cm1, cm2;
int flag;
float distL = 0.2794*.001;    //distance between two solinoids (in meters)* micrometers)
float distH;



void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  digitalWrite(trigPin1,HIGH);
  digitalWrite(trigPin2,HIGH);
  delay(10);
  digitalWrite(trigPin1,LOW);
  digitalWrite(trigPin2,LOW);
  flag = false;
  float count = 0;
  while (flag == false){
    count+=1.0;
    if(digitalRead(echoPin1) == HIGH || digitalRead(echoPin2) == HIGH){
      flag = true;
    }
    delay(10)
  }
  float dist;
  float Vel = distL/1;
  dist=(344* (count*.01))/2.0;
  if(echoPin1 == HIGH){
    digitalWrite(solenoidPin1,HIGH);
    digitalWrite(solenoidPin2,HIGH);
    int tim = dist/Vel;
    delay(tim);                     // Waits X time beore activating solenoids
    digitalWrite(solenoidPin1,LOW);
    digitalWrite(solenoidPin2,LOW);
  }
  if(echoPin2 == HIGH){
    digitalWrite(solenoidPin1,HIGH);
    digitalWrite(solenoidPin2,HIGH);
    int tim = dist/Vel;
    delay(tim);                       // Waits X time beore activating solenoids
    digitalWrite(solenoidPin1,LOW);
    digitalWrite(solenoidPin2,LOW);
  }
}




/* scratchpad
// IGNORE BELOW



// put your main code here, to run repeatedly:
//digitalWrite(trigPin1, LOW);
//delayMicroseconds(5);
//digitalWrite(trigPin1, HIGH);
//delayMicroseconds(10);
//digitalWrite(trigPin1, LOW);

//digitalWrite(trigPin2, LOW);
//delayMicroseconds(5);
//digitalWrite(trigPin2, HIGH);
//delayMicroseconds(10);
//digitalWrite(trigPin2, LOW);

//pinMode(echoPin1, INPUT);
//duration1 = pulseIn(echoPin1, HIGH);

//pinMode(echoPin2, INPUT);
//duration2 = pulseIn(echoPin2, HIGH);

//cm1 = (duration1/2) / 29.1;
//cm2 = (duration2/2) / 29.1;


//Need to look at distance
//if (cm1 < 10  || cm2 < 10){
//digitalWrite(solenoidPin1, HIGH);     //Switch Solenoid ON
//delay(1000);                          //Wait 1 Second
//digitalWrite(solenoidPin1, LOW);      //Switch Solenoid OFF
//delay(1000);

//digitalWrite(solenoidPin2, HIGH);      //Switch Solenoid ON
//delay(1000);                           //Wait 1 Second
//digitalWrite(solenoidPin2, LOW);       //Switch Solenoid OFF
//delay(1000);
//}*/
