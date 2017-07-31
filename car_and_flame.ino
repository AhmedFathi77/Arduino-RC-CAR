

#define IN1  5              //the forward rotational direction pin of the right motors
#define IN2  6              //the backward rotational direction pin of the right motors
#define IN3  9             //the forward rotational direction pin of the left motors
#define IN4  10 
#define EN1  3            //the PWM pin of the left motors
#define EN2  11             //the PWM pin of the left motors
#define sesensor  A0  
#define buzzer 4
#define flamepin A1

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
  pinMode(sesensor,INPUT);
  
   pinMode(buzzer,OUTPUT);
  pinMode(flamepin,INPUT);
  Serial.begin(9600);    //setup serial communication protocol with speed of data trans and recive 9600
}

 int forward(int speeder)    // function to move the car forward with PWM value masked in speeder value 
 {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);  
 }

 int backward(int speeder)     // function to move the car backward with PWM value masked in speeder value
 {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
    
 }

 int turn_right(int speeder)  // function to move the car turn right with PWM value masked in speeder value
 {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }
 
 int turn_left(int speeder)  // function to move the car turn left with PWM value masked in speeder value
 {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }

 int turn_round(int speeder)  // function to move the car turn round it self with fixed center of rotating  with PWM value masked in speeder value
 {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }


void loop() 
{
   
   Serial.println(analogRead(A1));
   while(1)                   //for ever loop as this code will still applied forever the robot working
   {
      if(Serial.available())          //making condition as asking if the arduino reciving data from the bluetooth module
    {
      int data = Serial.read();           //put the readed data from bluetooth in varialbe called data

 while(data == '1')                     //while the send data equal 1 which customized to be the up arrow on the mobile app make it move forward 
 {
  forward(220);                           //the car will move forward with PWM 220 of 255 
  delay(5);                               // delay with 5 ms only as the time for excuting forward is so small so we need to make delay to see forward function 
  forward(0);                              // the turn off the forward function by sending the pwm value with zero
  break;                                   // break to get out of this loop and start checking agian for the right condtion with the recived value by bluetooth
 }
                 /*******************this previous sequence as when sending 1 from the mobile app the app still sending 1 even if yo all the way give your finger uo
                       so we made it with delay 5 ms only then stop then start check again if i still holding the 1 or i gave my finger away if i gave it up it
                   will start checking another conditions if i still on the top arrow which sends 1 it will still forward **********************/ 
                                                           
 
  while (data == '2') 
 { 
 backward(220);
 delay(5);
 backward(0);
 break;
 }
while (data=='3') 
 {
  turn_left(220);
  delay(5);
  turn_left(0);
  break;
 }
while(data=='4') 
 {
  turn_right(220);
  delay(5);
  turn_right(0);
  break;
 }
 while(data=='5') 
 {
  turn_round(220);
  delay(5);
  turn_round(0);
  break;
 }
   }


int soundsensor=analogRead(sesensor);
if(soundsensor>=54){
  forward(220);
  delay(5);
  forward(0);
  break;             
}

int flamestatus=analogRead(flamepin);
if(flamestatus<=100){
  digitalWrite(buzzer,HIGH);}else if(flamestatus>100) digitalWrite(buzzer,LOW);

  
}




   
      }
   






