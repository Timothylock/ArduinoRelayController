// pin numbers based on the connection to relay board
const int one = 4;
const int two = 11;
const int three = 10;
const int four = 9;
const int five = 8;
const int six = 7;
const int seven = 6;
const int eight = 5;

const int bootingLED = 3;
const int allonLED = 13;
const int acceptSerialLED = 12;

// Default Mode (serial / AllOn)
String defaultMode = "AllOn";

///////////////////////////
//   STOP EDITING HERE   //
///////////////////////////

String inData = "";
String input = "";
int pinNum = 0;


void setup(){ 
  // Pins Setup
  pinMode(one, OUTPUT); 
  pinMode(two, OUTPUT); 
  pinMode(three, OUTPUT); 
  pinMode(four, OUTPUT); 
  pinMode(five, OUTPUT); 
  pinMode(six, OUTPUT); 
  pinMode(seven, OUTPUT); 
  pinMode(eight, OUTPUT);
  pinMode(bootingLED, OUTPUT);
  pinMode(allonLED, OUTPUT);
  pinMode(acceptSerialLED, OUTPUT);

  // Cool Stuff
  digitalWrite(bootingLED, HIGH);
  digitalWrite(acceptSerialLED, HIGH);
  digitalWrite(allonLED, HIGH);

  // Serial Setup
  Serial.begin(9600); 

  // More cool stuff
  delay (2000); // Test Ligts
  digitalWrite(acceptSerialLED, LOW);
  digitalWrite(allonLED, LOW);
  cyclePins();
  digitalWrite(bootingLED, LOW);

  if (defaultMode.equalsIgnoreCase("serial")){
    digitalWrite(acceptSerialLED, HIGH);
    allOff();
    Serial.print("Ready to accept serial input");
  }
  else{
    allOn();
    digitalWrite(allonLED, HIGH);
    Serial.print("All on. Still accepting serial\n");
  }
} 

void loop(){ 
  // Handle reading that serial data
  if (Serial.available())  { 
    char recieved = Serial.read();
    inData += recieved; 

    // Process message when new line character is recieved
    if (recieved == '.')
    {
      input = inData;
      inData = ""; // Clear recieved buffer
    }

    if (!input.equals("")){
      if ((input.substring(0,2)).equalsIgnoreCase("on")){
        pinNum = (input.substring(input.length() - 3, input.length() - 1)).toInt();
        digitalWrite(pinNum, LOW);
        Serial.print("pin on");
      }else if ((input.substring(0,2)).equalsIgnoreCase("of")){
        pinNum = (input.substring(input.length() - 3, input.length() - 1)).toInt();
        digitalWrite(pinNum, HIGH);
        Serial.print("pin off");
      }
      input = "";
    }
  } 

  // Process a new input from serial if 


}

void cyclePins(){
  digitalWrite(one, HIGH);
  delay(100); 
  digitalWrite(two, HIGH);
  delay(100); 
  digitalWrite(three, HIGH);
  delay(100); 
  digitalWrite(four, HIGH);
  delay(100); 
  digitalWrite(five, HIGH);
  delay(100); 
  digitalWrite(six, HIGH);
  delay(100); 
  digitalWrite(seven, HIGH);
  delay(100); 
  digitalWrite(eight, HIGH);
  delay(100); 
  digitalWrite(one, LOW);
  delay(100); 
  digitalWrite(two, LOW);
  delay(100); 
  digitalWrite(three, LOW);
  delay(100); 
  digitalWrite(four, LOW);
  delay(100); 
  digitalWrite(five, LOW);
  delay(100); 
  digitalWrite(six, LOW);
  delay(100); 
  digitalWrite(seven, LOW);
  delay(100); 
  digitalWrite(eight, LOW);
  delay(1000); 
}

void allOn(){
  digitalWrite(one, LOW);
  digitalWrite(two, LOW);
  digitalWrite(three, LOW);
  digitalWrite(four, LOW);
  digitalWrite(five, LOW);
  digitalWrite(six, LOW);
  digitalWrite(seven, LOW);
  digitalWrite(eight, LOW);
}

void allOff(){
  digitalWrite(one, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(three, HIGH);
  digitalWrite(four, HIGH);
  digitalWrite(five, HIGH);
  digitalWrite(six, HIGH);
  digitalWrite(seven, HIGH);
  digitalWrite(eight, HIGH);
}

