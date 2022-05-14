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

int digit = 0;
int number=0;

const int buttonPin1 = 13;
int buttonState1 = 0; 

const int buttonPin2 = 7;
int buttonState2 = 0;

const int buttonPin3 = 3;
int buttonState3 = 0;


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
  
  // pushbutton 
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  
  

}

void loop() 
{
  
  // trigger button 1
  buttonState1 = digitalRead(buttonPin1);
 
  if (buttonState1 == HIGH) {
    
    //display led 
    auto_display();
  } 
  
 
}


// display number in led1
void led1_brigth(int i){
  bitSet(dataArrayRED[i], 8);
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin1, MSBFIRST, dataArrayRED[i]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin1, HIGH);
  
  bitClear(dataArrayRED[i], 8);
  digitalWrite(latchPin1, HIGH);
  shiftOut(dataPin1, clockPin1, MSBFIRST, dataArrayRED[i]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin1, LOW);
}

// display number in led2
void led2_brigth(int i){
  bitSet(dataArrayRED[i], 8);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, dataArrayRED[i]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin2, HIGH);
  
  bitClear(dataArrayRED[i], 8);
  digitalWrite(latchPin2, HIGH);
  shiftOut(dataPin2, clockPin2, MSBFIRST, dataArrayRED[i]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin2, LOW);

}

//display left and right led from input "i"
void display_number(int i){
  
  // divide i by 10 to recieve tens digits
  led1_brigth(i/10);
  // mod i by 10 to recieve ones digits
  led2_brigth(i%10);
  delay(400);

  
}

void auto_display(){
for(int i=0; i<100; i++){      
    display_number(i);
  
    // trigger button 2 to reset led number to 0 value
    buttonState2 = digitalRead(buttonPin2);

    if (buttonState2 == HIGH) {   
      i = 0;  
  } 
  
  
  }   

}
