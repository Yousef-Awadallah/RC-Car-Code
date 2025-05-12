;
/*
 * Acknowledgment: this code was modified by me (Yousef) to work for my project, but originally found on the internet
 * Project: SMARTPHONE CONTROLLED BLUETOOTH RACING CAR
 */
 
 int outPin1 = 5;     //motor1
 int outPin2 = 6;    //motor1

 int outPin3 = 10;   //motor2
 int outPin4 = 11;   //motor2

 char bt = 0;       //BT 
 

 void setup()
 {
   Serial.begin(9600);
   
   pinMode(outPin1,OUTPUT);
   pinMode(outPin2,OUTPUT);
   pinMode(outPin3,OUTPUT);
   pinMode(outPin4,OUTPUT);
   
 }
 void loop()
 {
   if (Serial.available() > 0) //save incoming data to variable 'bt'
   {
     bt = Serial.read();

   
     if(bt == 'F')           //move forwards
     {
       digitalWrite(outPin1,HIGH);
       digitalWrite(outPin2,LOW);
       digitalWrite(outPin3,LOW);
       digitalWrite(outPin4,LOW);
     }
     else if (bt == 'B')      //move backwards
     {
       digitalWrite(outPin1,LOW);
       digitalWrite(outPin2,HIGH);
       digitalWrite(outPin3,LOW);
       digitalWrite(outPin4,LOW);
     }
     else if (bt == 'S')     //stop!!
     {   
       digitalWrite(outPin1,LOW);
       digitalWrite(outPin2,LOW);
       digitalWrite(outPin3,LOW);
       digitalWrite(outPin4,LOW);
     }
     else if (bt == 'R')    // turn wheels right
     {
       digitalWrite(outPin3,LOW);
       digitalWrite(outPin4,HIGH);
       digitalWrite(outPin1,LOW);
       digitalWrite(outPin2,LOW);
     }
     else if (bt == 'L')     //turn wheels left
     {
       digitalWrite(outPin3,HIGH);
       digitalWrite(outPin4,LOW);
       digitalWrite(outPin1,LOW);
       digitalWrite(outPin2,LOW);
     }
     else if (bt== 'G')      //move forward left
     {
      digitalWrite(outPin1,HIGH);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,HIGH);
      digitalWrite(outPin4,LOW);
     }
     else if (bt== 'I')      //move forward right
     {
      digitalWrite(outPin1,HIGH);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,LOW);
      digitalWrite(outPin4,HIGH);
     }
     else if (bt== 'H')      //move backward left
     {
      digitalWrite(outPin1,LOW);
      digitalWrite(outPin2,HIGH);
      digitalWrite(outPin3,HIGH);
      digitalWrite(outPin4,LOW);
     }
     else if (bt=='J')       //move backward right
     {
      digitalWrite(outPin1,LOW);
      digitalWrite(outPin2,HIGH);
      digitalWrite(outPin3,LOW);
      digitalWrite(outPin4,HIGH);
     }
      
   }
   
 }
