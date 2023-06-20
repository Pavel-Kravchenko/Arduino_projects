int flag=0;
const int buttonPin = 2; 
const int piezoPin = 11; 
const int POMP_PIN = 10; 
const long INTERVAL_between = 60000*60;  
const long INTERVAL_watering = 5000;  

int ledPin = 13;
int buttonState = 0;  
unsigned long waitTime = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(POMP_PIN, OUTPUT);
  pinMode(ledPin, OUTPUT);  
  pinMode(buttonPin, INPUT);
  digitalWrite(POMP_PIN, HIGH); 
}

void loop(){
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
    if(buttonState==HIGH&&flag==0)
     { 
       flag=1; 
       buttonState = 0;
       digitalWrite(ledPin, HIGH);
       delay(2000);
       tone(piezoPin, 1000, 500);
       delay(2000);
     } 

    if(buttonState==HIGH&&flag==1)
     { 
       flag=0; 
       buttonState = 0;
       waitTime = 0;
       digitalWrite(ledPin, LOW);  
       delay(2000);
     } 
     
if (flag == 1){
    Serial.print("Time: ");
    Serial.println(millis(), waitTime);
      if (waitTime == 0 || millis() - waitTime > INTERVAL_between*12){
        digitalWrite(POMP_PIN, LOW);
        delay(INTERVAL_watering);
        digitalWrite(POMP_PIN, HIGH);
        waitTime = millis();
    }
  }
}
