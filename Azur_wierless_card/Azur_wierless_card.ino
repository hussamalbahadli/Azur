/*    Arduino Long Range Wireless Communication using HC-12
                      Example 01
   by Dejan Nedelkovski, www.HowToMechatronics.com
*/

#include <Arduino.h> // مكتبة الاردوينو الاساسية 

#include <SPI.h> // مكتبة تسمح لي بالاتصال باي جهاز يعمل على هذا البروتوكول 
#include <MFRC522.h> // مكتبة الخاصة بال rfid reader -- rc522

#define SS_PIN 10 //منفذ دخول البيانات 
#define RST_PIN 9 // منفذ خروج البيانات

MFRC522 mfrc522(SS_PIN, RST_PIN); // أنشاء الاتصال 

byte card_ID[4]; //حجم البطاقة هو 4 بايت 
byte Name1[4] = {0x44, 0x1A, 0xA3, 0x39}; //البطاقة الاولى 
byte Name2[4] = {0x72, 0x02, 0xDE, 0x24}; //البطاقة الثانية 
byte Name3[4] = {0x8D, 0x05, 0x17, 0xD3};
byte Name4[4] = {0xA4, 0x09, 0xA6, 0x39};
      

// ملاحظة يستخدم هذا في حالة دخول وخروج الطالب مرة واحدة فقط فهو اختياري 
int NumbCard[4]; //عدد البطاقات . والتي هي 2 فقط 
int statu[4]; // عدد البطاقات . والتي هي 2 ققط

int s = 0; 
int j = 0;

int const RedLed = 6; //  ضوء احمر 
int const GreenLed = 5; // ضوء احضر 
int const Buzzer = 8; // جرص 

//String Log;
long ID; //user number
#include <SoftwareSerial.h>
SoftwareSerial HC12(8, 7); // HC-12 TX Pin, HC-12 RX Pin


void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  SPI.begin();        // انشاء بروتوكول 
  mfrc522.PCD_Init(); // تعريف المكتبة 

  //Serial.println("CLEARSHEET"); // هذا الامر يمسح البيانات في كل مرة يشتغل البرنامج 
   // ملاحظة اسم الطالب في برنامج الاكسل 
  pinMode(RedLed, OUTPUT); // تهيئة المنفذ خروج 5 فولت 
  pinMode(GreenLed, OUTPUT); // تهيئة المنفذ خروج 5 فولت 
  pinMode(Buzzer, OUTPUT); // تهيئة المنفذ خروج 5 فولت 

  delay(200); // انتظار 200 ملي ثانية 
      //  HC12.println("2,LABEL,Date,ID,Time IN,Time OUT"); // انشاء جدول يحتوي على التاريخ و رقم الطالب و وقت الدخول و وقت الحروج 

}


void loop() {

  

  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return; //اذا لم تعثر على بطاقات اعد البحث 
  }
  // تحديد البطاقات
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return; //اذا ودظت بطاقة ارسلها
  }

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    card_ID[i] = mfrc522.uid.uidByte[i];

    if (card_ID[i] == Name1[i])
    {
      
      ID = 1; // رقم الطالب
      j = 0;
      s = 0;
    }
    else if (card_ID[i] == Name2[i])
    {
      ID = 2; //رقم الطالب
      j = 1;
      s = 1;
    }
    else if (card_ID[i] == Name3[i])
    {
    ID = 3; //رقم الطالب
      j = 2;
      s = 2;
    }
    else if (card_ID[i] == Name4[i])
    {
    ID = 4; //رقم الطالب
      j = 3;
      s = 3;
    }
    else
    {
      digitalWrite(GreenLed, LOW);
      digitalWrite(RedLed, HIGH);
       goto cont; //شغل ضوء احمر اذا لم تعثر على شيء 
    }
  }
  if (NumbCard[j] == 1 )
  {
    NumbCard[j] = 0; //لجعل الطالب يسجل دخول وخروج اكثر من مرة 
    HC12.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    HC12.print(ID);
    HC12.print(",");
    HC12.print("");
    HC12.print(",");
    HC12.println("TIME");
    digitalWrite(RedLed,HIGH);
    digitalWrite(GreenLed,LOW);
    digitalWrite(Buzzer,HIGH);
    delay(30);
    digitalWrite(Buzzer,LOW);
    
  }
  else if (NumbCard[j] == 0)
  {
    NumbCard[j] = 1; // لجعل الطالب يسجل دخول وخروج اكثر من مرة 
    HC12.print("DATA,DATE,"); //ارسل البيانات الى برنامج الاكسل
    HC12.print(ID);
    HC12.print(",");
    HC12.print("TIME");
    HC12.print(",");
    HC12.println("");
    digitalWrite(GreenLed, HIGH);
    digitalWrite(RedLed, LOW);
    digitalWrite(Buzzer, HIGH);
    delay(30);
    digitalWrite(Buzzer, LOW);
  }
  else if (statu[s] == 1)
  {
    //في حالة البطاقة غير معرفة 
    digitalWrite(RedLed, HIGH);
  }
  delay(1000);
cont:
  delay(2000);
  digitalWrite(GreenLed, LOW);
  digitalWrite(RedLed, LOW);

 
  
  /*while (Serial.available()) {      // If Serial monitor has data
    HC12.write(Serial.read());      // Send that data to HC-12

  }
 
  while (HC12.available()) {        // If HC-12 has data
    //Serial.write(HC12.read());      // Send the data to Serial monitor
        HC12.write(Serial.read());      // Send that data to HC-12

  }
   */
}
