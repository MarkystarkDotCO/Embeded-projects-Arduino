// register 1
int latchPin1 = 11;      
int clockPin1 = 9;      
int dataPin1 = 12;     

// register 2
int latchPin2 = 5;      
int clockPin2 = 4;    
int dataPin2 = 6;    

byte dataRED;
byte dataArrayRED[10];

void setup() 
{
 
  // register 1 settingup
  pinMode(latchPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);  
  pinMode(clockPin1, OUTPUT);
  
  // register 2 settingup
  
  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);  
  pinMode(clockPin2, OUTPUT);
  
  //Bit to display led number
dataArrayRED[0] = 0x3F; 
dataArrayRED[1] = 0x06; 
dataArrayRED[2] = 0xDB; 
dataArrayRED[3] = 0x4F; 
dataArrayRED[4] = 0x66; 
dataArrayRED[5] = 0x6D; 
dataArrayRED[6] = 0x7D; 
dataArrayRED[7] = 0x07; 
dataArrayRED[8] = 0xFF; 
dataArrayRED[9] = 0x6F; 
  
  //
  Serial.begin(9600);
 
}

void loop() 
{
  float a;
  a = analogRead(A0);
  display_LED((a*99) / 1023);
}

void led_brigth(int number, int dataPin, int latchPin, int clockPin){
  bitSet(dataArrayRED[number], 8);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, dataArrayRED[number]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin, HIGH);
  
  bitClear(dataArrayRED[number], 8);
  digitalWrite(latchPin, HIGH);
  shiftOut(dataPin, clockPin, MSBFIRST, dataArrayRED[number]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin, LOW);

}
void display_LED(int i){
  
  if(i>=0){
  // divide i by 10 to recieve tens digits
  led_brigth(i/10, dataPin1, latchPin1, clockPin1 );
  // mod i by 10 to recieve ones digits
  led_brigth(i%10, dataPin2, latchPin2, clockPin2);
  }

}
