/*Control 2 DC Motors with Smartphone via Bluetooth*/
/*Created by Daniel Dominguez @dominguezdaniel*/

int motorPin1 = 6; // pin 2 on L293D IC
int motorPin2 = 8; // pin 7 on L293D IC
int enablePin = 10; // pin 1 on L293D IC

int motor2Pin1 = 13; // pin 2 on L293D IC
int motor2Pin2 = 12 ; // pin 7 on L293D IC
int enable2Pin = 9; // pin 1 on L293D IC

int state;
int flag=0; //makes sure that the serial only prints once the state
 
void setup() {
// sets the pins as outputs:
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(enablePin, OUTPUT);

pinMode(motor2Pin1, OUTPUT);
pinMode(motor2Pin2, OUTPUT);
pinMode(enable2Pin, OUTPUT);

// sets enablePin high so that motor can turn on:
digitalWrite(enablePin, HIGH);
digitalWrite(enable2Pin, HIGH);
// initialize serial communication at 9600 bits per second:
Serial.begin(57600);
}
 
void loop() {
//if some date is sent, reads it and saves in state
if(Serial.available() > 0){
state = Serial.read();
flag=0;
}
// if the state is '0' the DC motor will turn off
if (state == '0') {
digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D low
digitalWrite(motor2Pin2, LOW); // set pin 7 on L293D low

if(flag == 0){
Serial.println("Motor: off");
flag=1;
}
}
// if the state is '1' the motor will turn right
else if (state == '1') {
digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
if(flag == 0){
Serial.println("Motor: right");
flag=1;
}
}
// if the state is '2' the motor will turn left
else if (state == '2') {
digitalWrite(motorPin1, HIGH); // set pin 2 on L293D high
digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
if(flag == 0){
Serial.println("Motor: left");
flag=1;
}
}

else if (state == '3') {
digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D low
digitalWrite(motor2Pin2, HIGH); // set pin 7 on L293D high
if(flag == 0){
Serial.println("Motor2: right");
flag=1;
}
}

else if (state == '4') {
digitalWrite(motor2Pin1, HIGH); // set pin 2 on L293D high
digitalWrite(motor2Pin2, LOW); // set pin 7 on L293D low
if(flag == 0){
Serial.println("Motor2: left");
flag=1;
}
}

}
