//Connections between SIM800L <--> ESP32
#define MODEM_RST            5
#define MODEM_PWKEY          4
#define MODEM_POWER_ON       23
#define MODEM_TX             27
#define MODEM_RX             26
#define LOCKER2A  33
#define LOCKER1A  32

#define SerialAT  Serial1

String textMessage = "";
String lampState = "";
const int blueLED = 13;
bool gsm_ready;
void setup() {
  // Set modem reset, enable, power pins
  pinMode(MODEM_PWKEY, OUTPUT);
  pinMode(MODEM_RST, OUTPUT);
  pinMode(MODEM_POWER_ON, OUTPUT);
  digitalWrite(MODEM_PWKEY, LOW);
  digitalWrite(MODEM_RST, HIGH);
  digitalWrite(MODEM_POWER_ON, HIGH);

  pinMode(blueLED, OUTPUT);
  digitalWrite(blueLED, HIGH);
  
  gsm_ready = false;
  SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);
  delay(1000);
  Serial.begin(115200);               //Begin the Serial communication with PC
  delay(5000);                      //Delay to let the module to connect to network, if turned on before you can remove this
  SerialAT.println("AT");            //Send AT command it will says "OK" if everything is fine
  delay(100);
  SerialAT.print("AT+CMGF=1\r");     // Configuring TEXT mode
  delay(100);
  SerialAT.print("AT+CNMI=2,2,0,0,0\r"); // Set module to send SMS data to serial out upon receipt
  delay(100);
  SerialAT.println("AT+CMGDA=\"DEL ALL\""); //Deletes all messages stored
  delay(100);
  gsm_ready = true;
}



void loop() {

  if ((SerialAT.available() > 0) && gsm_ready == true){
    textMessage = SerialAT.readString();
    Serial.print("textMessage: ");
    Serial.println(textMessage);

    delay(10);
    if(textMessage.indexOf("Locker 2A") >= 0) {
      pinMode(LOCKER2A, OUTPUT);
      digitalWrite(LOCKER2A, LOW);
      delay(3000);
      digitalWrite(LOCKER2A, HIGH);
      Serial.println("Abriendo locker");
      Serial.println("Deleting all messages...");
      textMessage = "";
    }
  }
}

// Function that sends SMS
/*
void sendSMS(String message) {
  // AT command to set SerialAT to SMS mode
  SerialAT.print("AT+CMGF=1\r");
  delay(100);
  SerialAT.println("AT+CMGS=\"+521122223333\"");
  delay(100);
  SerialAT.print(message);
  delay(100);
  // End AT command with a ^Z, ASCII code 26
  SerialAT.println((char)26);
  delay(100);
  SerialAT.println();
  delay(5000);
}
*/