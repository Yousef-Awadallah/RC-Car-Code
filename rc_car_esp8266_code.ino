//*Nodemcu ESP8266 WIFI control car with the New Blynk app.
//*Acknowledgment: this code was modified by me (Yousef) to work for my project, but originally found on the internet
//*Project: SMARTPHONE CONTROLLED BLUETOOTH RACING CAR


// Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
//#include <SerialESP8266wifi.h>
//#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>


// Define the motor pins
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5





// Variables for the Blynk widget values
int x = 50;
int y = 50;
int Speed;
int Speaker = D6;




char auth[] = ""; //Enter your Blynk auth token
char ssid[] = ""; //Enter your WIFI name
char pass[] = ""; //Enter your WIFI passowrd


void setup() {
  Serial.begin(9600);
  //Set the motor pins as output pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(Speaker, OUTPUT);

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

// Get the joystick values
BLYNK_WRITE(V0) {
  x = param[0].asInt();
}
// Get the joystick values
BLYNK_WRITE(V1) {
  y = param[0].asInt();
}
//Get the slider values
BLYNK_WRITE(V2) {
  Speed = param.asInt();
}

// Check these values using the IF condition
void smartcar() {
  if (y > 70 && x > 70) {
  carForwardRight();
  Serial.println("carForwardRight");
  } else if (y > 70 && x < 30) {
  carForwardLeft();
  Serial.println("carForwardLeft");
  } else if (y < 30 && x > 70) {
  carBackwardRight();
  Serial.println("carBackwardRight");
  } else if (y < 30 && x < 30) {
  carBackwardLeft();
  Serial.println("carBackwardLeft");
  } else if (y > 70) {
    carForward();
    Serial.println("carForward");
  } else if (y < 30) {
    carBackward();
    Serial.println("carBackward");
  } else if (x < 30) {
    carLeft();
    Serial.println("carLeft");
  } else if (x > 70) {
    carRight();
    Serial.println("carRight");
  } else if (x < 70 && x > 30 && y < 70 && y > 30) {
    carStop();
    Serial.println("carstop");
  } 









}

void loop() {
  Blynk.run();// Run the blynk function
  smartcar();// Call the main function
}

/**************Motor movement functions*****************/
void carForwardRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
tone(Speaker, 670, 5);



  }

 void carForwardLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);


tone(Speaker, 670, 5);


 }

void carBackwardRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

tone(Speaker, 370, 5);
  
  }



void carBackwardLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
tone(Speaker, 370, 5);

  }




void carForward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);




tone(Speaker, 670, 5);

  }




void carBackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);



tone(Speaker, 370, 5);
  }




void carLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
