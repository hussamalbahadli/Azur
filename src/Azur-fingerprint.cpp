

#include <Arduino.h>

#include <Adafruit_Fingerprint.h>

#include <SoftwareSerial.h>

#include <SPI.h>

 

SoftwareSerial mySerial(2, 3);


SoftwareSerial HC12(9, 10); // HC-12 TX Pin, HC-12 RX Pin
 
int ID ;
int led = 8;


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  Serial.begin(9600);
  HC12.begin(9600);
  SPI.begin();
  //while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
  delay(100);
  Serial.println("2,LABEL,Date,ID,Time IN,Time OUT");
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");

  HC12.println("2,LABEL,Date,ID,Time IN,Time OUT"); 
}

 void zero ()
 {
  finger.fingerID = 0 ;
 }

 uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}

void loop()                     
{
  getFingerprintIDez();
  delay(50);            //don't ned to run this at full speed.


  if ( finger.fingerID == 1 && finger.confidence >= 60 ) 
  {
    
    ID = 1;
    HC12.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    HC12.print(ID);
    HC12.print(",");
    HC12.print("TIME");
    HC12.print(",");
    HC12.println("");
    digitalWrite(led,HIGH);
    delay(500);
    zero();
    
  }

  if ( finger.fingerID == 2 && finger.confidence >= 50 ) 
  {
    ID = 2;
    HC12.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    HC12.print(ID);
    HC12.print(",");
    HC12.print("TIME");
    HC12.print(",");
    HC12.println("");
    digitalWrite(led,HIGH);
    delay(500);
    zero();
    
    
  }

   if ( finger.fingerID == 3 && finger.confidence >= 50 ) 
  {
    ID = 3;
    HC12.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    HC12.print(ID);
    HC12.print(",");
    HC12.print("TIME");
    HC12.print(",");
    HC12.println("");
    digitalWrite(led,HIGH);
    delay(500);
    zero();
    
    
  }

  else 
  {
   Serial.println("NO Finger Print ! "); 
   delay(100);
   digitalWrite(led,LOW);
  }

  
}

