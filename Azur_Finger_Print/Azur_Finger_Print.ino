/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/


#include <Adafruit_Fingerprint.h>

// On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// uncomment this line:
// #define mySerial Serial1

// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// comment these two lines if using hardware serial
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

 
int ID ;
int led = 13;


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
  delay(100);
  Serial.println("2,LABEL,Date,ID,Time IN,Time OUT");
  pinMode(led,OUTPUT);

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
}

 void zero ()
 {
  finger.fingerID = 0 ;
 }

void loop()                     // run over and over again
{
  getFingerprintIDez();
  delay(50);            //don't ned to run this at full speed.

 // finger.confidence >= 150

  if ( finger.fingerID == 1 && finger.confidence >= 60 ) 
  {
    
    ID = 1;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    digitalWrite(led,HIGH);
    delay(500);
    zero();
    //return finger.fingerID = 0;
    
  }

  if ( finger.fingerID == 2 && finger.confidence >= 50 ) 
  {
    ID = 2;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }
 if ( finger.fingerID == 3 && finger.confidence >= 50 ) 
  {
    ID = 3;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

  if ( finger.fingerID == 4 && finger.confidence >= 80 ) 
  {
    ID = 4;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

    if ( finger.fingerID == 5 && finger.confidence >= 70 ) 
  {
    ID = 5;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

    if ( finger.fingerID == 6 && finger.confidence >= 100 ) 
  {
    ID = 6;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

    if ( finger.fingerID == 7 && finger.confidence >= 75 ) 
  {
    ID = 7;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

    if ( finger.fingerID == 8 && finger.confidence >= 70 ) 
  {
    ID = 8;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

    if ( finger.fingerID == 9 && finger.confidence >= 70 ) 
  {
    ID = 9;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

    if ( finger.fingerID == 10 && finger.confidence >= 70 ) 
  {
    ID = 10;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

    if ( finger.fingerID == 11 && finger.confidence >= 70 ) 
  {
    ID = 11;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }

     if ( finger.fingerID == 24 && finger.confidence >= 70 ) 
  {
    ID = 24;
    Serial.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    Serial.print(ID);
    Serial.print(",");
    Serial.print("TIME");
    Serial.print(",");
    Serial.println("");
    //ID =0;
    delay(10);
    zero();
    //return finger.fingerID = 0;
    
  }
  
  else 
  {
   Serial.println("NO Finger Print ! "); 
   delay(100);
   digitalWrite(led,LOW);
  }

  
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


